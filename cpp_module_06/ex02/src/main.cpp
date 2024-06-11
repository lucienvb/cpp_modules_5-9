#include "Base.hpp"
#include <unistd.h>

void identify(Base *p);
void identify(Base &p);

void test(Base *random) {
    if (random) {
        identify(random);
        identify(*random);
    }
    else
        std::cout << "generate failed" << std::endl;
}

int main() {
    Base *random = generate();
    sleep(1);
    Base *rand = generate();

    test(random);
    test(rand);
    
    return 0;
}