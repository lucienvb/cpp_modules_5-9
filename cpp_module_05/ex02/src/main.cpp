#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

// void    testBeSigned(Bureaucrat &other, AForm &aForm) {
//     try {
//         aForm.beSigned(other);
//     }
//     catch (std::exception &e) {
//          std::cout << e.what() << std::endl;
//     }
// }

int main() {
    ShrubberyCreationForm form("tree");
    Bureaucrat bur;
    form.beSigned(bur);
    form.execute(bur);


    // AForm important("important", 1, 1);
    // Bureaucrat  bur("bur", 2);
    // testBeSigned(bur, important);
    // bur.signAForm(important);

    // Bureaucrat  burea("burea", 1);
    // testBeSigned(burea, important);
    // burea.signAForm(important);

    // std::cout << "\n>> burea's info <<\n" << burea << std::endl;
    // std::cout << ">> important's info <<\n" << important << std::endl;
}
