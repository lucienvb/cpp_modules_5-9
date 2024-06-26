#include "../include/Span.hpp"
#include <iostream>

void test_with_ten_thousand_numbers() {
    unsigned int limit = 10005;
    Span vec = Span(limit);

    // call shortestSpan and longestSpan with no numbers
    try {
        vec.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        vec.longestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    vec.addNumber(1);
    // call shortestSpan and longestSpan with one number
    try {
        vec.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        vec.longestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    int current = 2;
    for (unsigned int i = 0; i < limit - 1; i++) {
        current *= (current + i);
        if (current % 2 != 0 && current > 100000)
            current /= 1000;
        vec.addNumber(current);
    }
    try {
        vec.addNumber(101);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "shorest span: " << vec.shortestSpan() << std::endl;
    std::cout << "longest span: " << vec.longestSpan() << std::endl;
}

void simple_test() {
    unsigned int limit = 5;
    Span vec = Span(limit);

    vec.addNumber(1);
    vec.addNumber(33);
    vec.addNumber(3);
    vec.addNumber(666);
    vec.addNumber(100);

    std::cout << "shorest span: " << vec.shortestSpan() << std::endl;
    std::cout << "longest span: " << vec.longestSpan() << std::endl;
}

void test_add_numbers() {
    unsigned int limit = 10005;
    Span vec = Span(limit);

    vec.addNumbers(0, 10005);
    std::cout << "shorest span: " << vec.shortestSpan() << std::endl;
    std::cout << "longest span: " << vec.longestSpan() << std::endl;

}

int main() {
    std::cout << ">> SIMPLE TEST <<" << std::endl;
    simple_test();
    std::cout << "\n------------------------------------------------\n" << std::endl;
    std::cout << ">> TEST WITH MORE THEN TEN THOUSAND NUMBERS <<" << std::endl;
    test_with_ten_thousand_numbers();
    std::cout << "\n------------------------------------------------\n" << std::endl;
    std::cout << ">> TEST ADD NUMBERS <<" << std::endl;
    test_add_numbers();
    return 0;
}