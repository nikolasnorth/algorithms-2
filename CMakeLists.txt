cmake_minimum_required(VERSION 3.19)
project(algorithms)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dist)

set(LinkedList src/data-structures/linked-list)
add_executable(test_linked_list ${LinkedList}/test.cpp ${LinkedList}/LinkedList.cpp ${LinkedList}/LinkedList.h)

set(Sorting src/sorting)
add_executable(test_sorting ${Sorting}/test.cpp ${Sorting}/sorting.cpp)
