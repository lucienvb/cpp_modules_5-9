#include "Bureaucrat.hpp"

void    testIncrement(Bureaucrat &other) {
    try {
        other.increment();
    }
    catch (std::exception &e) {
         std::cout << e.what() << std::endl;
    }
}

void    testDecrement(Bureaucrat &other) {
    try {
        other.decrement();
    }
    catch (std::exception &e) {
         std::cout << e.what() << std::endl;
    }
}

void    testCreate(const std::string name, int grade) {
    try {
        Bureaucrat maurice(name, grade);
    }
    catch (std::exception &e) {
         std::cout << e.what() << std::endl;
    }
}

int main() {
    {
        testCreate("Lucien", 0);
        testCreate("Lucien", 151);
        testCreate("Lucien", 1);
        testCreate("Lucien", 150);
    }
    std::cout << "\n----------------------------------------\n" << std::endl;
    {
        Bureaucrat lucien("Lucien", 149);
        std::cout << "\n>> burea's info <<\n" << lucien << std::endl;
        testDecrement(lucien);
        testDecrement(lucien);
    }
    std::cout << "\n----------------------------------------\n" << std::endl;
    {
        Bureaucrat maurice("maurice", 2);
        std::cout << "\n>> burea's info <<\n" << maurice << std::endl;
        testIncrement(maurice);
        testIncrement(maurice);
    }
}
