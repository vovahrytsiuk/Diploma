project(UI LANGUAGES CXX)

set(INCLUDE_PREFIX "include/UI")
set(HEADERS
    ${INCLUDE_PREFIX}/Window.h
)

set(INCLUDE_TARGET ${PROJECT_NAME}.Include)
add_library(${INCLUDE_TARGET} INTERFACE ${HEADERS})

target_include_directories(${INCLUDE_TARGET} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES_PREFIX "src")
set(SOURCES
    ${SOURCES_PREFIX}/Window.cpp
)

set(STATIC_TARGET ${PROJECT_NAME}.Static)
add_library(${STATIC_TARGET} STATIC
    ${SOURCES}
)

target_link_libraries(${STATIC_TARGET}
    PUBLIC
        ${INCLUDE_TARGET}
    PRIVATE
        Markup.Static
)

add_link_options(
    /SUBSYSTEM:WINDOWS
    /DYNAMICBASE 
    Version.lib
    Comctl32.lib
    /MACHINE:X64
)

# add_subdirectory(UI.Test)