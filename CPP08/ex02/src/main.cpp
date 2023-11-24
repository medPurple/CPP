#include "MutantStack.hpp"


int main(){

	std::cout << "\e[4;32m" << "[TEST : mstack]" << "\e[0m" << std::endl;
	MutantStack<int> mstack;
	std::list<int> list;
	std::vector<int> vector;

	/*PUSH*/

	std::cout << "\e[4;33m" << "[push]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	list.push_back(5);
	list.push_back(17);
	std::cout << "[List of " << list.size() << " integers]: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << "[Vector of " << vector.size() << " integers]: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "MutanStack" << "\e[0m" << std::endl;
	mstack.push(5);
	mstack.push(17);
	print(mstack);

	/*TOP*/

	std::cout << "\e[4;33m" << "[top]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	std::cout << vector.back() << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	std::cout << mstack.top() << std::endl;

	/*POP*/

	std::cout << "\e[4;33m" << "[pop]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	list.pop_back();
	std::cout << "[List of " << list.size() << " integers]: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	vector.pop_back();
	std::cout << "[Vector of " << vector.size() << " integers]: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	mstack.pop();
	print(mstack);

	/*SIZE*/

	std::cout << "\e[4;33m" << "[size]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	std::cout << list.size() << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	std::cout << vector.size() << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << "\e[4;33m" << "[push]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::cout << "[List of " << list.size() << " integers]: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);
	vector.push_back(0);
	std::cout << "[Vector of " << vector.size() << " integers]: ";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	print(mstack);

	/*ITERATOR*/

	std::cout << "\e[4;33m" << "[iterator]" << "\e[0m" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::vector<int>::iterator vit = vector.begin();
	std::vector<int>::iterator vite = vector.end();
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	std::cout << "\e[4;33m" << "[++]" << "\e[0m" << std::endl;
	++it;
	++vit;
	++lit;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	std::cout << *lit << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	std::cout << *vit << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	std::cout << *it << std::endl;

	std::cout << "\e[4;33m" << "[--]" << "\e[0m" << std::endl;
	--it;
	--vit;
	--lit;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	std::cout << *lit << std::endl;
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	std::cout << *vit << std::endl;
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	std::cout << *it << std::endl;

	/*DISPLAY*/

	std::cout << "\e[4;33m" << "[display]" << "\e[0m" << std::endl;
	std::cout << "\e[0;94m" << "list" << "\e[0m" << std::endl;
	while (lit != lite)
	{
	std::cout << *lit << std::endl;
	++lit;
	}
	std::cout << "\e[0;94m" << "vector" << "\e[0m" << std::endl;
	while (vit != vite)
	{
	std::cout << *vit << std::endl;
	++vit;
	}
	std::cout << "\e[0;94m" << "MutantStack" << "\e[0m" << std::endl;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	/*COPY*/

	std::cout << "\e[4;32m" << "[TEST : s (copy mstack)]" << "\e[0m" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;
	std::stack<int> tmp = s;
    std::cout << "[Stack of " << tmp.size() << " integers]: ";
    while (!tmp.empty()) {
        std::cout << "[" << tmp.top() << "]";
        tmp.pop();
    }
    std::cout << std::endl;
	return 0;
}
