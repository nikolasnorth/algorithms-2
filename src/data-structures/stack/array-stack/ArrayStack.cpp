#include "ArrayStack.h"

template<typename T>
ArrayStack<T>::ArrayStack() : _items(std::vector<T>()) {}

template<typename T>
int ArrayStack<T>::size() const {
  return _items.size();
}

template<typename T>
void ArrayStack<T>::push(const T &data) {
  _items.push_back(data);
}

template<typename T>
std::optional<T> ArrayStack<T>::pop() {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  const auto item = _items.back();
  _items.pop_back();
  return item;
}

template<typename T>
std::optional<T> ArrayStack<T>::peek() const {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  return _items.back();
}
