#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	testShrub(){
	std::cout << "* test ShruberyCreationForm *" << std::endl <<std::endl;
	try{
		Bureaucrat lucien("lucien", 1);
		ShrubberyCreationForm form("ShrubShrub");
		form.execute(lucien);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testRob(){
	std::cout << "* test RobotomyRequest *" << std::endl;
	try{
		Bureaucrat maurice("maurice", 71);
		RobotomyRequestForm form("form");
		for (int i = 0; i < 5; i++){
			form.execute(maurice);
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
		}
	std::cout << std::endl;
}

void	testPres(void){
	std::cout << "* test PresidentialPardonForm *" << std::endl;

	try{
	PresidentialPardonForm form("''Form of Pardon''" );
	Bureaucrat jerome("jerome", 151);
	form.execute(jerome);
	std::cout << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat ghislaine("ghislaine", 4);
	PresidentialPardonForm pardon_form("''Form of Pardon''" );
	ghislaine.executeForm(pardon_form);
	std::cout << std::endl;
}

int	main(void){
	testPres();
	std::cout << "\n";
	testRob();
	std::cout << "\n";
	testShrub();
	return 0;
}