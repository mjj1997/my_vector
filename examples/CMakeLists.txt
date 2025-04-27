add_executable(MyVectorExample
    basic_example.cpp
)

target_link_libraries(MyVectorExample PRIVATE
    ${PROJECT_NAME}_static
)

add_executable(MyVectorIteratorExample
    iterator_example.cpp
)

target_link_libraries(MyVectorIteratorExample PRIVATE
    ${PROJECT_NAME}_static
)

