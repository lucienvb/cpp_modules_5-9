#include "Form.hpp"

Form::Form(): _name("lucien"), _sign_grade(1), _execute_grade(1) {
    std::cout << "Constructor Form called" << std::endl;
    _signed = false;
}

Form::Form(const std::string name, const int sign_grade, const int execute_grade): _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade) {
    std::cout << "Another constructor Form called" << std::endl;
    if (sign_grade < 1 || execute_grade < 1)
        throw Form::GradeTooHighException();
    if (sign_grade > 150 || execute_grade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade) {
    std::cout << "Copy constructor Form called" << std::endl;
    _signed = other._signed;
}

Form&   Form::operator=(const Form &other) {
    (void)other;
    return (*this);
}

Form::~Form() {
    std::cout << "Destructor Form called" << std::endl;
}

const std::string Form::getName() const {
	return (this->_name);
}

bool    Form::getSigned() const {
    return (this->_signed);
}

int Form::getSignGrade() const {
	return (this->_sign_grade);
}

int Form::getExecuteGrade() const {
	return (this->_execute_grade);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Exception thrown! Grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Exception thrown! Grade is too low.");
}

void    Form::beSigned(const Bureaucrat &other) {
    if (other.getGrade() > _sign_grade)
        throw Form::GradeTooLowException();
    else
        _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "name: " << form.getName() <<
	"\nsigned: " << form.getSigned() <<
	"\nsign grade: " << form.getSignGrade() <<
	"\nexecute grade: " << form.getExecuteGrade() << std::endl;
	return out;
}