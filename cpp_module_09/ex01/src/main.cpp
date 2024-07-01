#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error: no arguments provided" << std::endl;
        return 1;
    }
    RPN rpn;
    (void)argv;
    rpn.parse(argv[1]);

    return 0;
}