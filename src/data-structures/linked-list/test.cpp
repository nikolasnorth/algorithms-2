#include <iostream>
#include <vector>
#include "LinkedList.cpp"

// Print LinkedList
std::ostream &operator<<(std::ostream &s, const LinkedList<int> &list) {
  for (int i = 0; i < list.size(); i++) {
    s << list.get(i)->data() << " ";
  }
  return s;
}

// Print vectors
std::ostream &operator<<(std::ostream &s, const std::vector<int> &vec) {
  for (const auto &i : vec) {
    s << i << " ";
  }
  return s;
}

void test_add() {
  const std::vector<int> items = {10, 11, 12, 13, 14};

  auto list = LinkedList<int>();
  for (const auto &i : items) list.add(i);

  for (int j = 0; j < items.size(); j++) {
    if (list.get(j)->data() != items[j]) {
      std::cerr << "LinkedList::add() failed." << std::endl;
      std::cout << "Got:\t" << list << std::endl;
      std::cout << "Want:\t" << items << std::endl;
      return;
    }
  }
}

int main() {
  test_add();
}
