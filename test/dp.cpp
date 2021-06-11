#include "catch.hh"
#include "../src/dp.cpp"

TEST_CASE("naive fib()") {
  REQUIRE(fib(6) == 8);
  REQUIRE(fib(7) == 13);
  REQUIRE(fib(8) == 21);
}

TEST_CASE("memoization fib()") {
  std::unordered_map<int32_t, int64_t> memo;

  REQUIRE(fib(6, memo) == 8);

  memo.clear();
  REQUIRE(fib(7, memo) == 13);

  memo.clear();
  REQUIRE(fib(8, memo) == 21);

  memo.clear();
  REQUIRE(fib(50, memo) == 12586269025);  // should finish fairly quickly
}
