#include "RNP.hpp"

int main(int ac, char **av) {
    
        
    std::cout << "-- TEST SUBJECT --" << std::endl;
    try{
        int result = evaluateRPN(const_cast<char *>("8 9 * 9 - 9 - 9 - 4 - 1 +"));
        std::cout << "\tResult: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;
    try{
        int result = evaluateRPN(const_cast<char *>("7 7 * 7 -"));
        std::cout << "\tResult: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;

    try{
        int result = evaluateRPN(const_cast<char *>("1 2 * 2 / 2 * 2 4 - +"));
        std::cout << "\tResult: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;   
    try{
        int result = evaluateRPN(const_cast<char *>("(1 + 1)"));
        std::cout << "\tResult: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;

    std::cout << "-- PERSONNAL TEST --" << std::endl;


    try{
        int result = evaluateRPN(const_cast<char *>("+ 1"));
        std::cout << "Result: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;

    try{
        int result = evaluateRPN(const_cast<char *>("1 1"));
        std::cout << "Result: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;

    try{
        int result = evaluateRPN(const_cast<char *>("+"));
        std::cout << "Result: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;

    try{
        int result = evaluateRPN(const_cast<char *>("11 12 +"));
        std::cout << "Result: " << result << std::endl;}
    catch (std::exception &e){std::cout << e.what() << std::endl;}
    std::cout << std::endl;
    if (ac == 2 && av[1][0]){
        try{
            int result = evaluateRPN(av[1]);
            std::cout << "Result: " << result << std::endl;
        }
        catch (std::exception &e){std::cout << e.what() << std::endl;}
    }

    return 0;
}