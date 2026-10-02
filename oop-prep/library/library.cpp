#include "member.cpp"
#include <unordered_set>

class Library {
private:
  std::unordered_set<Member *> members;
  std::unordered_set<Book *> books;
};
