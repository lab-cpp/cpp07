#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T> Array<T>::Array() : _array(new T[0]()), _size(0) {}

template <typename T> Array<T>::Array(unsigned int size) : _array(new T[size]()), _size(size) {}

template <typename T> Array<T>::Array(const Array<T>& src) {
	this->_array = new T[src._size]();
	this->_size = src._size;

	for (unsigned int i = 0; i < src._size; ++i) {
		this->_array[i] = src._array[i];
	}
}

template <typename T> Array<T>& Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		delete[] this->_array;
		this->_array = new T[rhs._size]();
		this->_size = rhs._size;
		for (unsigned int i = 0; i < rhs._size; ++i) {
			this->_array[i] = rhs._array[i];
		}
	}
	return *this;
}

template <typename T> Array<T>::~Array() {
	delete[] _array;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}

template <typename T> T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size) {
		throw Array<T>::OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T> const T& Array<T>::operator[](unsigned int index) const {
	if (index >= this->_size) {
		throw Array<T>::OutOfBoundsException();
	}
	return this->_array[index];
}

template <typename T> unsigned int Array<T>::size() const {
	return this->_size;
}

#endif
