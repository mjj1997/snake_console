add_executable(ROOT_EXAMPLE_NAME
    example.cpp
)

target_link_libraries(ROOT_EXAMPLE_NAME PRIVATE
    ${PROJECT_NAME}_static
)

