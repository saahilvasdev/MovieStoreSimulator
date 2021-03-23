/**
 * comedy.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the comedy.h file is to provide a template for
 * the implementation (.cpp). All functions and variables are declared in this
 * file and were used throughout the implementation.
 **/

#ifndef COMEDY_H
#define COMEDY_H
#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

class Comedy : public Movie {

public:
  // creates a new Comedy movie
  Movie *create() override;

  // Syntax: F, Stock, Director, Title, Year it released
  bool read(istream &is) override;

  // prints out the information about the comedy movie
  // Syntax: Comedy: Title, Director, Year Released, Current Stock, Currently
  // Borrowed
  ostream &printer(ostream &os) const override;

  // returns the bigger year released
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
  int yearReleased = 0;
};

#endif