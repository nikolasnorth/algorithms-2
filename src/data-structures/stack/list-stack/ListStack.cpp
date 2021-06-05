#include "ListStack.h"

template<typename T>
ListStack<T>::ListStack() : _items(std::list<T>()) {}

template<typename T>
int ListStack<T>::size() const {
  return _items.size();
}

template<typename T>
void ListStack<T>::enqueue(const T &data) {
  _items.push_back(data);
}

template<typename T>
std::optional<T> ListStack<T>::dequeue() {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  const auto item = _items.front();
  _items.pop_front();
  return item;
}

template<typename T>
std::optional<T> ListStack<T>::peek() const {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  return _items.front();
}
