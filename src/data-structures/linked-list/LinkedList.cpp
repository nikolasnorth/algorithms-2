#include "LinkedList.h"

template<typename T>
Node<T>::Node(T data) : data_(data ? std::move(data) : nullptr), next_(nullptr), prev_(nullptr) {
  if (data == nullptr) throw std::invalid_argument("Data must not be null.");
}

template<typename T>
auto Node<T>::get_next() const -> std::optional<const T &> {
  if (next_) return *next_;
  return std::nullopt;
}

template<typename T>
auto Node<T>::get_prev() const -> std::optional<const T &> {
  if (prev_) return *prev_;
  return std::nullopt;
}

template<typename T>
auto Node<T>::get_data() const -> const T & {
  return data_;
}

template<typename T>
void Node<T>::set_next(T data) {
  if (data == nullptr) throw std::invalid_argument("Data must not be null.");
  next_ = std::make_shared<Node>(std::move(data));
}

template<typename T>
void Node<T>::set_prev(T data) {
  if (data == nullptr) throw std::invalid_argument("Data must not be null.");
  prev_ = std::make_shared<Node>(std::move(data));
}

template<typename T>
void Node<T>::set_data(T data) {
  if (data == nullptr) throw std::invalid_argument("Data must not be null.");
  data_ = std::move(data);
}

template<typename T>
LinkedList<T>::LinkedList() : _head(nullptr), _tail(nullptr), _size(0) {}

template<typename T>
LinkedList<T>::~LinkedList<T>() {
  Node<T> *current = this->_head;
  Node<T> *next;
  while (current != NULL) {
    next = current->next();
    delete current;
    current = next;
  }
}

template<typename T>
std::optional<T> LinkedList<T>::head() const {
  if (_size == 0) {
    return std::nullopt;
  }
  return _head->data();
}

template<typename T>
std::optional<T> LinkedList<T>::tail() const {
  if (_size == 0) {
    return std::nullopt;
  }
  return _tail->data();
}

template<typename T>
int LinkedList<T>::size() const {
  return _size;
}

template<typename T>
void LinkedList<T>::set_head(Node<T> *n) {
  this->_head = n;
}

template<typename T>
void LinkedList<T>::set_tail(Node<T> *n) {
  this->_tail = n;
}

template<typename T>
void LinkedList<T>::add(T data, int i) {
  if (i < -1 || this->_size < i) throw std::out_of_range("Index was out of range.");

  auto n = new Node<T>(data);
  if (this->_size == 0) {
    this->_head = n;
    this->_tail = n;
  } else if (i == 0) {
    n->set_next(this->_head);
    this->_head->set_prev(n);
    this->set_head(n);
  } else if (i == -1 || i == this->_size) {
    // Add to tail
    n->set_prev(this->_tail);
    this->_tail->set_next(n);
    this->set_tail(n);
  } else {
    auto current = this->_head;
    for (int j = 0; j < i - 1; j++) {
      current = current->next();
    }
    n->set_prev(current);
    n->set_next(current->next());
    current->next()->set_prev(n);
    current->set_next(n);
  }
  this->_size++;
}

template<typename T>
T LinkedList<T>::remove(int i) {
  if (i < -1 || this->_size <= i) throw std::out_of_range("Index was out of range.");

  Node<T> *n;
  T data;
  if (this->_size == 1) {
    n = this->_head;
    this->_head = nullptr;
    this->_tail = nullptr;
  } else if (i == 0) {
    n = this->_head;
    this->_head = this->_head->next();
    n->next()->set_prev(nullptr);
    n->set_next(nullptr);
  } else if (i == -1 || i == this->size() - 1) {
    n = this->_tail;
    this->_tail = this->_tail->prev();
    n->prev()->set_next(nullptr);
    n->set_prev(nullptr);
  } else {
    n = this->_head;
    for (int j = 0; j < i; j++) {
      n = n->next();
    }
    n->prev()->set_next(n->next());
    n->next()->set_prev(n->prev());
    n->set_prev(nullptr);
    n->set_next(nullptr);
  }
  data = n->data();
  delete n;
  this->_size--;
  return data;
}

template<typename T>
std::optional<T> LinkedList<T>::get(int i) const {
  if (_size == 0) return std::nullopt;
  if (i < 0 || this->_size <= i) throw std::out_of_range("Index was out of range.");

  auto n = this->_head;
  for (int j = 0; j < i; j++) {
    n = n->next();
  }
  return n->data();
}

template<typename T>
void LinkedList<T>::update(T data, int i) {
  if (i < 0 || this->_size <= i) throw std::out_of_range("Index was out of range.");

  if (i == 0) {
    this->_head->set_data(data);
  } else if (i == this->_size - 1) {
    this->_tail->set_data(data);
  } else {
    auto n = this->_head;
    for (int j = 0; j < i; j++) {
      n = n->next();
    }
    n->set_data(data);
  }
}

template<typename T>
bool LinkedList<T>::contains(T data, int from) const {
  if (from < 0 || this->_size <= from) throw std::out_of_range("Index was out of range.");

  auto n = this->_head;
  for (int i = 0; i < from; i++) {  // move to starting node
    n = n->next();
  }
  for (int i = from; i < this->_size; i++) {
    if (n->data() == data) {
      return true;
    }
    n = n->next();
  }
  return false;
}

template<typename T>
int LinkedList<T>::index_of(T data, int from) const {
  if (from < 0 || this->_size <= from) throw std::out_of_range("Index was out of range.");

  auto n = this->_head;
  for (int i = 0; i < from; i++) {  // move to starting node
    n = n->next();
  }
  for (int i = from; i < this->_size; i++) {
    if (n->data() == data) {
      return i;
    }
    n = n->next();
  }
  return -1;
}

template<typename T>
void LinkedList<T>::sort() {
  // TODO
}
