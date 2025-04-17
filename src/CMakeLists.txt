include_guard(GLOBAL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SRCS
    src.cpp
)

message(STATUS "libs ${LIBS}")

if(BUILD_ROOT_SHARED_LIBS)
    add_library(${PROJECT_NAME}_shared SHARED ${SRCS})
    target_link_libraries(${PROJECT_NAME}_shared PRIVATE
        ${LIBS}
    )
endif()

if(BUILD_ROOT_STATIC_LIBS)
    add_library(${PROJECT_NAME}_static STATIC ${SRCS})
    target_link_libraries(${PROJECT_NAME}_static PRIVATE
        ${LIBS}
    )
endif()
