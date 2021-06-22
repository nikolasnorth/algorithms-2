// Dynamic Programming

#include <unordered_map>
#include <vector>
#include <optional>

typedef unsigned int uint;

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

// Given a list of numbers, asserts whether there exists a combination of those numbers which add up to the
// target sum.
// Note: numbers can be summed more than once to achieve the target.
//
// Time: O(m * n)
// Space: O(m)
// where m = target, and n = size of nums.
bool can_sum(const int target, const std::vector<unsigned int> &nums, std::unordered_map<unsigned int, bool> &cache) {
  if (cache.contains(target)) return cache[target];
  if (target == 0) return true;
  if (target < 0) return false;

  for (const unsigned int &n : nums) {
    cache[target - n] = can_sum(static_cast<int>(target - n), nums, cache);
    if (cache[target - n]) return true;
  }

  cache[target] = false;
  return false;
}

// Given a list of numbers, returns a set of those numbers which add up to the target sum.
// If the target sum is not possible given the list of numbers, NULL will be returned.
// Note: numbers can be summed more than once to achieve the target.
//
// Time: O(m * n)
// Space: O(m * n)
// where m = target, and n = size of nums
std::optional<std::vector<uint>> how_sum(const int target, const std::vector<uint> &nums, std::unordered_map<int, std::optional<std::vector<uint>>> &cache) {
  if (target == 0) return std::vector<uint>();
  if (target < 0) return std::nullopt;
  if (cache.contains(target)) return cache[target];

  for (const unsigned int &n : nums) {
    auto result = how_sum(static_cast<int>(target - n), nums, cache);
    if (result.has_value()) {
      result.value().push_back(n);
      cache[target] = result.value();
      return result.value();
    }
  }

  cache[target] = std::nullopt;
  return std::nullopt;
}
