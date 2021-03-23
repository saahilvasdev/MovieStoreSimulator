/**
 * movie.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the movie.cpp is to
 * implement all of movie.cpp non-virtual methods and
 * to implement MovieFactory methods.
 **/
#include <iostream>
#include <string>

#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "movie.h"

using namespace std;

// a non-virtual helper method to read in the next item in a txt file
string Movie::readNextItem(istream &io) {
  char delimiter = ',';
  const char space = ' ';
  string str;
  getline(io, str, delimiter);
  if (str.empty()) {
    return str;
  }
  return str.substr(str.find_first_not_of(space),
                    str.find_last_not_of(space) + 1);
}

// a non-virtual helper method to determine if a movie has stock
bool Movie::inStock() { return (stock != 0); }

// default MovieFactory constructor
MovieFactory::MovieFactory() {
  for (auto &m : movies) {
    m = nullptr;
  }
  movies[getIndex('C')] = new Classics();
  movies[getIndex('D')] = new Drama();
  movies[getIndex('F')] = new Comedy();
}

// deconstructor for MovieFactory
MovieFactory::~MovieFactory() {
  for (auto &m : movies) {
    delete m;
  }
}

// create method for MovieFactory that checks if a movie
// exist in its catalog, and than uses that specific
// movie's create() method
Movie *MovieFactory::create(char movieType) {
  if (movies[getIndex(movieType)] != nullptr) {
    return movies[getIndex(movieType)]->create();
  }
  return nullptr;
}

// a private MovieFactory method that is a hashtable algorithm.
int MovieFactory::getIndex(char movieType) {
  if (movieType >= 'A' && movieType <= 'Z') {
    return movieType - 'A';
  }
  cout << "Given movieType is not valid: " << movieType << endl;
  return -1;
}