#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>
#include <iterator>

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
    template<typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
    int shortestSpan();
    int longestSpan();


private:
    std::vector<int>    _numbers;
    unsigned int        _max_size;

};

#endif