#include "StaticArray.h"

template<typename T, size_t N>
StaticArray<T, N>::StaticArray() : _size(0), _cap(N) {}

template<typename T, size_t N>
bool StaticArray<T, N>::is_empty() const {
  return _size == 0;
}

template<typename T, size_t N>
size_t StaticArray<T, N>::size() const {
  return _size;
}

template<typename T, size_t N>
size_t StaticArray<T, N>::capacity() const {
  return _cap;
}

template<typename T, size_t N>
T StaticArray<T, N>::get(const int i) const {
  if (i < 0 || _cap <= i) throw std::out_of_range("Index out of range.");

  return _items[i];
}

template<typename T, size_t N>
T StaticArray<T, N>::operator[](const int i) const {
  return get(i);
}

template<typename T, size_t N>
void StaticArray<T, N>::insert(int i, const T &data) {
  if (i < 0 || _cap <= i) throw std::out_of_range("Index out of range.");

  _items[i] = data;
  _size++;
}
