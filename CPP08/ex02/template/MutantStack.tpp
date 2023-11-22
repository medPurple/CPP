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
