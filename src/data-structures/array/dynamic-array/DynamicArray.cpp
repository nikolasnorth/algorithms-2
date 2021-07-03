#include "DynamicArray.h"

template<typename T, size_t N>
DynamicArray<T, N>::DynamicArray(float growth_factor) : _gf(growth_factor) {}

template<typename T, std::size_t N>
constexpr std::size_t DynamicArray<T, N>::capacity() const {
  return N;
}

template<typename T, std::size_t N>
T &DynamicArray<T, N>::operator[](const std::size_t &i) {
  if (i < 0 || N <= i) throw std::out_of_range("Index out of range.");

  return _items[i];
}

template<typename T, std::size_t N>
const T &DynamicArray<T, N>::operator[](const std::size_t &i) const {
  if (i < 0 || N <= i) throw std::out_of_range("Index out of range.");

  return _items[i];
}
