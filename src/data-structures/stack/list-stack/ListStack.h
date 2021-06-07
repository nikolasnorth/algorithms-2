#pragma once

#include <list>
#include <optional>

template<typename T>
class ListStack {
private:
  std::list<T> _items;
public:
  ListStack();

  // Returns number of items in the Stack.
  [[nodiscard]]
  int size() const;

  // Insert given item onto the Stack.
  //
  // Time: O(1)
  void push(const T &data);

  // Removes and returns topmost element from the Stack.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  std::optional<T> pop();

  // Returns topmost element from the Stack.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> peek() const;
};
