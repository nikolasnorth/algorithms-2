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
