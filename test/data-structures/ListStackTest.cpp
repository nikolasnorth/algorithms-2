#include "catch.hh"
#include "../src/data-structures/stack/list-stack/ListStack.cpp"

TEST_CASE("enqueue then dequeue 3 items") {
  ListStack<int> stack;

  stack.enqueue(100);
  stack.enqueue(200);
  stack.enqueue(300);

  REQUIRE(stack.size() == 3);
  REQUIRE(stack.peek().value_or(-1) == 100);

  REQUIRE(stack.dequeue().value_or(-1) == 100);
  REQUIRE(stack.dequeue().value_or(-1) == 200);
  REQUIRE(stack.dequeue().value_or(-1) == 300);

  REQUIRE(stack.size() == 0);
  REQUIRE(stack.peek().has_value() == false);
}
