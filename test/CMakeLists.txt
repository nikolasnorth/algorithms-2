project(algorithms_test)
set(SOURCE_FILES
        main.cpp
        sorting_test.cpp
        dp_test.cpp
        data-structures/linked-list/LinkedListTest.cpp
        data-structures/stack/ArrayStackTest.cpp
        data-structures/stack/ListStackTest.cpp
        data-structures/queue/ArrayQueueTest.cpp
        data-structures/queue/ListQueueTest.cpp
        data-structures/array/StaticArrayTest.cpp
        data-structures/array/DynamicArrayTest.cpp
        data-structures/hashmap/HashMapTest.cpp
        )
add_executable(algorithms_test ${SOURCE_FILES})

set(LINKED_LIST_SOURCE main.cpp data-structures/linked-list/LinkedListTest.cpp)
add_executable(LinkedListTest ${LINKED_LIST_SOURCE})

set(DP_SOURCE main.cpp dp_test.cpp)
add_executable(DPTest ${DP_SOURCE})

target_link_libraries(algorithms_test algorithms_src)
