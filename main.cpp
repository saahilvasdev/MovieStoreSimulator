/**
 * Driver for starting movie store tests
 */

#include <iostream>

#include "movieStore.h"

using namespace std;

// forward declaration, implementation in store_test.cpp
void testAllMovie() {
  MovieStore store1;
  cout << "--------------------Reading Movie Data--------------------" << endl;
  store1.readMoviesFromFile("data4movies.txt");
  cout << "--------------------Reading Customer Data--------------------"
       << endl;
  store1.readCustomersFromFile("data4customers.txt");
  cout << "--------------------Reading Command Data--------------------"
       << endl;
  store1.readCommandsFromFile("data4commands.txt");
}

int main() {
  testAllMovie();
  cout << "Done." << endl;
  return 0;
}
