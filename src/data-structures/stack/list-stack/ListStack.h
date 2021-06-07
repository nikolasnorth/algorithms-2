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

  void push(const T &data);

  std::optional<T> pop();

  [[nodiscard]]
  std::optional<T> peek() const;
};
