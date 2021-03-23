/**
 * drama.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the drama.cpp is to create,
 * read, and print out Drama movies.
 **/

#include <iostream>
#include <string>

#include "drama.h"

using namespace std;

// creates a new Classic movie
Movie *Drama::create() { return new Drama(); }

// Syntax: D, Stock, Director, Title, Year it released
bool Drama::read(istream &is) {
  char discardComma;
  int tempStock;
  is >> tempStock;
  stock = tempStock;
  is >> discardComma;
  director = readNextItem(is);
  title = readNextItem(is);
  is >> yearReleased;
  return true;
}

// prints out the information about the drama movie
// Syntax: Classic: Title, Director, Major Actor, Release Date, Current Stock,
// Currently Borrowed
ostream &Drama::printer(ostream &os) const {
  os << "Drama: "
     << "Title: " << title << ", Director: " << director
     << ", Year Released: " << yearReleased << ", Current Stock: " << stock
     << ", Currently Borrow: " << currentlyBorrow;
  return os;
}

// returns the bigger release date
bool Drama::genreSort(Movie *other) const {
  auto *otherDrama = dynamic_cast<Drama *>(other);

  if (director == otherDrama->director) {
    return title < otherDrama->title;
  }
  return director < otherDrama->director;
}

// compares if the keys in the pair are the same
bool Drama::sameKeys(pair<string, string> sortingAttributes) {
  pair<string, string> thisSortingAttributes;
  thisSortingAttributes.first = director;
  thisSortingAttributes.second = title;
  return (sortingAttributes.first == thisSortingAttributes.first &&
          sortingAttributes.second == thisSortingAttributes.second);
}

// decrements current stock by 1 and increments
// the number of borrowed by 1
void Drama::decrementStock() {
  stock = stock - 1;
  currentlyBorrow = currentlyBorrow + 1;
}

// increments current stock by 1 and decrements
// the number of borrowed by 1
void Drama::incrementStock() {
  stock = stock + 1;
  currentlyBorrow = currentlyBorrow - 1;
}