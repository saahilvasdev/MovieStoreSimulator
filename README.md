# Self-Evaluation Comments

Compilation Warning:
The warning is "unused parameter 'is' in the method bool commandI::read(istream &is). This warning says that we did not use the variable is and this is correct as for Command Inventory's read method there is nothing else to read in as the syntax in the data4commands.txt is just 'I' for the command. We could not comment 'is' out in the .h/.cpp file as it is a override method and needs to match with its parent's declaration of the method.

Clang-tidy warning:
The warning is parameter 'is' is unused in method bool commandI::read(istream &is). The reasoning is the same as above in the complication warning section.

Code Coverage:
Most code that was never ran are error messages that would appear if the syntax of the data files were wrong.
As our program final test requires us to run the files that are provided for us (data4commands.txt, data4customers.txt, data4movies.txt) some error message will not be printed out.
The store_test.cpp was never ran as all the test are being made in main.cpp.

# Assumptions
In main.cpp, the readCommandsFromFile() method is ran after both readMoviesFromFile() and readCustomersFromFile() method are ran.

All syntax in data4commands.txt, data4customers.txt, data4movies.txt are correct. The only invalid input are undetermined movies or customers.

# Notes
store_test.cpp is never ran because all test are being ran in main.cpp

All methods that are created are already being test in the three following method calls from movieStore. Being readCommandsFromFile(), readMoviesFromFile(), readCustomersFromFile().