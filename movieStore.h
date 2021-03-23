/**
 * movieStore.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the movieStore.h is to
 * declare all of movieStore's method.
 **/

#ifndef MOVIESTORE_H
#define MOVIESTORE_H
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "command.h"
#include "commandFactory.h"
#include "customer.h"
#include "movie.h"

using namespace std;

class Command;
class Customer;

class MovieStore {

  friend class CommandI;
  friend class CommandB;
  friend class CommandR;
  friend class CommandH;

public:
  // default constructor for MovieStore
  MovieStore();

  // deconstructor for MovieStore
  ~MovieStore();
  MovieStore(MovieStore &&other) = delete;
  MovieStore(const MovieStore &other) = delete;
  MovieStore &operator=(const MovieStore &other) = delete;
  MovieStore &operator=(MovieStore &&other) = delete;

  // a method to read a txt file that contain movie infomations
  void readMoviesFromFile(const string &filename);

  // a method to read a txt file that contain customer infomations
  void readCustomersFromFile(const string &filename);

  // a method to read a txt file that contain command infomations
  void readCommandsFromFile(const string &filename);

  // a lamda function that sorts movies using each sub genre's genreSort()
  // method
  void sortByMovieDefaultKey(vector<Movie *> &movies);

  // a helper method that returns a customer object with the targetCustomerID
  Customer *getCustomer(int targetCustomerID);

  // a helper method that returns a movie object with the specified
  // sortingAttributes

  Movie *getMovie(char movieType,
                  const pair<string, string> &sortingAttributes);

private:
  MovieFactory movieFactory;
  CommandFactory *commandFactory = new CommandFactory();
  map<char, vector<Movie *>, greater<char>> genresOfMovies;
  vector<Customer *> listOfCustomers;
  vector<Command *> listOfCommands;
};

#endif