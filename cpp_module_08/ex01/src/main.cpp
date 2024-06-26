#include "../include/Span.hpp"
#include <iostream>

int main() {

    Span vec = Span(5);

    vec.addNumber(1);
    vec.addNumber(11);
    vec.addNumber(33);
    vec.addNumber(666);
    vec.addNumber(100);
    try {
        vec.addNumber(101);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "shorest span: " << vec.shortestSpan() << std::endl;

    return 0;
}