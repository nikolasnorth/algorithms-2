#include <vector>

// Sorts items in ascending order using bubble sort algorithm.
//
// Time: O(n^2)
// Space: O(1) auxiliary
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

// Sorts items in ascending order using insertion sort algorithm.
//
// Time: O(n^2)
// Space: O(1) auxiliary
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

// Sorts items in ascending order using selection sort algorithm.
//
// Time: O(n^2)
// Space: O(1) auxiliary
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

// Sort items in ascending order using merge sort algorithm.
//
// Time: O(nlogn)
// Space: O(n) auxiliary
template<typename T>
std::vector<T> merge_sort(std::vector<T> &items) {
  if (items.size() == 1) return items;

  const int mid = static_cast<int>(items.size() / 2);  // drop remainder (if necessary)
  std::vector<T> l(items.begin(), items.begin() + mid);
  std::vector<T> r(items.begin() + mid, items.end());
  l = merge_sort(l);
  r = merge_sort(r);
  return merge(l, r);
}

// Sorts items in ascending order using quicksort algorithm.
// lo: Starting index of items
// hi: Last index of items
//
// Time: O(nlogn) with very high probability
// Space: O(n) auxiliary
template<typename T>
void quicksort(std::vector<T> &items, int lo, int hi) {
  if (lo >= hi) return;

  // Choose random pivot
  int pivot = rand() % (hi + 1);
  // Move pivot to end of items
  T tmp;
  tmp = items[pivot];
  items[pivot] = items[hi];
  items[hi] = tmp;
  pivot = hi;

  int i = lo, j = lo;
  while (j < pivot) {
    if (items[j] < items[pivot]) {
      // Swap i and j
      tmp = items[j];
      items[j] = items[i];
      items[i] = tmp;
      i++;
    }
    j++;
  }
  // Swap i and pivot
  tmp = items[pivot];
  items[pivot] = items[i];
  items[i] = tmp;
  pivot = i;
  quicksort(items, lo, pivot - 1);
  quicksort(items, pivot + 1, hi);
}
