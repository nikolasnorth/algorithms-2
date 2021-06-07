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

  // Inserts given data to the Queue.
  void enqueue(T data);

  // Removes and returns data from the Queue.
  std::optional<T> dequeue();

  // Returns data from the Queue.
  [[nodiscard]]
  std::optional<T> peek() const;
};
