#pragma once

#include <iostream>
#include <stack>
#include <sstream>


int evaluateRPN(char *expression);


class ErrorException : public std::exception {
        public:
            virtual const char* what() const throw();
        };