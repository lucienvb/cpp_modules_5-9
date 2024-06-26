#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

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

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const noexcept;
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const noexcept;
    };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif