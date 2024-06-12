#include <iostream>
#include "../include/whatever.hpp"

int main() {
    int a = 2;
    int b = 1;
    swap(a, b);
    std::cout << ">> SWAP TEST CASES <<\na: " << a << ", b: " << b << std::endl;

    float c = 3.3f;
    float d = 1.1f;
    swap(c, d);
    std::cout << "c: " << c << ", d: " << d << std::endl;

    char e = 'e';
    char f = 'f';
    swap(e, f);
    std::cout << "e: " << e << ", f: " << f << std::endl;


    std::cout << "\n>> MIN TEST CASES <<\nmin(2, 1): " << min(2, 1) << std::endl;
    std::cout << "min(2, 2): " << min(2, 2) << std::endl;
    std::cout << "min(3.3f, 1): " << min(3.3f, 1.1f) << std::endl;
    std::cout << "min('b', 'a'): " << min('b', 'a') << std::endl;
    std::cout << "min(true, false): " << min(true, false) << std::endl;

    std::cout << "\n>> MAX TEST CASES <<\nmax(2, 1): " << max(2, 1) << std::endl;
    std::cout << "max(2, 2): " << max(2, 2) << std::endl;
    std::cout << "max(3.3f, 1): " << max(3.3f, 1.1f) << std::endl;
    std::cout << "max('b', 'a'): " << max('b', 'a') << std::endl;
    std::cout << "max(true, false): " << max(true, false) << std::endl;

    return 0;
}
// int main(void)
// {
//     Awesome a(2), b(4); 
//     swap(a, b);
//     std::cout << a << " " << b << std::endl;
//     std::cout << max(a, b) << std::endl;
//     std::cout << min(a, b) << std::endl;
//     return (0);
// }
