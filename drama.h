/**
 * drama.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the drama.h file is to provide a template for
 * the implementation (.cpp). All functions and variables are declared in this
 * file and were used throughout the implementation.
 **/

#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <iostream>
#include <string>

using namespace std;

class Drama : public Movie {

public:
  // creates a new Classic movie
  Movie *create() override;

  // Syntax: D, Stock, Director, Title, Year it released
  bool read(istream &is) override;

  // prints out the information about the drama movie
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
  int yearReleased = 0;
};

#endif