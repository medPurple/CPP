#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

class EmptyContainerException : public std::exception {
    public :
            const char *what() const throw() {
	            return ("\x1b[31m \x1b[3m EasyFind exception : empty container \x1b[0m");}
};

class NoMatchContainerException : public std::exception {
    public :
            const char *what() const throw() {
	            return ("\x1b[31m \x1b[3m EasyFind exception : no matching container found \x1b[0m");}
};

template<typename T>
bool    easyfind(T& container, int num);

template<typename T>
void    print(T& tab);

#include "../template/easyfind.tpp"