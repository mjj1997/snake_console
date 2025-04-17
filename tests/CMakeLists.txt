find_package(GTest CONFIG REQUIRED)

set(TEST_SRCS
    test.cpp
)

add_executable(ROOT_UNIT_TEST
    ${TEST_SRCS}
)

target_link_libraries(ROOT_UNIT_TEST PRIVATE
    GTest::gtest
    ${PROJECT_NAME}_static
)
