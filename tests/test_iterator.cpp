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

TEST(MyVectorIteratrTest, ConstBeginIterator)
{
    myvector::MyVector v(5, 123);
    auto citr{ v.cbegin() };
    EXPECT_EQ(*citr, v[0]);
}

TEST(MyVectorIteratrTest, ConstEndIterator)
{
    myvector::MyVector v(5, 123);
    auto cendItr{ v.cend() };
    EXPECT_EQ(cendItr, &v[0] + v.size());
}

TEST(MyVectorIteratrTest, ConstIncrementOperator)
{
    myvector::MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    auto citr{ v.cbegin() };

    ++citr;
    EXPECT_EQ(*citr, v[1]);

    ++citr;
    EXPECT_EQ(*citr, v[2]);

    while (citr != v.cend()) {
        ++citr;
    }
    EXPECT_EQ(citr, v.cend());
}

TEST(MyVectorIteratrTest, ConstTraverseAllElements)
{
    myvector::MyVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    auto citr{ v.cbegin() };
    int count{ 0 };

    while (citr != v.cend()) {
        if (count == 0)
            EXPECT_EQ(*citr, 10);
        else if (count == 1)
            EXPECT_EQ(*citr, 20);
        else if (count == 2)
            EXPECT_EQ(*citr, 30);
        else if (count == 3)
            EXPECT_EQ(*citr, 40);

        ++citr;
        ++count;
    }

    EXPECT_EQ(count, v.size());
}
