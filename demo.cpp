/**
 * Name: Zhangfan Li
 * NetID: zli854
 * StudentID: 9080148449
 **/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "BookDB.h"
using namespace std;

/**
 * Main funcion for the database. Provides with
 * all commands and give out the user input format.
 **/

int main() {
  cout << "> ";
  char command;
  int BookID;
  int year;
  double rate;
  int sort;
  cin >> command;
  vector<Book> db;

  while (command != 'q') {
    if (command == 'p') {
      if (db.empty()) {
        cout << "No entries" << endl;
      } else {
        print(db);
      }

    } else if (command == 'a') {
      cin >> BookID >> year >> rate;
      if (addBook(BookID, year, rate, db) == 1) {
        cout << "Error processing command" << endl;
      } else {
        cout << "Book " + to_string(BookID) + " added" << endl;
      }

    } else if (command == 'd') {
      cin >> BookID;
      if (deleteBook(BookID, db) == 1) {
        cout << "Error processing command" << endl;
      } else {
        cout << "Book " + to_string(BookID) + " removed" << endl;
      }

    } else if (command == 'u') {
      cin >> BookID >> year >> rate;
      if (updateBook(BookID, year, rate, db) == 0) {
        cout << "Book " + to_string(BookID) + " updated" << endl;
      } else {
        cout << "Error processing command" << endl;
      }

    } else if (command == 'c') {
      if (calculateAverageRating(db) == -1) {
        cout << "Error processing command" << endl;
      } else {
        double average = calculateAverageRating(db);
        cout << "Average rating = ";
        cout << average << endl;
      }

    } else if (command == 'f') {
      cin >> year;
      if (db.empty()) {
        cout << "No entries" << endl;
      } else {
        vector<Book> *temp = findBooks(year, db);
        print(*temp);
        delete temp;
      }

    } else if (command == 's') {
      cin >> sort;
      if (sortDB(db, sort) == 1) {
        cout << "Error processing command" << endl;
      }
    }
    cout << "> ";
    cin >> command;
  }
  cout << "quit" << endl;
  exit(1);
}