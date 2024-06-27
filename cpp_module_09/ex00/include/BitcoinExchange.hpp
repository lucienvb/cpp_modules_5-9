#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange &obj);
    ~BitcoinExchange();

    void parseData();
    void getResults(std::string str);
    void addKeyPair(std::string date, double currency);
    void printMap();
    bool isValidDate(std::string date);
    bool isValidDay(int month, int day);

    class WrongFormatException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Wrong format of the input file");
        }
    };

    class InvalidDateException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("The date is invalid");
        }
    };

private:
    std::map<std::string, double> map;
};

#endif
