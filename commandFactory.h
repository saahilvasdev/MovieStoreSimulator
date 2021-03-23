/**
 * commandFactory.h
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandFactory.h file is to provide a
 *template for the implementation (.cpp). All functions and variables are
 *declared in this file and were used throughout the implementation.
 **/

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <iostream>
#include <string>

#include "command.h"

using namespace std;

class Command;

class CommandFactory {
public:
  // default constructor
  CommandFactory();

  // deconstructor
  ~CommandFactory();

  // create a Movie based on the commandType
  Command *create(char commandType);

  CommandFactory(CommandFactory &&other) = delete;
  CommandFactory(const CommandFactory &other) = delete;
  CommandFactory &operator=(const CommandFactory &other) = delete;
  CommandFactory &operator=(CommandFactory &&other) = delete;

private:
  static const int FACTORY_SIZE = 'Z' - 'A' + 1; // factory size
  Command *commands[FACTORY_SIZE]{};
  int getIndex(char commandType); // getter method for the index
};

#endif