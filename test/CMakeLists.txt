add_executable(testAdd testAdd.cpp)
target_link_libraries(testAdd
    PRIVATE
        foo
        GTest::gtest
        GTest::gtest_main
)
gtest_discover_tests(testAdd)

