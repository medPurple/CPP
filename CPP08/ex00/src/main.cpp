#include "easyfind.hpp"

int main() {
	std::array<int, 5>	array	= {0, 1, 2, 3, 4};
	std::vector<int>	vector;
	
	for (int i(1); i<=4; i++) {
		vector.push_back(i);
	}

	for (int num = -1; num <= 5; num++)
	{
		std::cout << "Number : " << num << std::endl;
		try {
            print(vector);
            std::cout << " ---> ";
			if (easyfind(vector, 1) == true)
                std::cout << "\x1b[32m \x1b[3m 	Occurrence found! \x1b[0m" << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
            print(array);
            std::cout << " ---> ";
			if (easyfind(array, 1) == true)
                std::cout << "\x1b[32m \x1b[3m 	Occurrence found! \x1b[0m" << std::endl;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	try {
		std::cout << std::endl << "Empty container : " << std::endl;
		std::vector<int> emptyvector;
		if (easyfind(emptyvector, 1) == true)
                std::cout << "\x1b[32m \x1b[3m 	Occurrence found! \x1b[0m	" << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return (0);
}