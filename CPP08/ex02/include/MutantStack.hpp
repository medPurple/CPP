#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <iterator>
#include <vector>
#include <list>

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

};

static bool msg_const = false;

void _display_constructor(std::string msg);

template <typename T> 
void    print(const MutantStack<T> &tab);

#define MUTANT_DC "[Default] Constructor called for MUTANT CLASS"
#define MUTANT_PC "[Parametric] Constructor called for MUTANT CLASS"
#define MUTANT_CC "[Copy] Constructor called for MUTANT CLASS"
#define MUTANT_AO "[Attribution] Operator called for MUTANT CLASS"
#define MUTANT_DD "[Default] Destructor called for MUTANT CLASS"

#include "../template/MutantStack.tpp"

