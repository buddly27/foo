add_library(foo
    foo/add.cpp
)

target_include_directories(foo
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS foo EXPORT ${PROJECT_NAME})
install(
    DIRECTORY
        foo
    DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

install(EXPORT ${PROJECT_NAME}
    FILE foo-targets.cmake
    NAMESPACE foo::
    DESTINATION share/cmake/foo
)

