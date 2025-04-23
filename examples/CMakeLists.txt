add_executable(MyVectorExample
    example.cpp
)

target_link_libraries(MyVectorExample PRIVATE
    ${PROJECT_NAME}_static
)

