#pragma once

#include <algorithm>
#include <cstddef>
#include <stdexcept>

namespace myvector {

template<typename T>
class MyVector
{
public:
    MyVector() {}
    MyVector(int n, const T& value);

    ~MyVector() { delete[] m_data; }

    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& rhs);

    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }
    bool empty() const { return m_size == 0; }

    //只读元素
    const T& operator[](size_t n) const { return m_data[n]; }
    //写入元素
    T& operator[](size_t n) { return m_data[n]; }

    void reserve(size_t newCapacity);
    void push_back(const T& value);
    void clear();

    class iterator;
    class const_iterator;

    iterator begin() noexcept { return iterator{ m_data }; }
    iterator end() noexcept { return iterator{ m_data + m_size }; }
    const_iterator cbegin() const noexcept { return const_iterator{ m_data }; }
    const_iterator cend() const noexcept { return const_iterator{ m_data + m_size }; }

private:
    T* m_data{ nullptr };
    size_t m_size{ 0 };
    size_t m_capacity{ 0 };
};

template<typename T>
MyVector<T>::MyVector(int n, const T& value)
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

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
    : m_data{ new T[other.m_capacity] }
    , m_size{ other.m_size }
    , m_capacity{ other.m_capacity }
{
    std::copy(other.m_data, other.m_data + other.m_size, m_data);
}

template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& rhs)
{
    if (&rhs == this) {
        return *this;
    }

    clear();

    m_data = new T[rhs.m_capacity];
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;

    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);

    return *this;
}

template<typename T>
void MyVector<T>::reserve(size_t newCapacity)
{
    if (newCapacity <= m_capacity)
        return;

    int* newData{ new T[newCapacity] };
    std::copy(m_data, m_data + m_size, newData);
    delete[] m_data;
    m_data = newData;
    m_capacity = newCapacity;
}

template<typename T>
void MyVector<T>::push_back(const T& value)
{
    if (m_size == m_capacity) {
        size_t newCapacity{ m_capacity == 0 ? 10 : m_capacity * 2 };
        reserve(newCapacity);
    }

    m_data[m_size] = value;
    ++m_size;
}
template<typename T>
void MyVector<T>::clear()
{
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
class MyVector<T>::iterator
{
public:
    iterator(T* ptr)
        : m_ptr{ ptr }
    {}

    T& operator*() { return *m_ptr; }
    iterator& operator++()
    {
        ++m_ptr;
        return *this;
    }

    bool operator==(const iterator& rhs) const { return m_ptr == rhs.m_ptr; }
    bool operator!=(const iterator& rhs) const { return m_ptr != rhs.m_ptr; }

private:
    friend class MyVector;

    T* m_ptr{ nullptr };
};

template<typename T>
class MyVector<T>::const_iterator
{
public:
    const_iterator(const T* ptr)
        : m_ptr{ ptr }
    {}

    const T& operator*() const { return *m_ptr; }
    const_iterator& operator++()
    {
        ++m_ptr;
        return *this;
    }

    bool operator==(const const_iterator& rhs) const { return m_ptr == rhs.m_ptr; }
    bool operator!=(const const_iterator& rhs) const { return m_ptr != rhs.m_ptr; }

private:
    friend class MyVector;

    const T* m_ptr{ nullptr };
};

} // namespace myvector
