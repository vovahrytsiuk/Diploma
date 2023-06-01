cmake_minimum_required (VERSION 3.19)

project(Diploma LANGUAGES CXX)

set(CMAKE_INSTALL_MESSAGE ALWAYS)
set(TEST_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/test")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (MSVC)
    # warnings
    list(APPEND CXX_FLAGS_LIST
        "/WX"
        "/W4"
    )
else()
    set(CMAKE_SKIP_BUILD_RPATH OFF)
    set(CMAKE_SKIP_INSTALL_RPATH OFF)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH OFF)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/bin")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH OFF)

    # warnings
    list(APPEND CXX_FLAGS_LIST
        "-Werror"
        "-Wall"
        "-Wextra"
        "-Wpedantic"
    )
endif()
foreach(_flag ${CXX_FLAGS_LIST})
    string(APPEND CMAKE_CXX_FLAGS " ${_flag}")
endforeach()

# enable_testing()

add_subdirectory(Components)
add_subdirectory(Projects)