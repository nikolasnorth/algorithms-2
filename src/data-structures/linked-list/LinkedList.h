#pragma once

#include <optional>
#include <memory>

template<typename T>
class Node {
private:
  std::shared_ptr<Node> next_;
  std::shared_ptr<Node> prev_;
  T data_;
public:
  Node() = delete;

  // Initializes a new node object storing the given data.
  // Throws std::invalid_argument if data is equal to nullptr.
  //
  // Time O:(1)
  explicit Node(T data);

  // Returns a const reference to the data stored at the next node (if it exists).
  // Otherwise, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  auto get_next() const -> std::optional<const T &>;

  // Returns a const reference to the data stored at the previous node (if it exists).
  // Otherwise, std::nullopt is returned.
  //
  // Time: O(1)
  [[nodiscard]]
  auto get_prev() const -> std::optional<const T &>;

  // Returns a const reference to the data stored at the current node.
  //
  // Time: O(1)
  [[nodiscard]]
  auto get_data() const -> const T &;

  // Sets next equal to a new node storing the given data.
  // Throws std::invalid_argument if data is equal to nullptr.
  //
  // Time: O(1)
  void set_next(T data);

  // Sets prev equal to a new node storing the given data.
  // Throws std::invalid_argument if data is equal to nullptr.
  //
  // Time: O(1)
  void set_prev(T data);

  // Sets data for the current node.
  // Throws std::invalid_argument if data is equal to nullptr.
  //
  // Time: O(1)
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
