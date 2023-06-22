project(Params LANGUAGES CXX)

set(INCLUDE_PREFIX "include/Params")
set(HEADERS
    ${INCLUDE_PREFIX}/Button.h
    ${INCLUDE_PREFIX}/CheckBox.h
    ${INCLUDE_PREFIX}/EditLine.h
    ${INCLUDE_PREFIX}/Form.h
    ${INCLUDE_PREFIX}/Label.h
    ${INCLUDE_PREFIX}/NumberBox.h
    ${INCLUDE_PREFIX}/RadioButton.h
    ${INCLUDE_PREFIX}/Text.h
)

set(INCLUDE_TARGET ${PROJECT_NAME}.Include)
add_library(${INCLUDE_TARGET} INTERFACE ${HEADERS})

target_include_directories(${INCLUDE_TARGET} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES_PREFIX "src")
set(SOURCES
    ${SOURCES_PREFIX}/Button.cpp
    ${SOURCES_PREFIX}/CheckBox.cpp
    ${SOURCES_PREFIX}/EditLine.cpp
    ${SOURCES_PREFIX}/Form.cpp
    ${SOURCES_PREFIX}/Label.cpp
    ${SOURCES_PREFIX}/NumberBox.cpp
    ${SOURCES_PREFIX}/RadioButton.cpp
    ${SOURCES_PREFIX}/Text.cpp
)

set(STATIC_TARGET ${PROJECT_NAME}.Static)
add_library(${STATIC_TARGET} STATIC
    ${SOURCES}
)

if(MSVC)
    target_compile_options(${STATIC_TARGET} PRIVATE /EHsc)
endif()

target_link_libraries(${STATIC_TARGET}
    PUBLIC
        ${INCLUDE_TARGET}
)
