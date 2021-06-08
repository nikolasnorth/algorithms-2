#pragma once

#include <list>
#include <optional>

template<typename T>
class ListQueue {
private:
  std::list<T> _items;
public:
  ListQueue();

  // Returns number of items in the queue.
  [[nodiscard]]
  int size() const;

  // Inserts given item into the queue.
  //
  // Time: O(1)
  void enqueue(const T &data);

  // Removes and returns next item from the queue.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  std::optional<T> dequeue();

  // Returns next item from the queue.
  // If empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> peek() const;
};
