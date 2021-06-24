#include "catch.hh"
#include "../src/dp.cpp"

TEST_CASE("fib()") {
  REQUIRE(fib(6) == 8);
  REQUIRE(fib(7) == 13);
  REQUIRE(fib(8) == 21);
  REQUIRE(fib(50) == 12586269025);  // should finish fairly quickly
}

TEST_CASE("can_sum()") {
  std::unordered_map<unsigned int, bool> cache;

  REQUIRE(can_sum(7, std::vector<unsigned int>{2, 3}, cache) == true);
  cache.clear();
  REQUIRE(can_sum(7, std::vector<unsigned int>{5, 3, 4, 7}, cache) == true);
  cache.clear();
  REQUIRE(can_sum(7, std::vector<unsigned int>{2, 4}, cache) == false);
  cache.clear();
  REQUIRE(can_sum(8, std::vector<unsigned int>{2, 3, 5}, cache) == true);
  cache.clear();
  REQUIRE(can_sum(300, std::vector<unsigned int>{7, 14}, cache) == false);  // should finish fairly quickly
}

TEST_CASE("how_sum()") {
  std::unordered_map<int, std::optional<std::vector<uint>>> cache;

  REQUIRE(how_sum(7, std::vector<uint>{2, 3}, cache).has_value() == true);
  cache.clear();
  REQUIRE(how_sum(7, std::vector<uint>{5, 3, 4, 7}, cache).has_value() == true);
  cache.clear();
  REQUIRE(how_sum(7, std::vector<uint>{2, 4}, cache).has_value() == false);
  cache.clear();
  REQUIRE(how_sum(8, std::vector<uint>{2, 3, 5}, cache).has_value() == true);
  cache.clear();
  REQUIRE(how_sum(300, std::vector<uint>{7, 14}, cache).has_value() == false);  // should finish fairly quickly
}

TEST_CASE("best_sum()") {
  std::unordered_map<int, std::optional<std::vector<uint>>> cache;

  REQUIRE(best_sum(7, std::vector<uint>{5, 3, 4, 7}, cache).value_or(std::vector<uint>()) == std::vector<uint>{7});
  cache.clear();

  REQUIRE(best_sum(8, std::vector<uint>{2, 3, 5}, cache).value_or(std::vector<uint>()) == std::vector<uint>{5, 3});
  cache.clear();

  REQUIRE(best_sum(8, std::vector<uint>{1, 4, 5}, cache).value_or(std::vector<uint>()) == std::vector<uint>{4, 4});
  cache.clear();

  REQUIRE(  // should finish fairly quickly
      best_sum(100, std::vector<uint>{1, 2, 5, 25}, cache).value_or(std::vector<uint>()) == std::vector<uint>{25, 25, 25, 25}
  );
}
