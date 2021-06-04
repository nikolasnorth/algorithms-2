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

  [[nodiscard]]
  Node<T> *head() const;

  [[nodiscard]]
  Node<T> *tail() const;

  [[nodiscard]]
  int size() const;

  void set_head(Node<T> *n);

  void set_tail(Node<T> *n);

  // Adds Node to LinkedList at given index (tail by default).
  // Throws exception if index is out of range.
  void add(T data, int i = -1);

  // Removes Node from LinkedList at given index (tail by default).
  // Throws exception if index is out of range.
  T remove(int i = -1);

  // Retrieves Node at given index.
  // Throws exception if index is out of range.
  const Node<T> *get(int i) const;

  // Updates data at given index.
  // Throws exception if index is out of range.
  void update(T data, int i);

  // Checks if LinkedList holds the specified data
  // starting from an index (beginning of list by default).
  // Throws exception if index is out of range.
  bool contains(T data, int from = 0) const;

  // Returns the index of the given data starting from
  // an index (beginning of list by default).
  // Returns -1 if data not found.
  // Throws exception if index is out of range.
  int index_of(T data, int from = 0) const;

  void sort();
};
