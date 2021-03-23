/**
 * classic.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: MArch 16th, 2021
 *
 * Description: The purpose of the classics.cpp is to create,
 * read, and print out Classic movies.
 **/

#include <iostream>
#include <string>

#include "classics.h"

using namespace std;

// creates a new Classic movie
Movie *Classics::create() { return new Classics(); }

// Syntax: C, Stock, Director, Title, Major actor Release Date
bool Classics::read(istream &is) {
  char discardComma; // reading in the comma
  int tempStock;
  is >> tempStock;
  stock = tempStock;
  is >> discardComma;
  director = readNextItem(is);
  title = readNextItem(is);
  is >> majorActorFirstName >> majorActorLastName;
  is >> releaseDateMonth >> releaseDateYear;
  return true;
}

// prints out the information about the classic movie
// Syntax: Classic: Title, Director, Major Actor, Release Date, Current Stock,
// Currently Borrowed
ostream &Classics::printer(ostream &os) const {
  os << "Classic: "
     << "Title: " << title << ", Director: " << director
     << ", Major Actor: " << majorActorFirstName << " " << majorActorLastName
     << ", Release Date: " << releaseDateMonth << " " << releaseDateYear
     << ", Current Stock: " << stock
     << ", Currently Borrow: " << currentlyBorrow;
  return os;
}

// returns the bigger release date
bool Classics::genreSort(Movie *other) const {
  auto *otherClassic = dynamic_cast<Classics *>(other);

  // if release date is same
  if (releaseDateMonth == otherClassic->releaseDateMonth &&
      releaseDateYear == otherClassic->releaseDateYear) {
    // major actor has same first name
    if (majorActorFirstName == otherClassic->majorActorFirstName) {
      return majorActorLastName < otherClassic->majorActorLastName;
    }
    return majorActorFirstName < otherClassic->majorActorFirstName;
  }

  // same releaseYear, compare releaseMonth
  if (releaseDateYear == otherClassic->releaseDateYear) {
    return releaseDateMonth > otherClassic->releaseDateMonth;
  }
  return releaseDateYear > otherClassic->releaseDateYear;
}

// compares if the keys in the pair are the same
bool Classics::sameKeys(pair<string, string> sortingAttributes) {
  pair<string, string> thisSortingAttributes;
  thisSortingAttributes.first =
      to_string(releaseDateMonth) + " " + to_string(releaseDateYear);
  thisSortingAttributes.second = majorActorFirstName + " " + majorActorLastName;
  return (sortingAttributes.first == thisSortingAttributes.first &&
          sortingAttributes.second == thisSortingAttributes.second);
}

// decrements current stock by 1 and increments
// the number of borrowed by 1
void Classics::decrementStock() {
  stock = stock - 1;
  currentlyBorrow = currentlyBorrow + 1;
}

// increments current stock by 1 and decrements
// the number of borrowed by 1
void Classics::incrementStock() {
  stock = stock + 1;
  currentlyBorrow = currentlyBorrow - 1;
}
