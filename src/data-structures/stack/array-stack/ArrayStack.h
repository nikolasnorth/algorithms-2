#pragma once

#include <vector>
#include <optional>

template<typename T>
class ArrayStack {
private:
  std::vector<T> _items;
public:
  ArrayStack();

  [[nodiscard]]
  int size() const;

  void push(const T &data);

  std::optional<T> pop();

  [[nodiscard]]
  std::optional<T> peek() const;
};
