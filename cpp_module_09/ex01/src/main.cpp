#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2 || !argv[1][0]) {
        std::cout << "Error: no arguments provided" << std::endl;
        return 1;
    }
    RPN rpn;
    if (!rpn.processRPN(argv[1])) {
        std::cout << "Error: invalid input" << std::endl;
        return 1;
    }
    rpn.printResult();
    return 0;
}