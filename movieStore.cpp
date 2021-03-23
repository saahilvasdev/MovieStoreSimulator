/**
 * movieStore.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the movieStore.cpp is to
 * implement all of movieStore.h declared methods
 **/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "command.h"
#include "commandFactory.h"
#include "customer.h"
#include "movieStore.h"

// a method to discard an entire line in a txt file
const string discardLine(istream &is) {
  string discard;
  getline(is, discard);
  return discard;
}

// default constructor for MovieStore
MovieStore::MovieStore() {
  vector<Movie *> classicsMovies;
  vector<Movie *> dramaMovies;
  vector<Movie *> comedyMovies;

  genresOfMovies['C'] = classicsMovies;
  genresOfMovies['D'] = dramaMovies;
  genresOfMovies['F'] = comedyMovies;
}

// deconstructor for MovieStore
MovieStore::~MovieStore() {
  // deletes everything in genresOfMovies
  for (auto &v : genresOfMovies) {
    for (auto &m : v.second) {
      delete m;
    }
  }
  // deletes everything in listOfCustomers
  for (auto &c : listOfCustomers) {
    delete c;
  }
  // deletes everything in listOfCommands
  for (auto &cd : listOfCommands) {
    delete cd;
  }
  // Delete the commandFactory
  delete commandFactory;
}

// a method to read a txt file that contain movie infomations
void MovieStore::readMoviesFromFile(const string &filename) {
  ifstream fs(filename);
  if (!fs.is_open()) {
    cerr << "File could not be open: " << filename << endl;
  }
  char movieType;
  char removeComma;
  while (fs >> movieType) {
    fs >> removeComma;
    Movie *tempMovie = movieFactory.create(movieType);
    if (tempMovie != nullptr) {
      if (tempMovie->read(fs)) {
        genresOfMovies[movieType].push_back(tempMovie);
        // sort the specfic vector
        sortByMovieDefaultKey(genresOfMovies[movieType]);
      } else {
        delete tempMovie;
      }
    } else {
      cerr << "Unrecognized movie type: " << movieType << endl;
      cerr << "Discarding line: " << discardLine(fs) << endl;
    }
  }
}

// a method to read a txt file that contain customer infomations
void MovieStore::readCustomersFromFile(const string &filename) {
  ifstream fs(filename);
  if (!fs.is_open()) {
    cerr << "File could not be open: " << filename << endl;
  }
  int customerId;
  string customerLastName;
  string customerFirstName;
  while (fs >> customerId) {
    fs >> customerLastName >> customerFirstName;
    Customer *tempCustomer =
        new Customer(customerId, customerLastName, customerFirstName);
    listOfCustomers.push_back(tempCustomer);
  }
}

// a method to read a txt file that contain command infomations
void MovieStore::readCommandsFromFile(const string &filename) {
  ifstream fs(filename);
  if (!fs.is_open()) {
    cerr << "File could not be open: " << filename << endl;
  }
  char commandType;
  while (fs >> commandType) {
    Command *tempCommand = commandFactory->create(commandType);
    if (tempCommand != nullptr) {
      if (tempCommand->read(fs)) {
        listOfCommands.push_back(tempCommand);
        // execute the command
        tempCommand->execute(*this);
      } else {
        delete tempCommand;
      }
    } else {
      cerr << "Unrecognized command type: " << commandType << endl;
      cerr << "Discarding line: " << discardLine(fs) << endl;
    }
  }
}

// a helper method that returns a customer object with the targetCustomerID
Customer *MovieStore::getCustomer(int targetCustomerID) {
  for (auto &c : listOfCustomers) {
    if (c->getID() == targetCustomerID) {
      return c;
    }
  }
  return nullptr;
}

// a helper method that returns a movie object with the specified
// sortingAttributes
Movie *MovieStore::getMovie(char movieType,
                            const pair<string, string> &sortingAttributes) {
  // checks if movieType exist in map
  if (genresOfMovies.count(movieType) != 0u) {
    for (auto &m : genresOfMovies[movieType]) {
      if (m->sameKeys(sortingAttributes)) {
        return m;
      }
    }
    return nullptr;
  }
  return nullptr;
}

// a lambda function that sorts movies using each sub genre's genreSort() method
void MovieStore::sortByMovieDefaultKey(vector<Movie *> &movies) {
  sort(movies.begin(), movies.end(),
       [](Movie *a, Movie *b) { return a->genreSort(b); });
}
