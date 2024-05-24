#include "Bureaucrat.hpp"
#include "Form.hpp"

// void    testIncrement(Bureaucrat &other) {
//     try {
//         other.increment();
//     }
//     catch (std::exception &e) {
//          std::cout << e.what() << std::endl;
//     }
// }

void    testBeSigned(Bureaucrat &other, Form &form) {
    try {
        form.beSigned(other);
    }
    catch (std::exception &e) {
         std::cout << e.what() << std::endl;
    }
}

// void    testCreate(const std::string name, int grade) {
//     try {
//         Bureaucrat maurice(name, grade);
//     }
//     catch (std::exception &e) {
//          std::cout << e.what() << std::endl;
//     }
// }

int main() {

    Form important("important", 1, 1);
    Bureaucrat  bur("bur", 2);
    testBeSigned(bur, important);
}
