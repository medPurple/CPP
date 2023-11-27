#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

int evaluateRPN(char *expression);


class ErrorException : public std::exception {
        public:
            virtual const char* what() const throw();
        };