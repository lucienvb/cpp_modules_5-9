#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat lucien("lucien", 2);
    Bureaucrat maurice("maurice", 73);
    Bureaucrat jerome("jerome", 146);

    ShrubberyCreationForm shrub("tree");
    RobotomyRequestForm rob("robot");
    PresidentialPardonForm pres("pres");
    try {
        lucien.executeForm(shrub);
        lucien.signAForm(shrub);
        Bureaucrat bur;
        shrub.beSigned(bur);
        shrub.execute(bur);
        lucien.executeForm(rob);
        lucien.executeForm(pres);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n";
    try {
        maurice.executeForm(shrub);
        maurice.executeForm(rob);
        maurice.executeForm(pres);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "\n";
    try {
        jerome.executeForm(shrub);
        jerome.executeForm(rob);
        jerome.executeForm(pres);
    }
    catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
