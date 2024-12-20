add_executable(test_dub_ll test_dub_ll.c)
target_link_libraries(test_dub_ll doubly_linked_list)
add_test(NAME TestDoubleLL COMMAND test_dub_ll)
