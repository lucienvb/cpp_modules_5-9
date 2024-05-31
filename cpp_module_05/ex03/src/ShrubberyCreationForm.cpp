#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
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

const char* ShrubberyCreationForm::OutfileNotOpenExeption::what() const throw() {
	return ("Exception thrown! Outfile is not open.");
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) {
    AForm::execute(executor);
    
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile)
        throw ShrubberyCreationForm::OutfileNotOpenExeption();

    outfile << "   /\\" << std::endl;
    outfile << "  / /\\" << std::endl;
    outfile << " /\\   \\" << std::endl;
    outfile << "/\\    /\\" << std::endl;
}

