#include "BitcoinExchange.hpp"
#include <regex>

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

void	BitcoinExchange::addData(std::string date, double currency) {
	map[date] = currency;
}

void	BitcoinExchange::printMap() {
	for (auto x: map)
		std::cout << x.first << " -> " << x.second << std::endl;
}

void	BitcoinExchange::parseInputFile(std::string str) {

	try {
		std::ifstream infile(str);
		bool first = true;
		for (std::string line; std::getline(infile, line);) {
			if (first) {
				if (line.compare("date | value") != 0)
					throw WrongFormatException();
				first = false;
			}
			else {
				std::string date = line.substr(0, 10);
				if (isValidFormat(line)) {
					double currency = stod(line.substr(13, line.size()));
					addData(date, currency);
				}
				else
					addData(line.substr(0, 10), "Error: bad input => ");


				
				// std::cout << "format: " << isValidFormat(line) << std::endl;
			}
			// std::cout << line << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}