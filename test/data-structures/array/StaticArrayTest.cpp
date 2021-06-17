#include "catch.hh"
#include "../src/data-structures/array/static-array/StaticArray.cpp"

TEST_CASE("StaticArray::insert() and StaticArray::get()") {
  StaticArray<int, 3> a;

  REQUIRE_THROWS_AS(a[-1], std::out_of_range);
  REQUIRE_THROWS_AS(a[3], std::out_of_range);

  REQUIRE(a.size() == 0);

  a.insert(0, 10);
  a.insert(1, 11);
  a.insert(2, 12);

  REQUIRE(a.size() == 3);

  REQUIRE(a[0] == 10);
  REQUIRE(a[1] == 11);
  REQUIRE(a[2] == 12);
}
