#include <iostream>
#include "sorting.cpp"

std::ostream &operator<<(std::ostream &s, const std::vector<int> &v) {
  for (const int &i : v) {
    s << i << ' ';
  }
  return s;
}

void test_bubble_sort() {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bubble_sort(items);
  if (items != sorted) {
    std::cerr << "Bubble sort failed." << std::endl;
  }
}

int main() {
  test_bubble_sort();
}
