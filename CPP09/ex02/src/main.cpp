#include "PMerge.hpp"



int main(int argc, char* argv[]) {
    try {
        if (argc < 2) {
            throw std::invalid_argument("Error: Missing input sequence");
        }
        // Parse command line arguments into a vector of integers
        std::vector<int> vector;
        std::deque<int> deque;

        for (int i = 1; i < argc; ++i) {
            int value = std::stoi(argv[i]);
            if (value < 0) {
                throw std::invalid_argument("Error: Input sequence must contain only positive integers");
            }
            vector.push_back(value);
            deque.push_back(value);
        }

        std::cout << "Before:" << std::endl;
        print<int>(vector);
        print<int>(deque);
        clock_t vectorStartTime = clock();
        mergeInsertSort(vector);
        clock_t vectorEndTime = clock();
        double vectorDuration = (vectorStartTime - vectorEndTime)* 1000000.0 / CLOCKS_PER_SEC;
        clock_t dequeStartTime = clock();
        mergeInsertSort(deque);
        clock_t dequeEndTime = clock();
        double dequeDuration = (dequeStartTime - dequeEndTime)* 1000000.0 / CLOCKS_PER_SEC;
        std::cout << "After:" << std::endl;
        print<int>(vector);
        print<int>(deque);
        std::cout << std::endl;
        std::cout << "Time to process a range of " << vector.size() << " elements with vector " << vectorDuration << " us" << std::endl;
        std::cout << "Time to process a range of " << deque.size() << " elements with vector " << dequeDuration << " us" << std::endl;


    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}



/*https://github.com/orcaus/CPP_Module_09/blob/main/ex02/PmergeMe.cpp*/