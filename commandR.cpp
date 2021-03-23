/**
 * commandR.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandR.cpp is to
 * implement all of commandR.h declared methods
 **/

#include <iostream>
#include <string>

#include "commandR.h"
#include "movieStore.h"

using namespace std;

// creates a new commandR object
Command *CommandR::create() { return new CommandR(); }

// prints out the infomation that commandR object stores
ostream &CommandR::printer(ostream &os) const {
  os << "Action R, Customer Id: " << customerId << " Media Type: " << mediaType
     << " Movie Type: " << movieType
     << " Sorting Attributes: " << sortingAttribute.first << " "
     << sortingAttribute.second;
  return os;
}

// reads in infomation for commandB to populate its
// private data member with
// Note: Hardcoded what movie type there is because
// syntax for each movie's sorting attrivutes is different
bool CommandR::read(istream &is) {
  string temp1, temp2;
  is >> customerId >> mediaType >> movieType;
  if (movieType == 'F') {
    sortingAttribute.first = readNextItem(is);
    is >> sortingAttribute.second;
  } else if (movieType == 'D') {
    sortingAttribute.first = readNextItem(is);
    sortingAttribute.second = readNextItem(is);
  } else if (movieType == 'C') {
    is >> temp1 >> temp2;
    temp1 = temp1 + " " + temp2;
    sortingAttribute.first = temp1;
    is >> temp1 >> temp2;
    temp1 = temp1 + " " + temp2;
    sortingAttribute.second = temp1;
  } else {
    cerr << "Discarding line: " << discardLine(is) << endl;
    return false;
  }
  return true;
}

// execute command for commandr which is returning
// a movie
void CommandR::execute(MovieStore &ms) {
  // get customer object
  Customer *targetCustomer = ms.getCustomer(customerId);
  // get movie object
  Movie *targetMovie = ms.getMovie(movieType, sortingAttribute);
  if (targetCustomer == nullptr) {
    cerr << "Invalid customer ID: " << customerId << endl;
    return;
  }
  if (targetMovie == nullptr) {
    cerr << "Invalid movie sorting Attribute: " << sortingAttribute.first << " "
         << sortingAttribute.second << endl;
    return;
  }
  // checks if customer has the movie borrowed
  if (targetCustomer->removeBorrow(sortingAttribute)) {
    targetMovie->incrementStock();
    targetCustomer->addTransaction(this);
  } else {
    cerr << "Customer ID: " << customerId
         << " does not have the movie borrow, can't return" << endl;
  }
}