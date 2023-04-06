#include "calc/calculator.h"

using namespace std;

double Calculator::calculate() {
    return expr();
}

double Calculator::expr() {
    double left = term();
    Token t = getNextToken();
    while (t.type == Token::Type::Plus || t.type == Token::Type::Minus) {
        double right = term();
        if (t.type == Token::Type::Plus) {
            left += right;
        } else {
            left -= right;
        }
        t = getNextToken();
    }
    putBackToken(t);
    return left;
}

double Calculator::term() {
    double left = power();
    Token t = getNextToken();
    while (t.type == Token::Type::Multiply || t.type == Token::Type::Divide) {
        double right = power();
        if (t.type == Token::Type::Multiply) {
            left *= right;
        } else {
            left /= right;
        }
        t = getNextToken();
    }
    putBackToken(t);
    return left;
}

double Calculator::power() {
    double left = factor();
    Token t = getNextToken();
    if (t.type == Token::Type::Power) {
        double right = power();
        return pow(left, right);
    }
    putBackToken(t);
    return left;
}

double Calculator::factor() {
    Token t = getNextToken();
    switch (t.type) {
        case Token::Type::Number:
            return t.value;
        case Token::Type::Minus:
            return -factor();
        case Token::Type::LeftParenthesis: {
            double result = expr();
            t = getNextToken();
            return result;
        }
        default:
            return expr();
    }
}

Token Calculator::getNextToken() {
    while (m_index < m_input.size() && isspace(m_input[m_index])) {
        m_index++;
    }
    if (m_index >= m_input.size()) {
        return Token();
    }
    if (isdigit(m_input[m_index])) {
        double value = 0;
        while (m_index < m_input.size() && isdigit(m_input[m_index])) {
            value = value * 10 + (m_input[m_index] - '0');
            m_index++;
        }
        if (m_index < m_input.size() && m_input[m_index] == '.') {
            m_index++;
            double factor = 0.1;
            while (m_index < m_input.size() && isdigit(m_input[m_index])) {
                value += factor * (m_input[m_index] - '0');
                factor *= 0.1;
                m_index++;
            }
        }
        return Token(Token::Type::Number, value);
    }
    switch (m_input[m_index]) {
        case '+':
            m_index++;
            return Token(Token::Type::Plus);
        case '-':
            m_index++;
            return Token(Token::Type::Minus);
        case '*':
            m_index++;
            return Token(Token::Type::Multiply);
        case '/':
            m_index++;
            return Token(Token::Type::Divide);
        case '^':
            m_index++;
            return Token(Token::Type::Power);
        case '(':
            m_index++;
            return Token(Token::Type::LeftParenthesis);
        case ')':
            m_index++;
            return Token(Token::Type::RightParenthesis);
        default:
            throw runtime_error("Неверный оператор!");
    }
}

void Calculator::putBackToken(const Token& t) {
    if (t.type != Token::Type::EndOfFile) {
        m_index--;
    }
}
