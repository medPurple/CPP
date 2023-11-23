#include "easyfind.hpp"

int main() {

    std::cout << "\e[4;32m" << "[TEST 1]" << "\e[0m" << std::endl;

    std::vector<int> tab;
    for (int i = 0; i < 10 ; i++)
        tab.push_back(i);  
    print(tab);
    try {
        if (easyfind(tab, 1) == true)
            std::cout << "Occurrence found!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
         if (easyfind(tab, 1) == true)
            std::cout << "Occurrence found!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\e[4;32m" << "[TEST 2]" << "\e[0m" << std::endl;
    srand(time(NULL));
    std::vector<int>tab_rand;
    for (int i = 0; i < 10 ; i++)
        tab_rand.push_back(rand());  
    print(tab_rand);
    try {
        if (easyfind(tab_rand, rand()) == true)
            std::cout << "Occurrence found!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        if (easyfind(tab_rand, rand()) == true)
            std::cout << "Occurrence found!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;  
}