#include "catch.hh"
#include "../src/sorting.cpp"

TEST_CASE("Bubble sort") {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  bubble_sort(items);
  CHECK(items == sorted);
}

TEST_CASE("Insertion sort") {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  insertion_sort(items);
  CHECK(items == sorted);
}

TEST_CASE("Selection sort") {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  selection_sort(items);
  CHECK(items == sorted);
}

TEST_CASE("Merge sort") {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  items = merge_sort(items);
  CHECK(items == sorted);
}

TEST_CASE("Quick sort") {
  std::vector<int> items = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  std::vector<int> sorted = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  quicksort(items, 0, (int) items.size() - 1);
  CHECK(items == sorted);
}
