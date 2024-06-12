#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base *generate() {
    srand( time(NULL) );
    int random_value = rand() % 3;
    
    if (random_value == 0)
        return new A;
    else if (random_value == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "Identified A on *p" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Identified B on *p" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Identified C on *p" << std::endl;
    else
        std::cout << "Identifying failed" << std::endl;
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "Identified A on &p" << std::endl;
        return ;
    }
    catch (std::bad_cast &e) {}
    try {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "Identified B on &p" << std::endl;
        return ;
    }
    catch (std::bad_cast &e) {}
    try {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "Identified C on &p" << std::endl;
        return ;
    }
    catch (std::bad_cast &e) {
        std::cout << "exception thrown: " << e.what() << std::endl;
    }
}

