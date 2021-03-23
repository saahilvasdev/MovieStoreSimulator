/**
 * commandH.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandB.cpp is to
 * implement all of commandH.h declared methods
 **/

#include <iostream>
#include <string>

#include "commandH.h"
#include "customer.h"
#include "movieStore.h"

using namespace std;

// creates a new commandH object
Command *CommandH::create() { return new CommandH(); }

// prints out the customerId that the commandH is
// looking at
ostream &CommandH::printer(ostream &os) const {
  os << "Action H, CustomerId: " << customerId;
  return os;
}

// reads in infomation for commandH to populate its
// private data member with
bool CommandH::read(istream &is) {
  is >> customerId;
  return true;
}

// execute command for commandH which is showing the
// history of a certain customer
void CommandH::execute(MovieStore &ms) {
  Customer *targetCustomer = ms.getCustomer(customerId);
  if (targetCustomer != nullptr) {
    cout << "Customer ID: " << customerId << " transactions:" << endl;
    targetCustomer->printTransactionHistory();
  } else {
    cerr << "Customer ID: " << customerId << " does not exist" << endl;
  }
}