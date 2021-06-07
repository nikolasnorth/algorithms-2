#pragma once

#include <vector>
#include <optional>

template<typename T>
class ArrayStack {
private:
  std::vector<T> _items;
public:
  ArrayStack();

  // Returns number of items in the Stack.
  [[nodiscard]]
  int size() const;

  // Inserts given item onto the Stack.
  //
  // Time: O(1)
  void push(const T &data);

  // Removes and returns next item from the Stack.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  std::optional<T> pop();

  // Returns next item from the Stack.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> peek() const;
};
