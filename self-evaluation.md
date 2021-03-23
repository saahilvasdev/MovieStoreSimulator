# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No

Yes the program compiles and runs to completion

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0, there is one compilation warning but it is addressed in README.md

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0, there is one clang-tidy warning but it is addressed in README.md

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0, Yes the tests sufficiently test the code. All sections of line below were never execute
is addresserd in README.md.

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: In moviestore.cpp, in readCommandsFromFile() method, line 122 and 123.

invalid movie type: In moviestore.cpp, in readMoviesFromFile() method, line 81 and 82.

invalid customer ID: Located in two place. 
First place: In commandB.cpp, in execute() method, line 68 and 69. 
Second place: In commandr.cpp, in execute() method, line 65 and 66.
 
invalid movie: Located in two place. 
First place: In commandB.cpp, in execute() method, line 72 and 73. 
Second place: In commandR.cpp, in execute() method, line 69 and 70.

factory classes: Two Factory classes.
One is located in commandFactory.h and commandFactory.cpp. 
The other one is located in movie.h and movie.cpp.

hashtable: Two hashtables. 
One hashtable is located in commandFactory.h/.cpp. 
The other is located in movie.h/.cpp. 
Both hashfunction is called getIndex(). The hashtable takes in a char that represents a movie sub-genre type. Than it checks if the letter is between A - Z. If so than give an index for that letter which is just  the following algorithm "charGiven - 'A'". Than this index is used in each Factory respectively. 

container used for comedy movies: Located in moviestore.h/.cpp. It is a private variable called genresOfMovies and the container for comedy movies is inside this genresOfMovies map. So is the other container for the other two movies.

function for sorting comedy movies: Located in comedy.h/.cpp, the function is called genreSort(). 

function where comedy movies are sorted: Located in moviestore.cpp, the method is called sortbyMovieDefaultKey(), located in line 155 - 158. This method is a lambda function that uses a specific sub-genre's genreSort() method. This sortByMovieDefaultKey() is than called in the method readMoviesFromFile() (Still in moviestore.cpp) in line 76.

functions called when retrieving a comedy movie based on title and year: The function name is getMovie() which is located in movieStore.h/.cpp. This function is than called in two places. First place: In commandB.cpp, in execute() method, line 67. Second place: In commandR.cpp, in execute() method, line 64.

functions called for retrieving and printing customer history: The function is called getCustomer which is located in movieStore.g/.cpp. This function is than called in one place. In commandH.cpp, in execute() method, line 40. Than once the customer object is retrived we print its infomation out with the function printTransactionHistory() which is line 43 of commandH.cpp.

container used for customer history: Located in moviestore.h/.cpp. It is a private variable called listOfCustomers.

functions called when borrowing a movie:
List of functions being called for borrowing a movie (All located in commandB.cpp under execute() method, line 64 - 85):
getCustomer();
getMovie();
inStock();
decrementStock();
addBorrow();
addTransaction();

explain borrowing a movie that does not exist: Once the commandB object's execute method is called in movieStore.cpp under the readMoviesFromfile() method. It than goes into commandB.cpp's execute() method. It makes a new Movie* to point at the movie object that is being stored in the MovieStore object by using the method "getMovie()". Than it checks if the pointer is pointing to a nullptr. If it does, that means the movie does not exist so a error message is printed out and the method is finished.

explain borrowing a movie that has 0 stock: Once the commandB object's execute method is called in movieStore.cpp under the readMoviesFromfile() method. It than goes into commandB.cpp's execute() method. Once it has confirmed that the movie does exist, it checks if the movie is in stock by using the method "inStock()". If the method returns false than it means the movie is out of stock and it prints out an error message saying you cannot borrow a movie that is out of stock.

explain returning a movie that customer has not checked out: Once the commandR object's execute method is called in movieStore.cpp under the readMoviesFromfile() method. It than goes into commandR.cpp's execute() method. In the execute() method it first checks if the customer and movie exist. If the tests are passed than it checks if the customer is returning a movie they have checked out. Which is the method called "removeBorrow()" which is a boolean method that checks the customer's container of movies being borrow. If the movie being return was never borrowed than we print out a error message stating that Customer ID: ___ does not have the movie borrow so they can't return it in the first place.

any static_cast or dynamic_cast used: We use dynamic_cast in 3 places. 
First place: Located in drama.cpp, in genreSort method, line 47.
Second place: Located in comedy.cpp, in genreSort method, line 47.
Third place: Located in classics.cpp, in genreSort method, line 50.


Q: Total points: 25