#include "iter.hpp"
#include <iostream>
#include <string>

// A simple function template that prints any type
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// A simple function that modifies an integer
void incrementInt(int& num) {
    num++;
}

int main() {
    std::cout << "--- Testing Array of Ints ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(int);

    // Call iter with a printing function
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    // Call iter with a modifying function
    ::iter(intArray, intLen, incrementInt);
    ::iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "\n--- Testing Array of Strings ---" << std::endl;
    std::string stringArray[] = {"Hello", "world", "from", "C++98"};
    size_t stringLen = sizeof(stringArray) / sizeof(std::string);

    ::iter(stringArray, stringLen, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
