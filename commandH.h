/**
 * commandH.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandH.h is to
 * declare all of commandH's method that needs to be
 * override from parent class.
 **/

#ifndef COMMANDH_H
#define COMMANDH_H
#include "command.h"
#include "movieStore.h"
#include <iostream>
#include <string>
using namespace std;

class CommandH : public Command {

public:
  // creates a new commandH object
  Command *create() override;

  // prints out the customerId that the commandH is
  // looking at
  ostream &printer(ostream &os) const override;

  // reads in infomation for commandH to populate its
  // private data member with
  bool read(istream &is) override;

  // execute command for commandH which is showing the
  // history of a certain customer
  void execute(MovieStore &ms) override;

private:
  int customerId = 0;
};

#endif