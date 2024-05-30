#include "../include/Intern.hpp"

Intern::Intern() {
    std::cout << "Constructor Intern called" << std::endl;
}

Intern::Intern(Intern &other) {
    std::cout << "Copy constructor Intern called" << std::endl;
    *this = other;
}

Intern&   Intern::operator=(const Intern &other) {
    if (this != &other)
        (void)other;
    return (*this);
}

Intern::~Intern() {
    std::cout << "Destructor Intern called" << std::endl;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

const char* Intern::FormNotFoundException::what() const throw() {
	return ("Exception thrown! Form not found.");
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
    std::cout << name << std::endl;
    std::cout << target << std::endl;

    std::string forms[3] = {"shubbery request", "robotomy request", "presidential request"};
    
    AForm *(Intern::*create[3])(const std::string &) = {
        &Intern::makeShrubberyCreationForm, 
        &Intern::makeRobotomyRequestForm,
        &Intern::makePresidentialPardonForm
        };

    for (size_t i = 0; i < 3; i++) {
        if (forms[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return ((this->*create[i])(target));
        }
    }
    throw Intern::FormNotFoundException(); 
}
