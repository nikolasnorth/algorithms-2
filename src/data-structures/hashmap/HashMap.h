#pragma once

#include <vector>
#include <optional>
#include <string>

template<typename K, typename V>
class Pair {
private:
  K _key;
  V _val;
public:
  Pair(const K &key, const V &data);

  V value() const;

  void set_value(const V &data);
};

template<typename K, typename V>
class HashMap {
  std::vector<V> _items;
  int _size;
  int _capacity;
  float load_factor;
public:
  HashMap();

  [[nodiscard]]
  int size() const;

  std::optional<V> get(const K &key);

  void insert(const V &data);

  std::optional<V> remove(const K &key);

  void update(const K &key, const V &data);
};
