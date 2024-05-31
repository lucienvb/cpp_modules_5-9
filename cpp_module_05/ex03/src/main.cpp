#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"

void	testSucces(std::string form_name) {
	AForm* form;

	try
	{
		Bureaucrat lucien("lucien", 1);
 		Intern someRandomIntern;
		form = someRandomIntern.makeForm(form_name, "Bender");
		form->beSigned(lucien);
		lucien.executeForm(*form);
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

int main ()
{
	std::cout << "\nTEST SUCCESS\n" << std::endl;
	testSucces("shrubbery request");

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\nTEST SUCCESS\n" << std::endl;
	testSucces("robotomy request");

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "\nTEST SUCCESS\n" << std::endl;
	testSucces("presidential request");

	std::cout << "\n----------------------------------------\n" << std::endl;

	std::cout << "TEST FAILURE\n" << std::endl;
	testSucces("Robomtomy Request");

	return 0;
}
