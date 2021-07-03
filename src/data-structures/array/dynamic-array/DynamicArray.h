#pragma once

#include <array>

template<typename T, std::size_t N = 0>
class DynamicArray {
private:
  std::array<T, N> _items;
  float _gf;  // Growth factor
public:
  explicit DynamicArray(float growth_factor = 2);

  [[nodiscard]]
  constexpr std::size_t capacity() const;

  // Returns mutable reference to item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  T &operator[](const std::size_t &i);

  // Returns readonly reference to item at position i.
  // Throws std::out_of_range exception if i is less than zero or greater than capacity.
  [[nodiscard]]
  const T &operator[](const std::size_t &i) const;
};
