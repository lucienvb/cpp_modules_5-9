#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other): AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target) {
    std::cout << "Copy constructor ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm&   ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    this->_target = other._target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor ShrubberyCreationForm called" << std::endl;
}

void    ShrubberyCreationForm::execute() {
    
    std::cout << "   /\\" << std::endl;
    std::cout << "  / /\\" << std::endl;
    std::cout << " /\\  \\" << std::endl;
    std::cout << "/\\   /\\" << std::endl;
}

