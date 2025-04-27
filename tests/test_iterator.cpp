#include "include/MyVector.h"

#include <gtest/gtest.h>

TEST(MyVectorIteratrTest, BeginIterator)
{
    myvector::MyVector v(5, 123);
    auto itr{ v.begin() };
    EXPECT_EQ(*itr, v[0]);
}
