#include "../include/Span.hpp"
#include "limits"

Span::Span() {}

Span::Span(uint N): _max_size(N) {}

Span::Span(const Span &obj){
	if (this != &obj){
		*this = obj;
	}
}

Span& Span::operator=(const Span &obj){
	if (this != &obj){
		this->_max_size = obj._max_size;
		this->_numbers = obj._numbers;
	}
	return (*this);
}

Span::~Span() {}

void    Span::addNumber(long long number) {
    if (_numbers.size() >= _max_size)
        throw SpanIsFullException();
    _numbers.push_back(number);
}

void    Span::addNumbers(long long begin, long long end) {
    while (begin != end) {
        if (_numbers.size() >= _max_size) {
            throw SpanIsFullException();
        }
        _numbers.push_back(begin);
        begin++;
    }
}

long long    Span::shortestSpan() {
    if (_numbers.size() < 2)
        throw NoSpanFoundException();

    std::vector<long long> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    long long minSpan = std::numeric_limits<long long>::max();
    for (uint i = 0; i < sortedNumbers.size() - 1; ++i) {
            long long current = sortedNumbers[i+1] - sortedNumbers[i];
            if (current < minSpan)
                minSpan = current;
    }
    return minSpan;
}

long long    Span::longestSpan() {
    if (_numbers.size() < 2)
        throw NoSpanFoundException();

    long long min = *std::min_element(_numbers.begin(), _numbers.end());
    long long max = *std::max_element(_numbers.begin(), _numbers.end());

    return max - min;
}
