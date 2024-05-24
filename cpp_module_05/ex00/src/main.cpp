#include "Bureaucrat.hpp"

int main() {
    Bureaucrat lucien;
    lucien.increment();
    lucien.increment();
    lucien.increment();
    lucien.increment();

    std::cout << lucien.getGrade() << std::endl;
    std::cout << lucien.getName() << std::endl;

    Bureaucrat maurice("maurice", 0);
    Bureaucrat jerome("jerome", 151);
    Bureaucrat ghislaine("ghislaine", 147);

    ghislaine.decrement();
    ghislaine.decrement();
    ghislaine.decrement();
    ghislaine.decrement();
    ghislaine.decrement();

    lucien = ghislaine;
    std::cout << lucien.getGrade() << std::endl;
    std::cout << lucien.getName() << std::endl;

}
