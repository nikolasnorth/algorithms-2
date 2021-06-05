project(algorithms_test)
set(SOURCE_FILES
        main.cpp
        sorting_test.cpp
        data-structures/LinkedListTest.cpp
        data-structures/ArrayStackTest.cpp
        )
add_executable(algorithms_test ${SOURCE_FILES})
target_link_libraries(algorithms_test algorithms_src)
