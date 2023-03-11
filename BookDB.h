#ifndef BOOKDB_H
#define BOOKDB_H

#include <iostream>
#include <vector>

typedef struct {
  int ID;
  int year;
  double rating;
} Book;

int addBook(int bookID, int year, double rating, std::vector<Book> &db);
int updateBook(int bookID, int year, double rating, std::vector<Book> &db);
int deleteBook(int bookID, std::vector<Book> &db);
std::vector<Book>* findBooks(int year, const std::vector<Book> &db);
double calculateAverageRating(const std::vector<Book> &db);
void print(const std::vector<Book> &db);
int sortDB(std::vector<Book> &db, int sortingMethod);

#endif
