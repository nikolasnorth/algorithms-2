#pragma once

#include <stdexcept>

template<typename T, std::size_t N>
class StaticArray {

private:
  T _items[N];

public:
  StaticArray();

  // Returns maximum number of items this StaticArray can hold.
  [[nodiscard]]
  constexpr std::size_t size() const;

  // Returns mutable reference to item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  T &operator[](const int i);

  // Returns readonly reference to item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  [[nodiscard]]
  const T &operator[](const int i) const;

  // Insert/overwrite position i with data.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  void insert(const int i, const T &data);
};

