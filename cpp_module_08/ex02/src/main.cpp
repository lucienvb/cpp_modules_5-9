#include "../include/MutantStack.hpp"

// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

int main() {
    MutantStack<int> mstack;

    mstack.push(-9999);
    mstack.push(33);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Size: " << mstack.size() << std::endl;

    for (int i = 0; i < 10; i++) {
        mstack.push(i * (i + 3));
    }

    std::cout << "Top element: " << mstack.top() << std::endl;
    std::cout << "Size: " << mstack.size() << std::endl;

    MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator ite = mstack.rend();

    it++;
    it--;

    std::cout << "MutantStack elements:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        it++;
    }

    std::stack<int> s(mstack);

    return 0;
}
