#include "include/MyVector.h"

#include <gtest/gtest.h>

TEST(MyVectorTest, EmptyVector)
{
    myvector::MyVector<int> v;

    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

TEST(MyVectorTest, PushBack)
{
    myvector::MyVector<int> v;
    for (int i{ 0 }; i < 10; ++i) {
        v.push_back(i);
    }

    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v.capacity(), 10);
}

TEST(MyVectorTest, Clear)
{
    myvector::MyVector<int> v;
    v.push_back(1);
    v.clear();

    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

TEST(MyVectorTest, LargeCapacity)
{
    myvector::MyVector<int> v;

    const int n{ 100000 };
    for (int i{ 0 }; i < n; ++i) {
        v.push_back(i);
    }

    EXPECT_EQ(v.size(), n);
    EXPECT_GE(v.capacity(), n);

    for (int i{ 0 }; i < n; i++) {
        EXPECT_EQ(v[i], i);
    }
}

TEST(MyVectorTest, NegativeN)
{
    try {
        myvector::MyVector<int> v(-1, 0);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(MyVectorTest, ReserveSmaller)
{
    myvector::MyVector<int> v(10, 0);
    v.reserve(5);
    EXPECT_EQ(v.capacity(), 10);
}

TEST(MyVectorTest, ManualReserve)
{
    myvector::MyVector<int> v;
    v.reserve(20);
    EXPECT_EQ(v.capacity(), 20);
}

TEST(MyVectorTest, ZeroSizeConstructor)
{
    myvector::MyVector<int> v(0, 0);
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

TEST(MyVectorTest, AutoResizing)
{
    myvector::MyVector<int> v;
    v.push_back(0);

    for (int i{ 0 }; i < 9; ++i) {
        v.push_back(i);
    }

    v.push_back(10);
    EXPECT_EQ(v.size(), 11);
    EXPECT_EQ(v.capacity(), 20);
}

TEST(MyVectorTest, ClearThenFill)
{
    myvector::MyVector<int> v;
    v.push_back(1);
    v.clear();
    v.push_back(2);

    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v.capacity(), 10);
}

TEST(MyVectorTest, CopyConstructor)
{
    myvector::MyVector<int> originalVec(5, 10);
    myvector::MyVector<int> otherVec(originalVec);

    EXPECT_EQ(originalVec.size(), otherVec.size());
    EXPECT_EQ(originalVec.capacity(), otherVec.capacity());

    for (size_t i{ 0 }; i < originalVec.size(); ++i) {
        EXPECT_EQ(originalVec[i], otherVec[i]);
    }

    otherVec[0] = 20;
    EXPECT_EQ(originalVec[0], 10);
}

TEST(MyVectorTest, CopyAssignment)
{
    myvector::MyVector<int> v1(3, 1);
    myvector::MyVector<int> v2(5, 2);
    v1 = v2;
    EXPECT_EQ(v1.capacity(), 5);

    EXPECT_EQ(v1.size(), v2.size());
    EXPECT_EQ(v1.capacity(), v2.capacity());
    for (size_t i{ 0 }; i < v1.size(); ++i) {
        EXPECT_EQ(v1[i], v2[i]);
    }

    v1[0] = 3;
    EXPECT_EQ(v2[0], 2);
}

TEST(MyVectorTest, SelfAssignment)
{
    myvector::MyVector<int> v;
    v.push_back(1);
    v = v;
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 1);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
