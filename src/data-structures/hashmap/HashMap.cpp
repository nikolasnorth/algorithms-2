#include "HashMap.h"

template<typename K, typename V>
Pair<K, V>::Pair(const K &key, const V &value) : _key(key), _val(value) {}

template<typename K, typename V>
V Pair<K, V>::value() const {
  return _val;
}

template<typename K, typename V>
void Pair<K, V>::set_value(const V &data) {
  _val = data;
}

template<typename K, typename V>
HashMap<K, V>::HashMap() : _items(std::vector<V>()), _size(0) {}

template<typename K, typename V>
int HashMap<K, V>::size() const {
  return _size;
}

template<typename K, typename V>
std::optional<V> HashMap<K, V>::get(const K &key) {
  // TODO
}

template<typename K, typename V>
void HashMap<K, V>::insert(const V &data) {
  // TODO
}

template<typename K, typename V>
std::optional<V> HashMap<K, V>::remove(const K &key) {
  // TODO
}

template<typename K, typename V>
void HashMap<K, V>::update(const K &key, const V &data) {
  // TODO
}
