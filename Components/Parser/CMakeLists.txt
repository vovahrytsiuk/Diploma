project(Parser LANGUAGES CXX)

set(INCLUDE_PREFIX "include/Parser")
set(HEADERS
    ${INCLUDE_PREFIX}/Error.h
    ${INCLUDE_PREFIX}/Parser.h
)

set(INCLUDE_TARGET ${PROJECT_NAME}.Include)
add_library(${INCLUDE_TARGET} INTERFACE ${HEADERS})

target_include_directories(${INCLUDE_TARGET} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${INCLUDE_TARGET}
    INTERFACE
        Params.Static
)

set(SOURCES_PREFIX "src")
set(SOURCES
    ${SOURCES_PREFIX}/Error.cpp
    ${SOURCES_PREFIX}/Parser.cpp
)

set(STATIC_TARGET ${PROJECT_NAME}.Static)
add_library(${STATIC_TARGET} STATIC
    ${SOURCES}
)

target_link_libraries(${STATIC_TARGET}
    PUBLIC
        ${INCLUDE_TARGET}
)