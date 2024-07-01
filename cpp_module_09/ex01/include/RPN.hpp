#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <variant>

enum class ValueType { 
    INT, 
    CHAR 
};

struct VarType {
    ValueType type;
    union {
        int intValue;
        char charValue;
    };

    VarType(int value) : type(ValueType::INT), intValue(value) {}
    VarType(char value) : type(ValueType::CHAR), charValue(value) {}
};

class RPN {
public:
    RPN();
    RPN(const RPN &obj);
    RPN &operator=(const RPN &obj);
    ~RPN();

    void	parse(std::string str);

private:
    std::stack<VarType> _stack;
};

#endif
