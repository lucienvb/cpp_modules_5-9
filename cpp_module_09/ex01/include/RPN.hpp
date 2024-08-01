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

    bool	processRPN(std::string str);
    void    printResult();
    bool    calculate(char operation);
    bool    isDecimal(char num);
    bool    isOperation(char operation);

private:
    long long _current;
    std::stack<long long> _numbers;
};

#endif
