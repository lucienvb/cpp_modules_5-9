#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {
private:
    const std::string   _name;
    int		            _grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string 	getName() const;
    int    		      	getGrade() const;
	void				increment();
	void				decrement();
	std::string			gradeTooHighException();
	std::string			gradeTooLowException();

};

#endif