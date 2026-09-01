#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;

public:
    // TODO: Default constructor (empty array)
    Array();

    // TODO: Parametrized constructor (array of size n)
    Array(unsigned int n);

    // TODO: Copy constructor
    Array(const Array& src);

    // TODO: Assignment operator
    Array& operator=(const Array& rhs);

    // TODO: Destructor
    ~Array();

    // TODO: Overload subscript operator[] (for non-const and const)
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    // TODO: size() function
    unsigned int size() const;

    // Exception class for out of bounds
    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

// Include the template implementation file at the very bottom!
// This is the magic behind .tpp files.
#include "Array.tpp"

#endif
