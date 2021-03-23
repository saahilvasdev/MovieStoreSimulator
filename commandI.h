/**
 * commandI.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandI.h is to
 * declare all of commandI's method that needs to be
 * override from parent class.
 **/
#ifndef COMMANDI_H
#define COMMANDI_H
#include "command.h"
#include "movieStore.h"
#include <iostream>
#include <string>
using namespace std;

class CommandI : public Command {

public:
  // creates a new commandI object
  Command *create() override;

  // prints out the infomation that commandI object stores
  ostream &printer(ostream &os) const override;

  // reads in the infomation for commandI to populate its
  // private data member
  bool read(istream &is) override;

  // execute command for commandI which is inventory
  void execute(MovieStore &ms) override;

private:
};

#endif