include_guard(GLOBAL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SRCS
    game_model.cpp
    game_controller.cpp
    game_view.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} PRIVATE
)

