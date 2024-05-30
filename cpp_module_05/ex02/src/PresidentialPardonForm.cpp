#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "Constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other): AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target) {
    std::cout << "Copy constructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm&   PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    this->_target = other._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) {
    AForm::execute(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
