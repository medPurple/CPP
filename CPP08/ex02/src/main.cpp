#include "MutantStack.hpp"
void exec_mutant();

int main()
{
    std::cout << "-- MUTANT --" << std::endl;
    exec_mutant();

    return 0;
}

void exec_mutant(){
        
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "TOP : ";
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "SIZE : ";
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}