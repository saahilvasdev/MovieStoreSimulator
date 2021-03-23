/**
 * classics.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the edge.h file is to provide a template for
 * the implementation (.cpp). All functions and variables are declared in this
 * file and were used throughout the implementation.
 **/

#ifndef CLASSICS_H
#define CLASSICS_H
#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

class Classics : public Movie {

public:
  // creates a new Classic movie
  Movie *create() override;

  // Syntax: C, Stock, Director, Title, Major actor Release Date
  bool read(istream &is) override;

  // prints out the information about the classic movie
  // Syntax: Classic: Title, Director, Major Actor, Release Date, Current Stock,
  // Currently Borrowed
  ostream &printer(ostream &os) const override;

  // returns the bigger release date
  bool genreSort(Movie *other) const override;

  // compares if the keys in the pair are the same
  bool sameKeys(pair<string, string> sortingAttributes) override;

  // decrements current stock by 1 and increments
  // the number of borrowed by 1
  void decrementStock() override;

  // increments current stock by 1 and decrements
  // the number of borrowed by 1
  void incrementStock() override;

protected:
  int releaseDateMonth = 0;
  int releaseDateYear = 0;
  string majorActorFirstName = "";
  string majorActorLastName = "";
};

#endif