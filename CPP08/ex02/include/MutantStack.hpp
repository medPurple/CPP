#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public			:
    // Coplien
                MutantStack();
                MutantStack(const MutantStack& rhs);
                MutantStack &operator=(const MutantStack& rhs);
                ~MutantStack<T>();

    // Operator
    // Setter / Getter
    // Function
                typedef typename std::stack<T>::container_type::iterator iterator;
                iterator begin();
                iterator end();

    protected   	:

    private     	:
                void _display_constructor(std::string msg){
                    std::cout << "\x1b[33m \x1b[3m" << msg << "\x1b[0m" << std::endl;
                } 

};

static bool msg_const = false;

#define MUTANT_DC "[Default] Constructor called for MUTANT CLASS"
#define MUTANT_PC "[Parametric] Constructor called for MUTANT CLASS"
#define MUTANT_CC "[Copy] Constructor called for MUTANT CLASS"
#define MUTANT_AO "[Attribution] Operator called for MUTANT CLASS"
#define MUTANT_DD "[Default] Destructor called for MUTANT CLASS"

#include "../template/MutantStack.tpp"

