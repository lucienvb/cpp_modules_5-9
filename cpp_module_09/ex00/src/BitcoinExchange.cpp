#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

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

void	BitcoinExchange::parseInputFile(std::string str) {

	try {
		str.erase(0, 5);
		std::ifstream infile(str);
		bool first = true;
		for (std::string line; std::getline(infile, line);) {
			if (first) {
				if (line.compare("date | value") != 0)
					throw WrongFormatException();
				first = false;
			}
			else {
				

			}
			std::cout << line << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}