#include "PMerge.hpp"

const char *::ErrorException::what() const throw()
{
		return ("\x1b[31m \x1b[3m Error \x1b[0m");
}

void start_sort(std::vector<int>vector, std::deque<int>deque){
	        
	std::cout << "Before:" << std::endl;
    {print<int>(vector); print<int>(deque);}

    clock_t vectorStartTime = clock();
    mergeInsertSort(vector);
    clock_t vectorEndTime = clock();
	double vectorDuration = (vectorEndTime - vectorStartTime);

    clock_t dequeStartTime = clock();
    mergeInsertSort(deque);
    clock_t dequeEndTime = clock();
    double dequeDuration = (dequeEndTime - dequeStartTime);
	
    std::cout << "After:" << std::endl;
    {print<int>(vector); print<int>(deque);}

    std::cout << std::endl;
    std::cout << "Time to process a range of " << vector.size() << " elements with vector " << vectorDuration << " us" << std::endl;
    std::cout << "Time to process a range of " << deque.size() << " elements with vector " << dequeDuration << " us" << std::endl;
}