#include "AForm.hpp"

AForm::AForm(): _name("lucien"), _sign_grade(1), _execute_grade(1) {
    std::cout << "Constructor AForm called" << std::endl;
    _signed = false;
}

AForm::AForm(const std::string name, const int sign_grade, const int execute_grade): _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    std::cout << "Another constructor AForm called" << std::endl;
    if (sign_grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other): _name(other._name), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {
    std::cout << "Copy constructor AForm called" << std::endl;
    _signed = other._signed;
}

AForm&   AForm::operator=(const AForm &other) {
    (void)other;
    return (*this);
}

AForm::~AForm() {
    std::cout << "Destructor AForm called" << std::endl;
}

const std::string AForm::getName() const {
	return (this->_name);
}

bool    AForm::getSigned() const {
    return (this->_signed);
}

int AForm::getSignGrade() const {
	return (this->_sign_grade);
}

int AForm::getExecuteGrade() const {
	return (this->_execute_grade);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Exception thrown! Grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Exception thrown! Grade is too low.");
}

const char* AForm::FormNotSignedException::what() const throw() {
	return ("Exception thrown! Grade is not signed.");
}

void    AForm::beSigned(const Bureaucrat &other) {
    try {
        if (other.getGrade() > _sign_grade)
            throw AForm::GradeTooLowException();
        else
            _signed = true;
    }
    catch (std::string exceptionMessage) {
		std::cout << exceptionMessage << std::endl;
	}
}

void    AForm::execute(Bureaucrat const & executor) {
    if (this->_signed == false)
        throw AForm::FormNotSignedException();
    else if (executor.getGrade() > _execute_grade)
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& aForm) {
	out << "name: " << aForm.getName() <<
	"\nsigned: " << aForm.getSigned() <<
	"\nsign grade: " << aForm.getSignGrade() <<
	"\nexecute grade: " << aForm.getExecuteGrade() << std::endl;
	return out;
}