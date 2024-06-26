#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

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

class Span {
public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int number);
    int shortestSpan();
    unsigned int    longestSpan();


private:
    std::vector<int>    _numbers;
    unsigned int        _max_size;

};

#endif