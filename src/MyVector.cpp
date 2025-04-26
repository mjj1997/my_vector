#include "include/MyVector.h"

#include <algorithm>

namespace myvector {

MyVector::MyVector() {}

MyVector::MyVector(int n, int value)
{
    for (int i{ 0 }; i < n; ++i) {
        push_back(value);
    }
}

MyVector::MyVector(const MyVector& other)
{
    m_data = new int[other.m_capacity];
    m_size = other.m_size;
    m_capacity = other.m_capacity;

    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

MyVector& MyVector::operator=(const MyVector& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    clear();

    m_data = new int[rhs.m_capacity];
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;

    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);

    return *this;
}

MyVector::~MyVector()
{
    delete[] m_data;
}

size_t MyVector::size() const
{
    return m_size;
}

void MyVector::push_back(int value)
{
    //1 如果capacity为0，则一次性开辟10个元素
    //2 如果capacity容量没有用完 追加到最后
    //3 如果capacity容量已经用完，开辟两倍capacity大小的容量，拷贝老数据，追加新数据
    if (m_capacity == 0) {
        reserve(10);
        m_data[0] = value;
        ++m_size;
    } else if (m_size < m_capacity) {
        //给最后一个元素的后面赋值为新元素value
        //增加元素数量
        m_data[m_size] = value;
        ++m_size;
    } else {
        //每次内存不够用就翻倍
        reserve(2 * m_capacity);

        m_data[m_size] = value;
        ++m_size;
    }
}

const int& MyVector::operator[](size_t n) const
{
    return m_data[n];
}

int& MyVector::operator[](size_t n)
{
    return m_data[n];
}

bool MyVector::empty() const
{
    return m_size == 0;
}

void MyVector::clear()
{
    if (m_capacity == 0) {
        return;
    } else {
        delete[] m_data;
        m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
}

void MyVector::reserve(size_t newCapacity)
{
    if (newCapacity <= m_capacity)
        return;

    int* newData{ new int[newCapacity] };
    std::copy(m_data, m_data + m_size, newData);
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

} // namespace myvector
