#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>
#include <fstream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	Intern();
	Intern(Intern &other);
	Intern& operator=(const Intern &other);
	~Intern();

	AForm *makeShrubberyCreationForm(const std::string &target);
	AForm *makeRobotomyRequestForm(const std::string &target);
	AForm *makePresidentialPardonForm(const std::string &target);
	
	AForm *makeForm(const std::string &name, const std::string &target);

		class FormNotFoundException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif