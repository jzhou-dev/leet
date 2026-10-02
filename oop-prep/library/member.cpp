#include "book.cpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Member {
private:
  int ID;
  std::string name;
  std::vector<Book *> borrowedBooks;

public:
  Member(int _ID, std::string _name) {
    ID = _ID;
    name = _name;
  }
  bool borrowBook(Book *book) {
    if (borrowedBooks.size() >= 3) {
      std::cout << "Error: " << name
                << " has reached the maximum number of books you "
                   "can borrow"
                << '\n';
      return false;
    }
    if (!book->borrowBook()) {
      std::cout << "Error: " << book->getTitle() << " by " << book->getAuthor()
                << " is currently unavailable" << '\n';
      return false;
    }
    std::cout << "Success: " << book->getTitle() << " by " << book->getAuthor()
              << " has been borrowed" << '\n';
    borrowedBooks.push_back(book);
    return true;
  }
  bool returnBook(Book *book) {
    if (std::find(borrowedBooks.begin(), borrowedBooks.end(), book) ==
        borrowedBooks.end()) {
      std::cout << "Error: " << name << " has not checked out this book"
                << '\n';
      return false;
    }
    std::cout << "Success: " << book->getTitle() << " by " << book->getAuthor()
              << " has been returned" << '\n';
    book->returnBook();
    borrowedBooks.erase(
        std::remove(borrowedBooks.begin(), borrowedBooks.end(), book),
        borrowedBooks.end());
    return true;
  }
  void listBorrowedBooks() {
    for (int i = 0; i < borrowedBooks.size(); ++i) {
      std::cout << borrowedBooks[i]->getTitle() << " by "
                << borrowedBooks[i]->getAuthor() << ' ';
    }
    std::cout << '\n';
  }
};
