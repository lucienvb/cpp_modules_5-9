#include "BitcoinExchange.hpp"
#include <regex>
#include <algorithm>

BitcoinExchange::BitcoinExchange(): map({}) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj){
	if (this != &obj){
		*this = obj;
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &obj){
	if (this != &obj){
		// this->_max_size = obj._max_size;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool isValidFormat(const std::string& str) {
    std::regex pattern(R"(\d{4}-\d{2}-\d{2} \| -?\d+(\.\d+)?)");

    return std::regex_match(str, pattern);
}

void	BitcoinExchange::addKeyPair(std::string date, double currency) {
	map[date] = currency;
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
		case 1:
			if (day > 31)
				return false;
			break ;
		case 2:
			if (day > 29)
				return false;
			break;
		case 3:
			if (day > 31)
				return false;
			break;
		case 4:
			if (day > 30)
				return false;
			break;
		case 5:
			if (day > 31)
				return false;
			break;
		case 6:
			if (day > 30)
				return false;
			break;
		case 7:
			if (day > 31)
				return false;
			break;
		case 8:
			if (day > 31)
				return false;
			break;
		case 9:
			if (day > 30)
				return false;
			break;
		case 10:
			if (day > 31)
				return false;
			break;
		case 11:
			if (day > 30)
				return false;
			break;
		case 12:
			if (day > 31)
				return false;
			break;
	}
	return true;
}

int	BitcoinExchange::getLastDayOfMonth(int month) {
	switch (month) {
		case 1:
			return 31;
			break ;
		case 2:
			return 29;
			break;
		case 3:
			return 31;
			break;
		case 4:
			return 30;
			break;
		case 5:
			return 31;
			break;
		case 6:
			return 30;
			break;
		case 7:
			return 31;
			break;
		case 8:
			return 31;
			break;
		case 9:
			return 30;
			break;
		case 10:
			return 31;
			break;
		case 11:
			return 30;
			break;
		case 12:
			return 31;
			break;
	}
	return -1;
}

bool	BitcoinExchange::isValidDate(std::string date) {

	int year = stoi(date.substr(0, 4));
	// std::cout << "year " << year << std::endl;
	if (year > 2022)
		return false;

	int month = stoi(date.substr(5, 7));
	// std::cout << "month " << month << std::endl;
	if (month > 12)
		return false;

	int day = stoi(date.substr(8, 10));
	// std::cout << "day " << day << std::endl;
	if (!isValidDay(month, day))
		return false;

	return (true);
}

void	decreaseDate(std::string &refDate) {
	
}

bool	BitcoinExchange::getCurrency(std::string date, double &refCurrency) {
	std::string &refDate = date;
	
	if (map.find(refDate) != std::end(map))
		refCurrency = map[refDate];
	else
		refCurrency = -1;
	std::cout << "refCurrency: " << refCurrency << std::endl;



	return true;
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
						// std::cout << date << " => " << number << " = " << number * map[date] << std::endl;
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