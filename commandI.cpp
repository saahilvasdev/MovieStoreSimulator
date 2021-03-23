/**
 * commandI.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandI.cpp is to
 * implement all of commandI.h declared methods
 **/

#include <iostream>
#include <string>

#include "commandI.h"
#include "movieStore.h"

using namespace std;

// creates a new commandI object
Command *CommandI::create() { return new CommandI(); }

// prints out the infomation that commandI object stores
ostream &CommandI::printer(ostream &os) const {
  os << "Action I: Printing Inventory ";
  return os;
}

// reads in the infomation for commandI to populate its
// private data member
// Note: commandI does not have any private variable so
// method only returns true
// Note 2: variable "is" is not used as nothing to read
bool CommandI::read(istream &is) { return true; }

// execute command for commandI which is inventory
void CommandI::execute(MovieStore &ms) {
  for (auto &m : ms.genresOfMovies) {
    int size = m.second.size();
    for (int i = 0; i < size; i++) {
      Movie *temp = m.second[i];
      cout << *temp << endl;
    }
  }
}
