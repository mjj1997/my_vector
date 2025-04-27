find_package(GTest CONFIG REQUIRED)

set(TEST_SRCS
    test.cpp
    test_iterator.cpp
)

add_executable(MyVectorUnitTest
    ${TEST_SRCS}
)

target_link_libraries(MyVectorUnitTest PRIVATE
    GTest::gtest
    ${PROJECT_NAME}_static
)
