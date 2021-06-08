#pragma once

#include <vector>
#include <optional>

template<typename T>
class ArrayQueue {
private:
  std::vector<T> _items;
public:
  ArrayQueue();

  // Returns number of items in the Queue.
  [[nodiscard]]
  int size() const;

  // Inserts given item into the Queue.
  //
  // Note: If number of items exceeds the max capacity of the
  // underlying array, reallocation is performed.
  //
  // Time: O(1) amortized, O(n) if reallocation occurs.
  void enqueue(const T &data);

  // Removes and returns next item from the Queue.
  // If empty, std::nullopt is returned.
  //
  // Note: Underlying array data structure requires all elements to
  // be shifted one position after the first element is removed.
  //
  // Time: O(n)
  std::optional<T> dequeue();

  // Returns next item from the Queue.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> peek() const;
};
