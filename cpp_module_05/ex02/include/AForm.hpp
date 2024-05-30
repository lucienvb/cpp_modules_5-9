#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string	_name;
    bool                _signed;
	const int			_sign_grade;
	const int			_execute_grade;

public:
	AForm();
	AForm(const std::string name, const int sign_grade, const int execute_grade);
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);
	~AForm();

	const std::string 	getName() const;
	bool	 			getSigned() const;
	int 			getSignGrade() const;
	int 			getExecuteGrade() const;

	void    beSigned(const Bureaucrat &other);

	void	execute(Bureaucrat const & executor);

	class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

	class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& aForm);

#endif