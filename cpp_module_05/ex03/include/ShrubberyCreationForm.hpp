#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include <fstream>

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
private:
    std::string	_target;

public:
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor);

	class OutfileNotOpenExeption : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

#endif