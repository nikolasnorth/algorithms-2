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
        )
add_executable(algorithms_test ${SOURCE_FILES})
target_link_libraries(algorithms_test algorithms_src)
