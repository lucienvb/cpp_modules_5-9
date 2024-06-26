#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

class SpanIsFullException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Span is full");
        }
};

class NoSpanFoundException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("No Span found");
        }
};

class LimitException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Number exceeds limit");
        }
};

class Span {
public:
    Span(uint N);
    Span(const Span &obj);
    Span &operator=(const Span &obj);
    ~Span();

    void addNumber(long long number);
    void addNumbers(long long begin, long long end);
    long long shortestSpan();
    long long longestSpan();


private:
    std::vector<int>    _numbers;
    uint        _max_size;

};

#endif