/**
 * commandB.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandB.h is to
 * declare all of commandB's method that needs to be
 * override from parent class.
 **/
#ifndef COMMANDB_H
#define COMMANDB_H
#include "command.h"
#include "movieStore.h"
#include <iostream>
#include <string>

using namespace std;

class CommandB : public Command {

public:
  // creates a new commandB object
  Command *create() override;

  // prints out the infomation that commandB object stores
  ostream &printer(ostream &os) const override;

  // reads in infomation for commandB to populate its
  // private data member with
  bool read(istream &is) override;

  // execute command for commandB which is borrowing
  // a movie
  void execute(MovieStore &ms) override;

private:
  int customerId = 0;
  char mediaType = ' ', movieType = ' ';
  pair<string, string> sortingAttribute;
};

#endif