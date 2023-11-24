#include "MutantStack.hpp"

/*----------------- Coplien ------------- */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    if (msg_const == true)
        _display_constructor(MUTANT_DC);
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& rhs){
    if (msg_const == true)
        _display_constructor(MUTANT_CC);
    *this = rhs;
}
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& rhs){
    if (this != &rhs)
        *this = rhs;
    if (msg_const == true)
        _display_constructor(MUTANT_AO);
    return *this;
}
template <typename T>
MutantStack<T>::~MutantStack(){
    if (msg_const == true)
        _display_constructor(MUTANT_DD);
} 

template<typename T>
void    print(const MutantStack<T> &tab){
    std::stack<T> tmp = tab;
     std::cout << "[Stack of " << tmp.size() << " integers]: ";
    while (!tmp.empty()) {
        std::cout << "[" << tmp.top() << "]";
        tmp.pop();
    }
    std::cout << std::endl;
    return;
}

void _display_constructor(std::string msg){
    std::cout << "\x1b[33m \x1b[3m" << msg << "\x1b[0m" << std::endl;}

/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { 
    return this->c.end();
}

/*--------------- Exception ------------- */
