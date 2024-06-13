#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename F> 
void iter(T *arr, size_t len, F func) {
    if (!arr)
        return ;
    for (size_t i = 0; i < len; i++) {
        func(arr[i]);
    }
}

class Awesome {
public:
    Awesome( void ) : _n( 42 ) { return; } 
    int get( void ) const { return this->_n; } 
    
private: 
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

#endif
