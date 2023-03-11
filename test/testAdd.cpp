#include <foo/add.h>

#include <gtest/gtest.h>

TEST(AddTest, Add)
{
    ASSERT_EQ(add(1, 3), 4);
}

