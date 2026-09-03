#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

void incrementInt(int& num)
{
    num++;
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(int);

    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    ::iter(intArray, intLen, incrementInt);
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::string stringArray[] = {"Hello", "world", "from", "C++98"};
    size_t stringLen = sizeof(stringArray) / sizeof(std::string);

    ::iter(stringArray, stringLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
