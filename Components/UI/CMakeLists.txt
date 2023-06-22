project(UI LANGUAGES CXX)

set(WIDGETS_PREFIX "Widgets/")
set(INCLUDE_PREFIX "include/UI")
set(HEADERS
    ${INCLUDE_PREFIX}/BaseApplication.h
    ${INCLUDE_PREFIX}/Window.h
    ${INCLUDE_PREFIX}/Font.h
    ${INCLUDE_PREFIX}/Event.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/Button.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/Label.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/CheckBox.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/IButton.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/FieldEdit.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/SpinBox.h
    ${INCLUDE_PREFIX}/${WIDGETS_PREFIX}/RadioButton.h
    ${INCLUDE_PREFIX}/WindowsParamsMock.h
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
    ${SOURCES_PREFIX}/BaseApplication.cpp
    ${SOURCES_PREFIX}/Window.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/Button.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/Label.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/CheckBox.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/FieldEdit.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/SpinBox.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/IWidget.cpp
    ${SOURCES_PREFIX}/${WIDGETS_PREFIX}/RadioButton.cpp
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
        Comctl32
    PRIVATE
        Params.Static
        Parser.Static
)

add_link_options(
    /SUBSYSTEM:WINDOWS
    /DYNAMICBASE 
    Version.lib
    Comctl32.lib
    /MACHINE:X64
)

# add_subdirectory(UI.Test)x

