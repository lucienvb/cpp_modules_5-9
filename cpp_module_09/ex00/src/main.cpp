#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong numbers of parameters, please use an input file" << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    btc.parseData();
    btc.getResults(argv[1]);
    return 0;
}