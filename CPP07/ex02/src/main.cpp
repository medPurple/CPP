#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    std::cout << "TEST COPY" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "\x1b[32m \x1b[3m Successful copy! \x1b[0m" << std::endl;
    try
    {
        std::cout << "Test : number[-2]" << std::endl;
        numbers[-2] = 0;
        std::cout << "\x1b[32m \x1b[3m OK ! \x1b[0m" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
     try
    {
        std::cout << "Test : number[10]" << std::endl;
        numbers[10] = 0;
        std::cout << "\x1b[32m \x1b[3m OK ! \x1b[0m" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "Test : number[" << MAX_VAL << "]" << std::endl;
        numbers[MAX_VAL] = 0;
        std::cout << "\x1b[32m \x1b[3m OK ! \x1b[0m" << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "TEST FILLING" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "\x1b[32m \x1b[3m Successful filling ! \x1b[0m" << std::endl;
    delete [] mirror;//
    return 0;
}