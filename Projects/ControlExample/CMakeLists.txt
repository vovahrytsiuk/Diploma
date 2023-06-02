cmake_minimum_required (VERSION 3.19)

project(ControlExample LANGUAGES CXX)

set(EXECUTABLE_TARGET ${PROJECT_NAME})

set(EXECUTABLE_SOURCES
    Application.cpp
    Application.h
    main.cpp
)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
add_executable(${EXECUTABLE_TARGET} ${EXECUTABLE_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)

target_link_libraries(${EXECUTABLE_TARGET}
    PRIVATE
        UI.Static
)


if(MSVC)
    target_compile_options(${EXECUTABLE_TARGET} PRIVATE /EHsc)
endif()


install(TARGETS ${EXECUTABLE_TARGET})
