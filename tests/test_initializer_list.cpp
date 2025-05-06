#include "include/MyVector.h"

#include <gtest/gtest.h>

TEST(MyVectorInitializerListTest, EmptyList)
{
    myvector::MyVector<int> v{};
    EXPECT_EQ(v.size(), 0);
}

TEST(MyVectorInitializerListTest, SingleElementList)
{
    myvector::MyVector<int> v{ 42 };
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 42);
}

TEST(MyVectorInitializerListTest, MultipleElementsList)
{
    myvector::MyVector<int> v{ 1, 2, 3 };
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST(MyVectorInitializerListTest, StringElements)
{
    myvector::MyVector<std::string> v{ "apple", "banana", "cherry" };
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], "apple");
    EXPECT_EQ(v[1], "banana");
    EXPECT_EQ(v[2], "cherry");
}
