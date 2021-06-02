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
    for (int j = i; j >= 0; j--) {
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
