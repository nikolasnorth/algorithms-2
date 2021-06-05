#pragma once

#include <list>
#include <optional>

template<typename T>
class ListStack {
private:
  std::list<T> _items;
public:
  ListStack();

  [[nodiscard]]
  int size() const;

  void enqueue(const T &data);

  std::optional<T> dequeue();

  [[nodiscard]]
  std::optional<T> peek() const;
};
