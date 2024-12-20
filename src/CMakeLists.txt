
add_library(calculator calculator.c)
add_library(doubly_linked_list doubly_linked_list.c)
add_executable(main main.c)
target_link_libraries(main doubly_linked_list)

