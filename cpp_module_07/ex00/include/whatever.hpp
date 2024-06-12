#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T &first, T &second) {
    T temp = first;
    first = second;
    second = temp;
}

template <typename T> T min(T first, T second) {
    if (first < second)
        return first;
    else
        return second;
}

template <typename T> T max(T first, T second) {
    if (first > second)
        return first;
    else
        return second;
}

class Awesome {
public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome(const Awesome& a) : _n(a._n) {}
    Awesome &operator=(Awesome & a) { _n = a._n; return *this; } 
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); } 
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); } 
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); } 
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); } 
    bool operator<=( Awesome const & rhs ) const {return (this->_n <= rhs._n); } 
    int get_n() const { return _n; } 

private: 
    int _n; 
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

#endif