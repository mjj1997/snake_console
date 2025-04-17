find_package(GTest CONFIG REQUIRED)

set(TEST_SRCS
    test.cpp
)

add_executable(SnakeUnitTest
    ${TEST_SRCS}
)

target_link_libraries(SnakeUnitTest PRIVATE
    GTest::gtest
)
