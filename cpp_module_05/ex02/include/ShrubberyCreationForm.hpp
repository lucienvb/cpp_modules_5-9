#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {
private:
    std::string	_target;

public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
};

#endif