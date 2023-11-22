#include "easyfind.hpp"

template<typename T>
bool    easyfind(T& container, int num) {  
    if (container.empty() == true) {
		throw EmptyContainerException();
	}
    if (std::find(container.begin(), container.end(), num) == container.end())
        throw NoMatchContainerException();
    return true;
};

template<typename T>
void    print(T& tab){
    std::cout << "[Container] ";
    for (int i = 0; i < (int)tab.size(); i ++)
        std::cout << tab[i] << " | ";
    std::cout << std::endl;
    return;
}