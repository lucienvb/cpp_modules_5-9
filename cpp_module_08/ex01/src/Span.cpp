#include "../include/Span.hpp"
#include "limits.h"

Span::Span(unsigned int N): _max_size(N) {}

Span::~Span() {}

void    Span::addNumber(int number) {
    if (_numbers.size() >= _max_size)
        throw SpanIsFullException();
    _numbers.push_back(number);
}

int    Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw NoSpanFoundException();
    int span = INT_MAX;
    unsigned int size = _numbers.size();
    for (unsigned int i = 0; i < size - 1; i++) {
        int current = _numbers[i+1] - _numbers[i];
        if (current < span && current >= 0)
            span = current;
    }
    return span;
}

