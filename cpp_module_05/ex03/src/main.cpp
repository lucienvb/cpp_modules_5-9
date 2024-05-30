#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

int main ()
{
	AForm* form;

	try
	{
		Bureaucrat lucien("lucien", 42);
 		Intern someRandomIntern;
		form = someRandomIntern.makeForm("robotomy request", "maurice");
		lucien.executeForm(*form);
		delete form;
		someRandomIntern.makeForm("Robomtomy Request", "maurice");
		lucien.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}
