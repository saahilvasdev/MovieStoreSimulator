/**
 * command.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the command.h file is to provide a template for
 * the implementation (.cpp). All functions and variables are declared in this
 * file and were used throughout the implementation.
 **/

#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <string>

#include "movieStore.h"

using namespace std;

class MovieStore;

class Command {
  friend ostream &operator<<(ostream &os, const Command &c) {
    return c.printer(os);
  }

public:
  virtual Command *create() = 0;
  virtual ostream &printer(ostream &os) const = 0;
  virtual bool read(istream &is) = 0;
  virtual void execute(MovieStore &ms) = 0;
  virtual ~Command() = default;

  Command() = default;
  Command(Command &&other) = delete;
  Command(const Command &other) = delete;
  Command &operator=(const Command &other) = delete;
  Command &operator=(Command &&other) = delete;

protected:
  // reads in the next item in the line
  string readNextItem(istream &io);

  // read to end of line
  const string discardLine(istream &is);
};

#endif