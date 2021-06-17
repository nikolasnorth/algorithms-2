#pragma once

#include <cstdlib>
#include <stdexcept>

template<typename T, size_t N>
class StaticArray {

private:
T _items[N];
size_t _size;
const size_t _cap;

public:
  StaticArray();

  // Checks whether the array is empty (i.e. size = 0).
  [[nodiscard]]
  bool is_empty() const;

  // Returns number of items currently in the StaticArray.
  [[nodiscard]]
  size_t size() const;

  // Returns maximum number of items this StaticArray can hold.
  [[nodiscard]]
  size_t capacity() const;

  // Returns item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  [[nodiscard]]
  T get(const int i) const;

  // Returns item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  [[nodiscard]]
  T operator[](const int i) const;

  // Inserts/overwrites data at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  void insert(const int i, const T &data);
};
