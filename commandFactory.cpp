/**
 * commandFactory.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: March 16th, 2021
 *
 * Description: The purpose of the commandFactory.cpp is creating command
 * objects for borrow, history, inventory, and return.
 **/

#include <iostream>
#include <string>

#include "command.h"
#include "commandB.h"
#include "commandH.h"
#include "commandI.h"
#include "commandR.h"

using namespace std;

// default constructor
CommandFactory::CommandFactory() {
  for (auto &c : commands) {
    c = nullptr;
  }
  commands[getIndex('B')] = new CommandB();
  commands[getIndex('H')] = new CommandH();
  commands[getIndex('I')] = new CommandI();
  commands[getIndex('R')] = new CommandR();
}

// deconstructor
CommandFactory::~CommandFactory() {
  for (auto &c : commands) {
    delete c;
  }
}

// create a Movie based on the commandType
Command *CommandFactory::create(char commandType) {
  if (commands[getIndex(commandType)] != nullptr) {
    return commands[getIndex(commandType)]->create();
  }
  return nullptr;
}

// getter method for the index
int CommandFactory::getIndex(char commandType) {
  if (commandType >= 'A' && commandType <= 'Z') { // precheck
    return commandType - 'A';
  }
  cout << "Given commandType is not valid: " << commandType << endl;
  return -1;
}