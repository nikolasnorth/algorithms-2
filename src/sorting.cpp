#include <vector>

template<typename T>
void bubble_sort(std::vector<T> &items) {
  for (int i = 0; i < items.size() - 1; i++) {
    bool done = true;
    for (int j = 0; j < items.size() - i - 1; j++) {
      if (items[j] > items[j + 1]) {
        // Swap items
        T tmp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = tmp;
        done = false;
      }
    }
    if (done) break;
  }
}

template<typename T>
void insertion_sort(std::vector<T> &items) {
  for (int i = 1; i < items.size(); i++) {
    for (int j = i; j > 0; j--) {
      if (items[j] >= items[j - 1]) break;
      // Shift items[j] left 1 position
      T tmp = items[j];
      items[j] = items[j - 1];
      items[j - 1] = tmp;
    }
  }
}

template<typename T>
void selection_sort(std::vector<T> &items) {
  for (int i = 0; i < items.size() - 1; i++) {
    int min = i;
    for (int j = i + 1; j < items.size(); j++) {
      if (items[j] < items[min]) min = j;
    }
    if (i != min) {
      // Swap items[i] and items[min]
      T tmp = items[i];
      items[i] = items[min];
      items[min] = tmp;
    }
  }
}

// Merges two given sorted arrays, a and b, into one sorted array.
template<typename T>
std::vector<T> merge(std::vector<T> &a, std::vector<T> &b) {
  std::vector<T> result;
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j]) {
      result.push_back(a[i]);
      i++;
    } else {
      result.push_back(b[j]);
      j++;
    }
  }
  while (i < a.size()) {
    result.push_back(a[i]);
    i++;
  }
  while (j < b.size()) {
    result.push_back(b[j]);
    j++;
  }
  return result;
}

template<typename T>
std::vector<T> merge_sort(std::vector<T> &a) {
  if (a.size() == 1) return a;
  const int mid = static_cast<int>(a.size() / 2);  // drop remainder (if necessary)
  std::vector<T> l(a.begin(), a.begin() + mid);
  std::vector<T> r(a.begin() + mid, a.end());
  l = merge_sort(l);
  r = merge_sort(r);
  return merge(l, r);
}
