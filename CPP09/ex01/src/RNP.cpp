#include "RNP.hpp"

int evaluateRPN(char *expression) {
    
    std::cout << "\x1b[34m\x1b[3m" << "Operation : " << expression << "\x1b[0m" << std::endl;
    std::stack<int> operandStack;
    std::stringstream ss;
    int operation = 0;

    ss << expression;
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && isdigit(token[1]))) {

            long operand = strtol(token.c_str(), NULL, 10);
            if ((!operand && token[0] != '0') || operand > 9 || operand < 0)
                throw ErrorException();
            operandStack.push(operand);}
        else {
            if (operandStack.empty())
                throw ErrorException();
            long operand2 = operandStack.top();

            operandStack.pop();
            if (operandStack.empty())
                throw ErrorException();
            long operand1 = operandStack.top();
            operandStack.pop();

            switch (token[0]) {
                case '+':
                    operation++;
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operation++;
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operation++;
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operation++;
                    operandStack.push(operand1 / operand2);
                    break;
                default :
                    throw ErrorException();
            }
        }
    }
    if (operation > 0)
        return operandStack.top();
    else
        throw ErrorException();
}


const char *::ErrorException::what() const throw()
{
		return ("\x1b[31m \x1b[3m Error \x1b[0m");
}