#include "include/MyVector.h"

#include <iostream>

int main(int argc, char* argv[])
{
    myvector::MyVector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (auto it{ v.begin() }; it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    for (const auto& val : v) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    return 0;
}
