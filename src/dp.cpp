// Dynamic Programming

#include <unordered_map>

// Returns the n-th fibonacci number (optimized with memoization).
//
// Time: O(n)
// Space: O(n) auxiliary
int64_t fib(int32_t n) {
  static std::unordered_map<int, int64_t> cache;

  if (n <= 2) return 1;
  if (cache.contains(n)) return cache[n];

  cache[n] = fib(n - 1) + fib(n - 2);
  return cache[n];
}
