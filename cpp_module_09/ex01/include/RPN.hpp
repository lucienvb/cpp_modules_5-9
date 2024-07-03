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
    void    calculate(long long first, long long second, char operation);
    bool    isDecimal(char num);
    bool    isOperation(char operation);

private:
    std::stack<long long> _numbers;
    std::stack<char> _operations;
};

#endif
