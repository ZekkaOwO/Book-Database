/**
 * Name: Zhangfan Li
 * NetID: zli854
 * StudentID: 9080148449
 **/

#include "BookDB.h"
#include <iostream>
#include <string>

/**
 * Add a book with the given ID, year and rating to the database.
 * If succeed, return 0; otherwise return 1.
 **/
int addBook(int bookID, int year, double rating, std::vector<Book> &db) {
  for (std::size_t i = 0; i < db.size(); ++i) {
    if (db[i].ID == bookID) {
      return 1;
    }
  }
  Book book = {bookID, year, rating};
  db.push_back(book);
  return 0;
}

/**
 * Find the book with the given ID in the database,
 * and update it with the new ID, year and rating.
 * If succeed, return 0; otherwise return 1.
 **/
int updateBook(int bookID, int year, double rating, std::vector<Book> &db) {
  for (std::size_t i = 0; i < db.size(); ++i) {
    if (db[i].ID == bookID) {
      db[i].year = year;
      db[i].rating = rating;
      return 0;
    }
  }
  return 1;
}

/**
 * Delete the book in the database with the given BookID.
 * If succeed, return 0; otherwise return 1.
 **/
int deleteBook(int bookID, std::vector<Book> &db) {
  for (std::size_t i = 0; i < db.size(); ++i) {
    if (db[i].ID == bookID) {
      db.erase(std::begin(db) + i);
      return 0;
    }
  }
  return 1;
}

/**
 * Find books with the given year in the database.
 * If succeed, return 0; otherwise return 1.
 **/
std::vector<Book> *findBooks(int year, const std::vector<Book> &db) {
  std::vector<Book> *book = new std::vector<Book>;

  for (std::size_t i = 0; i < db.size(); ++i) {
    if (db[i].year == year) {
      book->push_back(db[i]);
    }
  }

  return book;
}

/**
 * Calculate the average rating for all books in the database.
 * If the database is empty, return -1.0.
 **/
double calculateAverageRating(const std::vector<Book> &db) {
  if (db.empty()) {
    return -1.0;
  }

  double count = 0;
  for (std::size_t i = 0; i < db.size(); ++i) {
    count = count + db[i].rating;
  }
  return count / db.size();
}

/**
 * Print out the ID, year and rating for all books in the database.
 **/
void print(const std::vector<Book> &db) {
  std::string c = ", ";
  for (std::size_t i = 0; i < db.size(); ++i) {
    std::cout << db[i].ID << c << db[i].year << c << db[i].rating << std::endl;
  }
}

/**
 * Sort the database with the given sorting method.
 * Method 1: sort by ID, book with smaller ID will be put at the front
 * Method 2: sort by year, book with smaller year will be in the front.
 *           For books with same year, the one with smaller ID will be in front.
 * Method 3: sort by rating. book will smaller rating will be in front.
 *           For books with same rating, the one with smaller ID will be in
 *           front.
 *
 * If other sort method is input, return 1 and does nothing.
 **/
int sortDB(std::vector<Book> &db, int sortingMethod) {
  if (sortingMethod != 1 && sortingMethod != 2 && sortingMethod != 3) {
    return 1;
  }

  if (sortingMethod == 1) {
    Book temp;
    for (std::size_t i = 0; i < db.size() - 1; i++) {
      for (std::size_t j = i + 1; j > 0; j--) {
        if (db[j].ID < db[j - 1].ID) {
          temp = db[j - 1];
          db[j - 1] = db[j];
          db[j] = temp;
        } else {
          break;
        }
      }
    }
    return 0;
  }

  if (sortingMethod == 2) {
    Book temp;
    for (std::size_t i = 0; i < db.size() - 1; i++) {
      for (std::size_t j = i + 1; j > 0; j--) {
        if (db[j].year < db[j - 1].year) {
          temp = db[j - 1];
          db[j - 1] = db[j];
          db[j] = temp;
        } else if (db[j].year == db[j - 1].year) {
          if (db[j].ID < db[j - 1].ID) {
            temp = db[j - 1];
            db[j - 1] = db[j];
            db[j] = temp;
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
    return 0;
  }

  if (sortingMethod == 3) {
    Book temp;
    for (std::size_t i = 0; i < db.size() - 1; i++) {
      for (std::size_t j = i + 1; j > 0; j--) {
        if (db[j].rating < db[j - 1].rating) {
          temp = db[j - 1];
          db[j - 1] = db[j];
          db[j] = temp;
        } else if (db[j].rating == db[j - 1].rating) {
          if (db[j].ID < db[j - 1].ID) {
            temp = db[j - 1];
            db[j - 1] = db[j];
            db[j] = temp;
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
    return 0;
  }

  return 0;
}
