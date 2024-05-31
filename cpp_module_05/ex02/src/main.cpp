#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testShrub(){
	std::cout << "TEST SHRUBBERY CREATION FORM\n" << std::endl;
	try{
		Bureaucrat lucien("lucien", 144);
		ShrubberyCreationForm form("shrub form");
		form.beSigned(lucien);
		form.execute(lucien);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

void	testRob(){
	std::cout << "TEST ROBOTOMY REQUEST FORM\n" << std::endl;
	try {
		Bureaucrat maurice("maurice", 46);
		RobotomyRequestForm form("rob form");

		form.beSigned(maurice);
		form.execute(maurice);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void	testPres(void){
	std::cout << "TEST PRESIDENTIAL PARDON FORM\n" << std::endl;

	try {
		PresidentialPardonForm form("pres form" );
		Bureaucrat jerome("jerome", 6);
		form.beSigned(jerome);
		form.execute(jerome);
		std::cout << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}

int	main(void){
	{
		testShrub();
	}
	std::cout << "\n----------------------------------------\n" << std::endl;
	{
		testRob();
	}
	std::cout << "\n----------------------------------------\n" << std::endl;
	{
		testPres();
	}

	std::cout << "\n>> test executeForm <<\n" << std::endl;

	Bureaucrat ghislaine("ghislaine", 6);
	PresidentialPardonForm pardon_form("pres form" );
	pardon_form.beSigned(ghislaine);
	ghislaine.executeForm(pardon_form);
	std::cout << std::endl;

	return 0;
}