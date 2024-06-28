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
    bool isValidDate(std::string date);
    bool isValidDay(int month, int day);
    bool getCurrency(std::string date, double &refCurrency);
    int getLastDayOfMonth(int month);
    void decreaseDate(std::string &refDate);


    class WrongFormatException: public std::exception {
    public:
        virtual const char* what() const noexcept {
            return ("Wrong format of the input file");
        }
    };

private:
    std::map<std::string, double> _map;
};

#endif