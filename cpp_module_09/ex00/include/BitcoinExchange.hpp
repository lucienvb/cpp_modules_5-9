#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include<algorithm>

class WrongFormatException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Wrong format of the input file");
        }
};

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();

    void parseInputFile(std::string str);


};

#endif
