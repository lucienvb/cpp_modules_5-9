#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Lucien") {
    std::cout << "Constructor Bureaucrat called" << std::endl;
    _grade = 3;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
    std::cout << "Another constructor Bureaucrat called" << std::endl;
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();	
		_grade = grade;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
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
			throw Bureaucrat::GradeTooHighException();
		_grade -= 1;
		std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::decrement() {
	try {
		if (_grade > 149)
			throw Bureaucrat::GradeTooLowException();
		_grade += 1;
		std::cout << _name << ", bureaucrat grade " << _grade << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception thrown! Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception thrown! Grade is too low.");
}

void    Bureaucrat::signAForm(AForm &aForm) const {
	try {
		aForm.beSigned(*this);
		std::cout << _name << " signed " << aForm.getName() << std::endl;
	}
	catch (std::exception& e) {
		std::cout << _name << " couldn't sign " << aForm.getName() << " because " << e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << "name: " << bureaucrat.getName() <<
	"\ngrade: " << bureaucrat.getGrade() << std::endl;
	return out;
}

void	Bureaucrat::executeForm(AForm &form) const {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << _name << " not able to exexute form." << std::endl;
		std::cout << e.what() << std::endl;
	}
}