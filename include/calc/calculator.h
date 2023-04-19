#ifndef calculator_h
#define calculator_h

#include <iostream>
#include <string>
#include <cmath>

struct Token {
    enum class Type {
        Number,
        Plus,
        Minus,
        Multiply,
        Divide,
        Power,
        LeftParenthesis,
        RightParenthesis,
        EndOfFile
    };

    Type type;
    double value;

    Token(Type t = Type::EndOfFile, double v = 0.0) : type(t), value(v) {}
};

class Calculator {
public:
    Calculator(const std::string& input) : m_input(input), m_index(0) {}

    double calculate();

private:
    std::string m_input;
    size_t m_index;

    double expr();
    double term();
    double power();
    double factor();

    Token getNextToken();

    void putBackToken(const Token& t);
};

#endif /* calculator_h */
