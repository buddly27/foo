cmake_minimum_required(VERSION 3.22)

project(foo
    VERSION 0.1.0
    LANGUAGES CXX
)

include(GNUInstallDirs)

if (NOT ${CMAKE_CXX_STANDARD})
    set(CMAKE_CXX_STANDARD 14 CACHE STRING "Default C++ standard")
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_SHARED_LIBS "Build Shared Library" ON)

add_subdirectory(src)

if (BUILD_TESTS)
    find_package(GTest 1.8.0 REQUIRED)
    include(GoogleTest)
    enable_testing()

    add_subdirectory(test)
endif()

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "cmake/foo-config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/foo-config.cmake"
    INSTALL_DESTINATION share/cmake/test
)

write_basic_package_version_file(
    "foo-config-version.cmake"
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/foo-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/foo-config-version.cmake"
    DESTINATION share/cmake/test
)
