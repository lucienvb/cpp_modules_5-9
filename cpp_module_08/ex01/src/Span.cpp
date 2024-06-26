#include "../include/Span.hpp"
#include "limits.h"

Span::Span(unsigned int N): _max_size(N) {}

Span::~Span() {}

void    Span::addNumber(int number) {
    if (_numbers.size() >= _max_size)
        throw SpanIsFullException();
    _numbers.push_back(number);
}

template<typename InputIterator>
void    Span::addNumbers(InputIterator begin, InputIterator end) {
    while (begin != end) {
        if (_numbers.size() >= _max_size) {
            throw SpanIsFullException();
        }
        _numbers.push_back(*begin);
        begin++;
    }
}

int    Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw NoSpanFoundException();
    int span = INT_MAX;
    unsigned int size = _numbers.size();
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = i + 1; j < size; j++) {
            int current = _numbers[j] - _numbers[i];
            if (current < span && current >= 0)
                span = current;
        }
    }
    return span;
}

int    Span::longestSpan() {
    if (_numbers.size() < 2)
        throw NoSpanFoundException();
    int span = 0;
    unsigned int size = _numbers.size();
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = i + 1; j < size; j++) {
            int current = _numbers[j] - _numbers[i];
            if (current > span && current <= INT_MAX)
                span = current;
        }
    }
    return span;
}
