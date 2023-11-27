#include "PMerge.hpp"



int main(int argc, char* av[]) {
    try {
        if (argc < 2) {
            throw ErrorException();
        }
        std::vector<int> vector;
        std::deque<int> deque;

        for (int i = 1; i < argc; ++i) {
            long value = std::strtol(av[i], NULL, 10);
            if (value < 0 || (value == 0 && av[i][0] != '0') ||  value > INT_MAX) {
                throw ErrorException();
            }
            vector.push_back(value);
            deque.push_back(value);
        }
        start_sort(vector, deque);

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}