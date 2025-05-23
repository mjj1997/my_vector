#pragma once

#include <cstddef>

namespace myvector {

class MyVector
{
public:
    MyVector();
    MyVector(int n, int value);
    ~MyVector();

    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& rhs);

    size_t size() const;
    size_t capacity() const;
    bool empty() const;

    //只读元素
    const int& operator[](size_t n) const;
    //写入元素
    int& operator[](size_t n);

    void reserve(size_t newCapacity);
    void push_back(int value);
    void clear();

    class iterator
    {
    public:
        iterator(int* ptr);

        int& operator*();
        iterator& operator++();

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

    private:
        friend class MyVector;

        int* m_ptr{ nullptr };
    };

    class const_iterator
    {
    public:
        const_iterator(int* ptr);

        const int& operator*() const;
        const_iterator& operator++();

        bool operator==(const const_iterator& rhs) const;
        bool operator!=(const const_iterator& rhs) const;

    private:
        friend class MyVector;

        const int* m_ptr{ nullptr };
    };

    iterator begin() noexcept;
    iterator end() noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator cend() const noexcept;

private:
    int* m_data{ nullptr };
    size_t m_size{ 0 };
    size_t m_capacity{ 0 };
};

} // namespace myvector
