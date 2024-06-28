#include "BitcoinExchange.hpp"
#include <regex>
#include <algorithm>

BitcoinExchange::BitcoinExchange(): _map({}) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
	if (this != &obj){
		*this = obj;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj){
	if (this != &obj){
		this->_map = obj._map;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool isValidFormat(const std::string& str) {
    std::regex pattern(R"(\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?)");

    return std::regex_match(str, pattern);
}

void	BitcoinExchange::addKeyPair(std::string date, double currency) {
	_map[date] = currency;
}

void	BitcoinExchange::parseData() {
	try {
		std::ifstream infile("data/data.csv");
		bool first = true;
		for (std::string line; std::getline(infile, line);) {
			if (first) {
				first = false;
				continue ;
			}
			std::string date = line.substr(0, 10);
			double currency = stod(line.substr(11, line.size()));
			addKeyPair(date, currency);
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}

bool	BitcoinExchange::isValidDay(int month, int day) {
	switch (month) {
		case 1: if (day > 31) return false;
		case 2: if (day > 29) return false;
		case 3:	if (day > 31) return false;
		case 4: if (day > 30) return false;
		case 5:	if (day > 31) return false;
		case 6:	if (day > 30) return false;
		case 7:	if (day > 31) return false;
		case 8:	if (day > 31) return false;
		case 9: if (day > 30) return false;
		case 10: if (day > 31) return false;
		case 11: if (day > 30) return false;
		case 12: if (day > 31) return false;
		default: return true;
	}
}

int	BitcoinExchange::getLastDayOfMonth(int month) {
	switch (month) {
        case 1: return 31;
        case 2: return 29;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return -1;
    }
}

bool	BitcoinExchange::isValidDate(std::string date) {

	int year = stoi(date.substr(0, 4));
	if (year > 2022)
		return false;

	int month = stoi(date.substr(5, 7));
	if (month > 12)
		return false;

	int day = stoi(date.substr(8, 10));
	if (!isValidDay(month, day))
		return false;

	return (true);
}

void	BitcoinExchange::decreaseDate(std::string &refDate) {
	int day = stoi(refDate.substr(8, 10)) - 1;
	int month = stoi(refDate.substr(5, 7));
	int year = stoi(refDate.substr(0, 4));
	if (day <= 0) {
		month--;
		if (month <= 0) {
			year--;
			if (year < 2009) {
				refDate = "";
				return ;
			}
			month = 12;
			day = getLastDayOfMonth(month);
			if (day == -1) {
				refDate = "";
				return ;
			}
		}
	}
	std::string dayAddZero = "";
	if (day < 10)
		dayAddZero = "0";
	std::string monthAddZero = "";
	if (month < 10)
		monthAddZero = "0";
	refDate = std::to_string(year) + '-' + monthAddZero + std::to_string(month) + '-' + dayAddZero + std::to_string(day);
}

bool	BitcoinExchange::getCurrency(std::string date, double &refCurrency) {
	try {
		std::string &refDate = date;
		
		while (refDate != "") {
			if (_map.find(refDate) != std::end(_map)) {
				refCurrency = _map[refDate];
				return true;
			}
			decreaseDate(refDate);
		}
		return false;
	}
	catch (std::exception &e) {}
	return false;
}

void	BitcoinExchange::getResults(std::string str) {

	try {
		std::ifstream infile(str);
		bool first = true;
		double currency = -1;
		double &refCurrency = currency;
		for (std::string line; std::getline(infile, line);) {
			if (first) {
				if (line.compare("date | value") != 0)
					throw WrongFormatException();
				first = false;
			}
			else {
				std::string date = line.substr(0, 10);
				if (isValidFormat(line)) {
					double number = stod(line.substr(13, line.size()));
					if (number < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else if (number > 999)
						std::cout << "Error: too large a number." << std::endl;
					else if (!isValidDate(date))
						std::cout << "Error: bad input => " << date << std::endl;
					else if (getCurrency(date, refCurrency))
						std::cout << date << " => " << number << " = " << number * refCurrency << std::endl;
					else
						std::cout << "Error: current date and lower dates not found." << std::endl;
				}
			}
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}