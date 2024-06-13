#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <stdexcept>
#include <iostream>

template <class T> 
class Array {

public:
    Array(): _size(0), _arr(nullptr) {};
    
	Array(unsigned int n): _size(n), _arr(new T[n]()) {};
    
	Array(const Array &other): _size(other._size), _arr(new T[other._size]()) {
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	};

	Array &operator=(const Array &other) {
		if (this != &other) {
			delete[] _arr;
			_size = other._size;
			_arr = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_arr[i] = other._arr[i];
		}
		return *this;
	};

    ~Array() { delete[] _arr; };

	T& operator[](unsigned int index) {
		if (index >= _size)
			throw std::out_of_range("Index out of bound");
		return _arr[index];
	}

	T& operator[](unsigned int index) const {
		if (index >= _size)
			throw std::out_of_range("Index out of bound");
		return _arr[index];
	}

	unsigned int size() {
		return _size;
	}

private:
    unsigned int	_size; 
    T				*_arr;
};

#endif