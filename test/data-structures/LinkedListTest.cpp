#include "catch.hh"
#include "../src/data-structures/linked-list/LinkedList.cpp"

TEST_CASE("LinkedList::add()") {
  LinkedList<int> list;

  SECTION("index greater than list size or less than -1 should throw exception") {
    REQUIRE_THROWS_AS(list.add(100, -2), std::out_of_range);
    REQUIRE_THROWS_AS(list.add(100, 1), std::out_of_range);
  }

  SECTION("add to empty list") {
    list.add(100);

    REQUIRE(list.head()->data() == 100);
    REQUIRE(list.tail()->data() == 100);
    REQUIRE(list.size() == 1);
  }

  SECTION("add to beginning of non-empty list") {
    list.add(100, 0);

    REQUIRE(list.head()->data() == 100);
    REQUIRE(list.size() == 1);
  }

  SECTION("add to end of non-empty list") {
    list.add(100);

    REQUIRE(list.tail()->data() == 100);
    REQUIRE(list.size() == 1);
  }

  SECTION("add to middle of non-empty list") {
    list.add(100);
    list.add(300);
    list.add(200, 1);

    REQUIRE(list.get(1)->data() == 200);
    REQUIRE(list.size() == 3);
  }
}

TEST_CASE("LinkedList::remove()") {
  LinkedList<int> list;

  SECTION("index greater than (or equal to) list size, or less than -1 should throw exception") {
    REQUIRE_THROWS_AS(list.remove(-2), std::out_of_range);
    REQUIRE_THROWS_AS(list.remove(0), std::out_of_range);
  }

  SECTION("remove from list with one node") {
    list.add(100);

    auto result = list.remove();

    REQUIRE(result == 100);
    REQUIRE(list.size() == 0);
  }

  SECTION("remove from beginning of non-empty list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.remove(0);

    REQUIRE(result == 100);
    REQUIRE(list.head()->data() == 200);
    REQUIRE(list.size() == 2);
  }

  SECTION("remove from end of non-empty list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.remove();

    REQUIRE(result == 300);
    REQUIRE(list.tail()->data() == 200);
    REQUIRE(list.size() == 2);
  }

  SECTION("remove from middle of non-empty list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.remove(1);

    REQUIRE(result == 200);
    REQUIRE(list.size() == 2);
  }
}

TEST_CASE("LinkedList::update()") {
  LinkedList<int> list;

  SECTION("index greater than (or equal to) list size, or less than 0 should throw exception") {
    REQUIRE_THROWS_AS(list.update(100, 0), std::out_of_range);
    REQUIRE_THROWS_AS(list.update(100, -1), std::out_of_range);
  }

  SECTION("update head node") {
    list.add(100);
    list.add(100);
    list.add(100);

    list.update(200, 0);

    REQUIRE(list.head()->data() == 200);
  }

  SECTION("update tail node") {
    list.add(100);
    list.add(100);
    list.add(100);

    list.update(200, list.size() - 1);

    REQUIRE(list.tail()->data() == 200);
  }

  SECTION("update middle node") {
    list.add(100);
    list.add(100);
    list.add(100);

    list.update(200, 1);

    REQUIRE(list.get(1)->data() == 200);
  }
}

TEST_CASE("LinkedList::find()") {
  LinkedList<int> list;

  SECTION("index greater than (or equal to) list size, or less than 0 should throw exception") {
    REQUIRE_THROWS_AS(list.contains(100, 0), std::out_of_range);
    REQUIRE_THROWS_AS(list.contains(100, -1), std::out_of_range);
  }

  SECTION("data not in list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.contains(500);

    REQUIRE(result == false);
  }

  SECTION("data is in list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.contains(200);

    REQUIRE(result == true);
  }

  SECTION("data is in list, however not from starting index") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.contains(100, 1);

    REQUIRE(result == false);
  }

  SECTION("data is in list, and found from starting position greater than 0") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.contains(300, 1);

    REQUIRE(result == true);
  }
}

TEST_CASE("LinkedList::index_of()") {
  LinkedList<int> list;

  SECTION("index greater than (or equal to) list size, or less than 0 should throw exception") {
    REQUIRE_THROWS_AS(list.index_of(100, 0), std::out_of_range);
    REQUIRE_THROWS_AS(list.index_of(100, -1), std::out_of_range);
  }

  SECTION("data is not in list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.index_of(500);

    REQUIRE(result == -1);
  }

  SECTION("data is in list") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.index_of(200);

    REQUIRE(result == 1);
  }

  SECTION("data is in list, however not from starting index") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.index_of(100, 1);

    REQUIRE(result == -1);
  }

  SECTION("data is in list, and found from starting position greater than 0") {
    list.add(100);
    list.add(200);
    list.add(300);

    auto result = list.index_of(300, 1);

    REQUIRE(result == 2);
  }
}
