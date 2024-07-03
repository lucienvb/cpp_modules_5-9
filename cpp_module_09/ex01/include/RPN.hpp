#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <variant>

class RPN {
public:
    RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);
    ~RPN();

    bool	parse(std::string str);
    void    printNumbersTop();
    bool    process();
    void    calculate(int first, int second, char operation);

private:
    std::stack<long long> _numbers;
    std::stack<char> _operations;
};

#endif
