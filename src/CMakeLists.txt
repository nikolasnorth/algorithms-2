project(algorithms_src)
set(SOURCE_FILES
        sorting.cpp
        data-structures/linked-list/LinkedList.h
        data-structures/linked-list/LinkedList.cpp
        data-structures/stack/array-stack/ArrayStack.h
        data-structures/stack/array-stack/ArrayStack.cpp
        data-structures/stack/list-stack/ListStack.h
        data-structures/stack/list-stack/ListStack.cpp
        )
add_library(algorithms_src ${SOURCE_FILES})
