#include "ArrayQueue.h"

template<typename T>
ArrayQueue<T>::ArrayQueue() : _items(std::vector<T>()) {}

template<typename T>
int ArrayQueue<T>::size() const {
  return _items.size();
}

template<typename T>
void ArrayQueue<T>::enqueue(T data) {
  _items.push_back(data);
}

template<typename T>
std::optional<T> ArrayQueue<T>::dequeue() {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  T item = _items.front();
  _items.erase(_items.begin());
  return item;
}

template<typename T>
std::optional<T> ArrayQueue<T>::peek() const {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  return _items.front();
}
