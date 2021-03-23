/**
 * commandR.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandR.h is to
 * declare all of commandR's method that needs to be
 * override from parent class.
 **/

#ifndef COMMANDR_H
#define COMMANDR_H
#include "command.h"
#include "movieStore.h"
#include <iostream>
#include <string>
using namespace std;

class CommandR : public Command {

public:
  // creates a new commandR object
  Command *create() override;

  // prints out the infomation that commandR object stores
  ostream &printer(ostream &os) const override;

  // reads in infomation for commandB to populate its
  // private data member with
  bool read(istream &is) override;

  // execute command for commandr which is returning
  // a movie
  void execute(MovieStore &ms) override;

private:
  int customerId = 0;
  char mediaType = ' ', movieType = ' ';
  pair<string, string> sortingAttribute;
};

#endif