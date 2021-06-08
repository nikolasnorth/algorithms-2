#pragma once

#include <stdexcept>
#include <optional>

template<typename T>
class Node {
private:
  Node *_next;
  Node *_prev;
  T _data;
public:
  explicit Node(T data);

  [[nodiscard]]
  Node *next() const;

  [[nodiscard]]
  Node *prev() const;

  [[nodiscard]]
  int data() const;

  void set_next(Node *n);

  void set_prev(Node *n);

  void set_data(T data);
};

template<typename T>
class LinkedList {
private:
  Node<T> *_head;
  Node<T> *_tail;
  int _size;
public:
  explicit LinkedList();

  ~LinkedList();

  // Returns data stored in the first node of the list.
  // If list is empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> head() const;

  // Returns data stored in the last node of the list.
  // If list is empty, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  std::optional<T> tail() const;

  // Returns the number of nodes in the list.
  [[nodiscard]]
  int size() const;

  void set_head(Node<T> *n);

  void set_tail(Node<T> *n);

  // Inserts node into the list at given index (tail by default).
  // Throws exception if index is out of range.
  //
  // Time: O(1)
  void add(T data, int i = -1);

  // Removes node from list at given index (tail by default).
  // Throws exception if index is out of range or list is empty.
  //
  // Time: O(n)
  T remove(int i = -1);

  // Returns data stored at the given index.
  // If list is empty, std::nullopt is returned.
  // Throws exception if list is not empty and index is out of range.
  //
  // Time: O(n)
  [[nodiscard]]
  std::optional<T> get(int i) const;

  // Updates data at the given index.
  // Throws exception if index is out of range.
  //
  // Time: O(n)
  void update(T data, int i);

  // Checks if list holds the specified data starting from an index
  // (beginning of list by default).
  // Throws exception if index is out of range.
  //
  // Time: O(n)
  [[nodiscard]]
  bool contains(T data, int from = 0) const;

  // Returns the index of given data. Returns -1 data not found.
  // data: item to be searched
  // from: [Optional] index to serve as starting point (start of list by default)
  // Throws exception if index is out of range.
  //
  // Time: O(n)
  [[nodiscard]]
  int index_of(T data, int from = 0) const;

  void sort();
};
