#include "ListQueue.h"

template<typename T>
ListQueue<T>::ListQueue() : _items(std::list<T>()) {}

template<typename T>
int ListQueue<T>::size() const {
  return _items.size();
}

template<typename T>
void ListQueue<T>::enqueue(const T &data) {
  _items.push_back(data);
}

template<typename T>
std::optional<T> ListQueue<T>::dequeue() {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  T item = _items.front();
  _items.pop_front();
  return item;
}

template<typename T>
std::optional<T> ListQueue<T>::peek() const {
  if (_items.size() == 0) {
    return std::nullopt;
  }
  return _items.front();
}
