/**
 * customer.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the customer.cpp is to deal with
 * transactions such as borrowing and returning movies. Along with
 * that, the transaction history is printed.
 **/

#include <iostream>
#include <string>

using namespace std;

#include "customer.h"

// constructor for creating a new customer
Customer::Customer(int newCustomerId, string newLastName, string newFirstName) {
  customerId = newCustomerId;
  lastName = move(newLastName);
  firstName = move(newFirstName);
}

// prints out the customer ID and first & last name
void Customer::printInfo() {
  cout << "Customer ID: " << customerId << endl;
  cout << "Name: " << firstName << " " << lastName << endl;
}

// adds a transaction
void Customer::addTransaction(Command *transaction) {
  transactionHistory.push_back(transaction);
}

// adds a borrow
void Customer::addBorrow(Movie *borrowingMovie) {
  currentlyBorrowed.push_back(borrowingMovie);
}

// removes a borrow
bool Customer::removeBorrow(const pair<string, string> &sortingAttributes) {
  auto it = currentlyBorrowed.begin();
  while (it != currentlyBorrowed.end()) {
    if ((*it)->sameKeys(sortingAttributes)) {
      it = currentlyBorrowed.erase(it);
      return true;
    }
  }
  return false;
}

// getter method for getting the ID of a customer
int Customer::getID() { return customerId; }

// prints out the transaction histroy for a customer
void Customer::printTransactionHistory() {
  for (auto &c : transactionHistory) {
    cout << *c << endl;
  }
}