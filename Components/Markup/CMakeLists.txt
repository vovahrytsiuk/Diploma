project(Markup LANGUAGES CXX)

set(INCLUDE_PREFIX "include/Markup")
set(HEADERS
    ${INCLUDE_PREFIX}/Markup.h
)

set(INCLUDE_TARGET ${PROJECT_NAME}.Include)
add_library(${INCLUDE_TARGET} INTERFACE ${HEADERS})

target_include_directories(${INCLUDE_TARGET} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES_PREFIX "src")
set(SOURCES
    ${SOURCES_PREFIX}/Markup.cpp
)

set(STATIC_TARGET ${PROJECT_NAME}.Static)
add_library(${STATIC_TARGET} STATIC
    ${SOURCES}
)

target_link_libraries(${STATIC_TARGET}
    PUBLIC
        ${INCLUDE_TARGET}
    # PRIVATE
)