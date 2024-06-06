#include "Base.hpp"

void identify(Base *p);
void identify(Base &p);

int main() {
    Base *random = generate();
    if (random) {
        // Base &r = *random;
        Base base;
        identify(random);
        identify(*random);
        identify(base);
    }
    else
        std::cout << "generate failed" << std::endl;
    return 0;
}