/**
 * comedy.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: MArch 16th, 2021
 *
 * Description: The purpose of the comedy.cpp is to create,
 * read, and print out Comedy movies.
 **/

#include <iostream>
#include <string>

#include "comedy.h"

using namespace std;

// creates a new Comedy movie
Movie *Comedy::create() { return new Comedy(); }

// Syntax: F, Stock, Director, Title, Year it released
bool Comedy::read(istream &is) {
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

// prints out the information about the comedy movie
// Syntax: Comedy: Title, Director, Year Released, Current Stock, Currently
// Borrowed
ostream &Comedy::printer(ostream &os) const {
  os << "Comedy: "
     << "Title: " << title << ", Director: " << director
     << ", Year Released: " << yearReleased << ", Current Stock: " << stock
     << ", Currently Borrow: " << currentlyBorrow;
  return os;
}

// returns the bigger year released
bool Comedy::genreSort(Movie *other) const {
  auto *otherComedy = dynamic_cast<Comedy *>(other);

  if (title == otherComedy->title) {
    return yearReleased > otherComedy->yearReleased;
  }
  return title < otherComedy->title;
}

// compares if the keys in the pair are the same
bool Comedy::sameKeys(pair<string, string> sortingAttributes) {
  pair<string, string> thisSortingAttributes;
  thisSortingAttributes.first = title;
  thisSortingAttributes.second = to_string(yearReleased);
  return (sortingAttributes.first == thisSortingAttributes.first &&
          sortingAttributes.second == thisSortingAttributes.second);
}

// decrements current stock by 1 and increments
// the number of borrowed by 1
void Comedy::decrementStock() {
  stock = stock - 1;
  currentlyBorrow = currentlyBorrow + 1;
}

// increments current stock by 1 and decrements
// the number of borrowed by 1
void Comedy::incrementStock() {
  stock = stock + 1;
  currentlyBorrow = currentlyBorrow - 1;
}