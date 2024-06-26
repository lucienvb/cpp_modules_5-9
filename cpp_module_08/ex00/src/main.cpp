#include "easyfind.hpp"

#include <vector>
#include <list>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    const std::list<int> lst = {6, 7, 8, 9, 0};

    try {
        auto it = easyfind(vec, 0);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        auto it = easyfind(vec, 1);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        auto it = easyfind(lst, 1);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        auto it = easyfind(lst, 6);
        std::cout << "Found in list: " << *it << std::endl;

    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}