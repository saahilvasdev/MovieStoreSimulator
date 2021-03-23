/**
 * customer.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the customer.h file is to provide a template for
 * the implementation (.cpp). All functions and variables are declared in this
 * file and were used throughout the implementation.
 **/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>

#include "command.h"
#include "movie.h"

using namespace std;

class Command;

class Customer {

public:
  // constructor for creating a new customer
  Customer(int newCustomerId, string newLastName, string newFirstName);

  // deconstructor
  ~Customer() = default;

  // default constructor
  Customer() = default;

  Customer(Customer &&other) = delete;
  Customer(const Customer &other) = delete;
  Customer &operator=(const Customer &other) = delete;
  Customer &operator=(Customer &&other) = delete;

  // adds a transaction
  void addTransaction(Command *transaction);

  // adds a borrow
  void addBorrow(Movie *borrowingMovie);

  // removes a borrow
  bool removeBorrow(const pair<string, string> &sortingAttributes);

  // prints out the customer ID and first & last name
  void printInfo();

  // getter method for getting the ID of a customer
  int getID();

  // prints out the transaction histroy for a customer
  void printTransactionHistory();

private:
  int customerId = 0;
  string lastName = "";
  string firstName = "";
  vector<Movie *> currentlyBorrowed;    // vector containing all the borrowed
                                        // movies
  vector<Command *> transactionHistory; // vector containing transactions
};

#endif