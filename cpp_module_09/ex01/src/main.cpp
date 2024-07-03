#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: no arguments provided" << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.parse(argv[1])) {
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }
    if (!rpn.process()) {
        std::cout << "Error: invalid order" << std::endl;
        return 1;
    }
    rpn.printNumbersTop();
    return 0;
}