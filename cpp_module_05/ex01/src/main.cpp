#include "Bureaucrat.hpp"
#include "Form.hpp"

void    testBeSigned(Bureaucrat &other, Form &form) {
    try {
        form.beSigned(other);
    }
    catch (std::exception &e) {
         std::cout << e.what() << std::endl;
    }
}

int main() {

    Form important("important", 1, 1);
    Bureaucrat  bur("bur", 2);
    testBeSigned(bur, important);
    bur.signForm(important);

    Bureaucrat  burea("burea", 1);
    testBeSigned(burea, important);
    burea.signForm(important);

    std::cout << "\n>> burea's info <<\n" << burea << std::endl;
    std::cout << ">> important's info <<\n" << important << std::endl;
}
