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