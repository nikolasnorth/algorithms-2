// Dynamic Programming

#include <unordered_map>
#include <vector>
#include <optional>
#include <string>

using uint = unsigned int;

// Returns the n-th fibonacci number (optimized with memoization).
//
// Time: O(n)
// Space: O(n) auxiliary
//
auto fib(int n) -> uint64_t {
  static std::unordered_map<int, uint64_t> cache;

  if (n <= 2) return 1;
  if (cache.contains(n)) return cache[n];

  cache[n] = fib(n - 1) + fib(n - 2);
  return cache[n];
}


// Given a list of numbers, asserts whether there exists a combination of those numbers which add up to the target sum.
// Note: numbers can be summed more than once to achieve the target.
//
// Time: O(m * n)
// Space: O(m)
// where m = target, and n = size of nums.
//
auto can_sum(const int target, const std::vector<uint> &nums, std::unordered_map<uint, bool> &cache) -> bool {
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


// Returns a list of the given numbers which add up to the target sum.
// If the target sum is not possible given the list of numbers, std::nullopt will be returned.
// Note: numbers can be summed more than once to achieve the target.
//
// Time: O(m * n)
// Space: O(m^2)
// where m = target, and n = size of nums
//
auto how_sum(
    const int target, const std::vector<uint> &nums, std::unordered_map<int, std::optional<std::vector<uint>>> &cache
) -> std::optional<std::vector<uint>> {
  if (target == 0) return std::vector<uint>();
  if (target < 0) return std::nullopt;
  if (cache.contains(target)) return cache[target];

  for (const uint &n : nums) {
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


// Returns the shortest possible list of the given numbers which add up to the target sum.
// If the target sum is not possible given the list of numbers, std::nullopt will be returned.
// Note: numbers can be summed more than once to achieve the target.
//
// Time: O(m^2 * n)
// Space: O(m^2)
// where m = target, and n = size of nums
//
auto best_sum(
    const int target, const std::vector<uint> &nums, std::unordered_map<int, std::optional<std::vector<uint>>> &cache
) -> std::optional<std::vector<uint>> {
  if (target == 0) return std::vector<uint>();
  if (target < 0) return std::nullopt;
  if (cache.contains(target)) return cache[target];

  std::optional<std::vector<uint>> best = std::nullopt;
  for (const uint &n : nums) {
    auto result = best_sum(static_cast<int>(target - n), nums, cache);
    if (!result.has_value()) continue;

    result.value().push_back(n);
    if (!best.has_value() || result.value().size() < best.value().size()) {
      best = result;
    }
  }

  cache[target] = best;
  return best;
}


// Given a list of words, asserts whether the target can be constructed by any combination of those words.
// Note: Any given word can be used more than once to construct the target.
//
// Time: O(m^2 * n)
// Space: O(m^2)
// where m = size of target, and n = size of words
//
bool can_construct(const std::string &target, const std::vector<std::string> &words, std::unordered_map<std::string, bool> &cache) {
  if (target.empty()) return true;
  if (cache.contains(target)) return cache[target];

  for (const std::string &word : words) {
    const auto i = target.find(word);
    if (i != 0) continue;  // word not a prefix of target

    auto target_copy = target;
    auto result = can_construct(target_copy.erase(i, word.length()), words, cache);
    cache[target] = result;

    if (result) return true;
  }

  cache[target] = false;
  return false;
}
