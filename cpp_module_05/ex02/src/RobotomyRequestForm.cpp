#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "Constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other): AForm(other.getName(), other.getSignGrade(), other.getExecuteGrade()), _target(other._target) {
    std::cout << "Copy constructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm&   RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    this->_target = other._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) {
    AForm::execute(executor);

    std::cout << "Make some drilling noises..." << std::endl;
    
    srand ( time(NULL) );
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "The robotomy failed." << std::endl;
}
