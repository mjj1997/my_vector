#include "include/MyVector.h"

#include <gtest/gtest.h>

TEST(MyVectorIteratrTest, BeginIterator)
{
    myvector::MyVector v(5, 123);
    auto itr{ v.begin() };
    EXPECT_EQ(*itr, v[0]);
}

TEST(MyVectorIteratrTest, EndIterator)
{
    myvector::MyVector v(5, 123);
    auto endItr{ v.end() };
    EXPECT_EQ(endItr, &v[0] + v.size());
}

