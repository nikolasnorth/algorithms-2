#include "catch.hh"
#include "../src/data-structures/array/static-array/StaticArray.cpp"

TEST_CASE("StaticArray::insert(), StaticArray::operator[]") {
  StaticArray<int, 4> a;

  REQUIRE_THROWS_AS(a[-1], std::out_of_range);
  REQUIRE_THROWS_AS(a[4], std::out_of_range);

  a.insert(0, 10);
  a.insert(1, 11);
  a[2] = 12;
  a[3] = 13;

  REQUIRE(a[0] == 10);
  REQUIRE(a[1] == 11);
  REQUIRE(a[2] == 12);
  REQUIRE(a[3] == 13);
}
