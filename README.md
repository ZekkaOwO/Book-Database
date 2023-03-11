# <center> Book Database </center>

## Description

This is a program that creates a book database to store books.
Features associated with a book are book ID, publication year and rating.

## Functions

*int addBook(int bookID, int year, double rating, std::vector<Book> &db)*: Add the book with the feature into the database if the book with the ID is not in the database yet and return 0, else return 1 and does nothing.

*int updateBook(int bookID, int year, double rating, std::vector<Book> &db)*: Update the book with the given ID to the new year and rating information.

*int deleteBook(int bookID, std::vector<Book> &db)*: Delete the book with the given ID and return 0. If such a book does not exist, return 1 and does nothing.

*std::vector<Book>* findBooks(int year, const std::vector<Book> &db)*: Find the book and return a pointer to that book.

*double calculateAverageRating(const std::vector<Book> &db)*: Calculate the average rating of all books in the database. If there is no book, return -1.0.

*void print(const std::vector<Book> &db)*: Print out all the information of all books currently in the database. If the database is empty, print "No entries".

*int sortDB(std::vector<Book> &db, int sortingMethod)*: Sort the books based on the sorting method. If sorting method is 1, sort by Book ID. If 2, sort by year. If 3, sort by rating. If there are books with same year or rating, then the one with smaller ID will be put in the front.

*int main()*: Function that prompt users and get user inputs. Once there is a ">" comes out, users can type their commands. Once "q" is typed, the program will end.


## Compile

Using the command *make build*.

## How to run it

After compling, there will be a file named *"BookDB"*. Once it comes up, 
using *./BookDB* to run it.

