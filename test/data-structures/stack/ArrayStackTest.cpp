#include "catch.hh"
#include "../src/data-structures/stack/array-stack/ArrayStack.cpp"

TEST_CASE("push then pop 3 items") {
  ArrayStack<int> stack;

  stack.push(100);
  stack.push(200);
  stack.push(300);

  REQUIRE(stack.size() == 3);
  REQUIRE(stack.peek().value_or(-1) == 300);

  REQUIRE(stack.pop().value_or(-1) == 300);
  REQUIRE(stack.pop().value_or(-1) == 200);
  REQUIRE(stack.pop().value_or(-1) == 100);

  REQUIRE(stack.size() == 0);
  REQUIRE(stack.peek().has_value() == false);
}
