#include "StaticArray.h"

template<typename T, std::size_t N>
StaticArray<T, N>::StaticArray() = default;

template<typename T, std::size_t N>
constexpr std::size_t StaticArray<T, N>::size() const {
  return N;
}

template<typename T, std::size_t N>
T &StaticArray<T, N>::operator[](const int i) {
  if (i < 0 || N <= i) throw std::out_of_range("Index out of range.");

  return _items[i];
}

template<typename T, std::size_t N>
const T &StaticArray<T, N>::operator[](const int i) const {
  if (i < 0 || N <= i) throw std::out_of_range("Index out of range.");

  return _items[i];
}

template<typename T, std::size_t N>
void StaticArray<T, N>::insert(int i, const T &data) {
  if (i < 0 || N <= i) throw std::out_of_range("Index out of range.");

  _items[i] = data;
}
