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
    {
        Form success("success", 3, 1);
        Bureaucrat  bur("bur", 1);

        std::cout << "\n>> bur's info <<\n" << bur << std::endl;
        std::cout << ">> success's info <<\n" << success << std::endl;

        testBeSigned(bur, success);
        bur.signForm(success);
    }
    std::cout << "\n----------------------------------------\n" << std::endl;
    {
        Form failure("failure", 60, 1);
        Bureaucrat  burea("burea", 70);

        std::cout << "\n>> burea's info <<\n" << burea << std::endl;
        std::cout << ">> failure's info <<\n" << failure << std::endl;

        testBeSigned(burea, failure);
        burea.signForm(failure);
    }
}
