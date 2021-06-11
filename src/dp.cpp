// Dynamic Programming

#include <unordered_map>

// Returns the n-th fibonacci number (using naive approach).
//
// Time: O(2^n)
// Space: O(n) auxiliary
int64_t fib(int32_t n) {
  if (n <= 2) return 1;
  return fib(n - 1) + fib(n - 2);
}

// Returns the n-th fibonacci number (using memoization).
//
// Time: O(n)
// Space: O(n) auxiliary
int64_t fib(int32_t n, std::unordered_map<int32_t, int64_t> &memo) {
  if (memo.find(n) != memo.end()) return memo[n];
  if (n <= 2) return 1;

  memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
  return memo[n];
}
