include_guard(GLOBAL)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SRCS
    MyVector.cpp
)

if(BUILD_MYVECTOR_SHARED_LIBS)
    add_library(${PROJECT_NAME}_shared SHARED ${SRCS})
    target_link_libraries(${PROJECT_NAME}_shared PRIVATE

    )
endif()

if(BUILD_MYVECTOR_STATIC_LIBS)
    add_library(${PROJECT_NAME}_static STATIC ${SRCS})
    target_link_libraries(${PROJECT_NAME}_static PRIVATE

    )
endif()
