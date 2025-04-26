#include "include/MyVector.h"

#include <exception>
#include <gtest/gtest.h>

void print(myvector::MyVector& v, const char* msg)
{
    std::cout << "The contents of " << msg << " are:";
    for (int i{ 0 }; i != v.size(); ++i) {
        std::cout << ' ' << v[i];
    }
    std::cout << '\n';
}

TEST(MyVectorTest, Test1)
{
    myvector::MyVector v;
    EXPECT_EQ(v.size(), 0);

    for (int i{ 0 }; i < 10; ++i) {
        v.push_back(i);
    }
    print(v, "v");
    EXPECT_EQ(v.size(), 10);

    for (int i{ 0 }; i < 10; ++i) {
        EXPECT_EQ(v[i], i);
    }

    v.clear();
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
}

TEST(MyVectorTest, Test2)
{
    myvector::MyVector v;

    int n{ 100000 };
    for (int i{ 0 }; i < n; ++i) {
        v.push_back(i);
    }
    EXPECT_EQ(v.size(), n);

    for (int i{ 0 }; i < n; i++) {
        EXPECT_EQ(v[i], i);
    }

    v.clear();
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
}

TEST(MyVectorTest, Test3)
{
    myvector::MyVector v1;
    EXPECT_TRUE(v1.empty());
    EXPECT_EQ(v1.size(), 0);

    myvector::MyVector v2(4, 100);
    EXPECT_FALSE(v2.empty());
    EXPECT_EQ(v2.size(), 4);

    myvector::MyVector v3(v2);
    EXPECT_FALSE(v3.empty());
    EXPECT_EQ(v3.size(), v2.size());

    v3.clear();
    EXPECT_TRUE(v3.empty());
    EXPECT_EQ(v3.size(), 0);

    v3.push_back(16);
    v3.push_back(2);
    v3.push_back(77);
    v3.push_back(29);
    EXPECT_FALSE(v3.empty());
    EXPECT_EQ(v3[0], 16);
    EXPECT_EQ(v3[3], 29);
    int myInts[] = { 16, 2, 77, 29 };
    EXPECT_EQ(v3.size(), sizeof(myInts) / sizeof(int));
    print(v3, "v3"); //The contents of v3 are:16 2 77 29

    v3.push_back(30);
    EXPECT_EQ(v3[4], 30);
    EXPECT_EQ(v3.size(), 5);
    print(v3, "v3"); //The contents of v3 are:16 2 77 29 30
    EXPECT_EQ(v3.size(), sizeof(myInts) / sizeof(int) + 1);

    v1 = v3;
    print(v1, "v1"); //The contents of first are:16 2 77 29 30
    EXPECT_FALSE(v1.empty());
    EXPECT_EQ(v1.size(), v3.size());
}

TEST(MyVectorTest, Test4)
{
    myvector::MyVector a;
    a.push_back(16);
    a.push_back(2);
    a.push_back(77);
    a.push_back(29);

    {
        myvector::MyVector b(a);
        b.push_back(2);
        EXPECT_EQ(b[4], 2);
        EXPECT_EQ(b[0], 16);
    }

    {
        myvector::MyVector c;
        c = a;
        c[0] = 1;
        EXPECT_EQ(c[0], 1);
    }
}

TEST(MyVectorTest, NegativeN)
{
    try {
        myvector::MyVector v(-1, 0);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
