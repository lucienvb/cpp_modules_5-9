#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Lucien") {
    std::cout << "Constructor Bureaucrat called" << std::endl;
    _grade = 3;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
    std::cout << "Another constructor Bureaucrat called" << std::endl;
	try {
		if (grade < 1)
			throw gradeTooHighException();
		if (grade > 150)
			throw gradeTooLowException();	
		_grade = grade;
	}
	catch (std::string exceptionMessage) {
		std::cout << exceptionMessage << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor Bureaucrat called" << std::endl;
    if (this != &other)
        *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
    std::cout << "Assignment operator Bureaucrat called" << std::endl;
	this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor Bureaucrat called" << std::endl;
}

const std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::increment() {
	try {
		if (_grade < 2)
			throw gradeTooHighException();
		_grade -= 1;
		std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
	}
	catch (std::string exceptionMessage) {
		std::cout << exceptionMessage << std::endl;
	}
}

void Bureaucrat::decrement() {
	try {
		if (_grade > 149)
			throw gradeTooLowException();
		_grade += 1;
		std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
	}
	catch (std::string exceptionMessage) {
		std::cout << exceptionMessage << std::endl;
	}
}

std::string Bureaucrat::gradeTooHighException() {
	return ("Exception thrown! Grade is too high.");
}

std::string Bureaucrat::gradeTooLowException() {
	return ("Exception thrown! Grade is too Low.");
}

