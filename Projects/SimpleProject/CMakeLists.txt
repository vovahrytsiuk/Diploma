cmake_minimum_required (VERSION 3.22)

project(SimpleProject LANGUAGES CXX)

set(EXECUTABLE_TARGET ${PROJECT_NAME})

set(EXECUTABLE_SOURCES
    main.cpp
)

add_executable(${EXECUTABLE_TARGET} ${EXECUTABLE_SOURCES})

target_link_libraries(${EXECUTABLE_TARGET}
    PRIVATE
        UI.Static
)

install(TARGETS ${EXECUTABLE_TARGET})

# add_subdirectory(xcp2mdf.Test)
