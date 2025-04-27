#include "include/MyVector.h"

#include <algorithm>
#include <stdexcept>

namespace myvector {

MyVector::MyVector() {}

MyVector::MyVector(int n, int value)
{
    if (n < 0) {
        throw std::invalid_argument{ "n cannot be negative" };
    }

    reserve(n);

    for (int i{ 0 }; i < n; ++i) {
        m_data[i] = value;
    }

    m_size = n;
}

MyVector::MyVector(const MyVector& other)
    : m_data{ new int[other.m_capacity] }
    , m_size{ other.m_size }
    , m_capacity{ other.m_capacity }
{
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
    if (m_size == m_capacity) {
        size_t newCapacity{ m_capacity == 0 ? 10 : m_capacity * 2 };
        reserve(newCapacity);
    }

    m_data[m_size] = value;
    ++m_size;
}

const int& MyVector::operator[](size_t n) const
{
    return m_data[n];
}

int& MyVector::operator[](size_t n)
{
    return m_data[n];
}

size_t MyVector::capacity() const
{
    return m_capacity;
}

bool MyVector::empty() const
{
    return m_size == 0;
}

void MyVector::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
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

MyVector::iterator::iterator(int* ptr)
    : m_ptr{ ptr }
{}

MyVector::iterator MyVector::begin() noexcept
{
    return MyVector::iterator{ m_data };
}

int& MyVector::iterator::operator*()
{
    return *m_ptr;
}

} // namespace myvector
