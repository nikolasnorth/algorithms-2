#include "catch.hh"
#include "../src/dp.cpp"

TEST_CASE("naive fib()") {
  REQUIRE(fib(6) == 8);
  REQUIRE(fib(7) == 13);
  REQUIRE(fib(8) == 21);
  REQUIRE(fib(50) == 12586269025);  // should finish fairly quickly
}
