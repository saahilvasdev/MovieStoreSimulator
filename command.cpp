/**
 * command.cpp
 * Name: Tommy Ni & Saahil Vasdev
 * Date of creation: March 8th, 2021
 * Date of last modification: MArch 16th, 2021
 *
 * Description: The purpose of the command.cpp is to
 * read in the command from the text file
 **/

#include <iostream>
#include <string>

#include "command.h"
#include "commandB.h"
#include "commandH.h"
#include "commandI.h"
#include "commandR.h"

using namespace std;

// reads in the next item in the line
string Command::readNextItem(istream &io) {
  char delimiter = ','; // delimiter
  const char space = ' ';
  string str;
  getline(io, str, delimiter);
  if (str.empty()) { // if the string is empty
    return str;
  }
  return str.substr(str.find_first_not_of(space),
                    str.find_last_not_of(space) + 1);
}

// read to end of line
const string Command::discardLine(istream &is) {
  string discard;
  getline(is, discard);
  return discard;
}