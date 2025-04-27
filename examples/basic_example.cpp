#include "include/MyVector.h"

#include <iostream>

int main(int argc, char* argv[])
{
    myvector::MyVector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (size_t i{ 0 }; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
