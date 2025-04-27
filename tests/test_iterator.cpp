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

TEST(MyVectorIteratrTest, IncrementOperator)
{
    myvector::MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    auto itr{ v.begin() };

    ++itr;
    EXPECT_EQ(*itr, v[1]);

    ++itr;
    EXPECT_EQ(*itr, v[2]);

    while (itr != v.end()) {
        ++itr;
    }
    EXPECT_EQ(itr, v.end());
}

TEST(MyVectorIteratrTest, TraverseAllElements)
{
    myvector::MyVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    auto itr{ v.begin() };
    int count{ 0 };

    while (itr != v.end()) {
        if (count == 0)
            EXPECT_EQ(*itr, 10);
        else if (count == 1)
            EXPECT_EQ(*itr, 20);
        else if (count == 2)
            EXPECT_EQ(*itr, 30);
        else if (count == 3)
            EXPECT_EQ(*itr, 40);

        ++itr;
        ++count;
    }

    EXPECT_EQ(count, v.size());
}

