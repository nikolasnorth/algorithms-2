#include "catch.hh"
#include "../src/data-structures/queue/list-queue/ListQueue.cpp"

TEST_CASE("ListQueue: enqueue 3 items then dequeue 3 items") {
  ListQueue<int> q;

  q.enqueue(100);
  q.enqueue(200);
  q.enqueue(300);

  REQUIRE(q.size() == 3);
  REQUIRE(q.peek().value_or(-1) == 100);

  REQUIRE(q.dequeue().value_or(-1) == 100);
  REQUIRE(q.dequeue().value_or(-1) == 200);
  REQUIRE(q.dequeue().value_or(-1) == 300);

  REQUIRE(q.size() == 0);
  REQUIRE(q.peek().has_value() == false);
}
