#include <string>

class Book {
private:
  int ID;
  bool available;
  std::string title;
  std::string author;

public:
  Book(int _ID, std::string _title, std::string _author) {
    ID = _ID;
    title = _title;
    author = _author;
    available = true;
  }
  bool borrowBook() {
    if (!available) {
      return false;
    }
    available = false;
    return true;
  }
  void returnBook() { available = true; }
  std::string getTitle() { return title; }
  std::string getAuthor() { return author; }
};
