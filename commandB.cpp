/**
 * commandB.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandB.cpp is to
 * implement all of commandB.h declared methods
 **/
#include <iostream>
#include <string>

#include "commandB.h"
#include "movieStore.h"

using namespace std;

// creates a new commandB object
Command *CommandB::create() { return new CommandB(); }

// prints out the infomation that commandB object stores
ostream &CommandB::printer(ostream &os) const {
  os << "Action B, Customer Id: " << customerId << " Media Type: " << mediaType
     << " Movie Type: " << movieType
     << " Sorting Attributes: " << sortingAttribute.first << " "
     << sortingAttribute.second;
  return os;
}

// reads in infomation for commandB to populate its
// private data member with
// Note: Hardcoded what movie type there is because
// syntax for each movie's sorting attrivutes is different
bool CommandB::read(istream &is) {
  string temp1, temp2;
  is >> customerId >> mediaType >> movieType;
  if (mediaType != 'D') {
    cerr << "Invalid Media Type: " << mediaType << endl;
    cerr << "Discarding line: " << discardLine(is) << endl;
    return false;
  }
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

// execute command for commandB which is borrowing
// a movie
void CommandB::execute(MovieStore &ms) {
  // Get customer and specific movie
  Customer *targetCustomer = ms.getCustomer(customerId);
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
  // both customer and movie exist
  if (!targetMovie->inStock()) {
    cerr << "Cannot borrow a movie that is out of stock" << endl;
  } else {
    targetMovie->decrementStock();
    targetCustomer->addBorrow(targetMovie);
    targetCustomer->addTransaction(this);
  }
}