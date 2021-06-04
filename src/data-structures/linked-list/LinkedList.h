#pragma once

#include <stdexcept>
#include <memory>
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

  [[nodiscard]]
  Node<T> *head() const;

  [[nodiscard]]
  Node<T> *tail() const;

  [[nodiscard]]
  int size() const;

  void set_head(Node<T> *n);

  void set_tail(Node<T> *n);

  void add(T data, int i = -1);

  const Node<T> *get(int i) const;

  const Node<T> *find(T data, int from = 0) const;

  int index_of(T data, int from = 0) const;

  void sort();
};
