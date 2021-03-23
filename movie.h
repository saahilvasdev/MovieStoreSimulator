/**
 * movie.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the movie.h is to
 * declare all methods that its sub classes will override.
 * There is also movieFactory class declared in the same file.
 **/
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

using namespace std;

class Movie {
  friend ostream &operator<<(ostream &os, const Movie &m) {
    return m.printer(os);
  }

public:
  virtual Movie *create() = 0;
  virtual bool read(istream &is) = 0;
  virtual ostream &printer(ostream &os) const = 0;
  virtual ~Movie() = default;
  virtual bool genreSort(Movie *movie) const = 0;
  virtual bool sameKeys(pair<string, string> sortingAttributes) = 0;
  virtual void decrementStock() = 0;
  virtual void incrementStock() = 0;

  Movie() = default;
  Movie(Movie &&other) = delete;
  Movie(const Movie &other) = delete;
  Movie &operator=(const Movie &other) = delete;
  Movie &operator=(Movie &&other) = delete;

  // a non-virtual helper method to determine if a movie has stock
  bool inStock();

protected:
  char denotationMovie = ' ';
  string director = "";
  string title = "";
  int stock = 0;
  int currentlyBorrow = 0;

  // a non-virtual helper method to read in the next item in a txt file
  string readNextItem(istream &io);
};

class MovieFactory {

public:
  // default MovieFactory constructor
  MovieFactory();

  // deconstructor for MovieFactory
  ~MovieFactory();

  // create method for MovieFactory that checks if a movie
  // exist in its catalog, and than uses that specific
  // movie's create() method
  Movie *create(char movieType);

  MovieFactory(MovieFactory &&other) = delete;
  MovieFactory(const MovieFactory &other) = delete;
  MovieFactory &operator=(const MovieFactory &other) = delete;
  MovieFactory &operator=(MovieFactory &&other) = delete;

private:
  static const int FACTORY_SIZE = 'Z' - 'A' + 1;
  Movie *movies[FACTORY_SIZE]{};

  // a private MovieFactory method that is a hashtable algorithm.
  int getIndex(char movieType);
};

#endif