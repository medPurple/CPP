#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    std::cout << "----- TEST CHAR ---------" << std::endl;
    ScalarConverter::convert("TEST");
    std::cout << std::endl;
    ScalarConverter::convert("c");
    std::cout << std::endl;
    ScalarConverter::convert("-c");
    std::cout << std::endl;
    ScalarConverter::convert("+c");
    std::cout << std::endl;
     ScalarConverter::convert("\0");
    std::cout << std::endl;

    std::cout << "----- TEST INT ---------" << std::endl;
    ScalarConverter::convert("10");
    std::cout << std::endl;
    ScalarConverter::convert("42");
    std::cout << std::endl;
    ScalarConverter::convert("-10");
    std::cout << std::endl;
    ScalarConverter::convert("+10");
    std::cout << std::endl;
    ScalarConverter::convert("++++++++++10");
    std::cout << std::endl;
    ScalarConverter::convert("1+0");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483648");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483649");
    std::cout << std::endl;
    ScalarConverter::convert("2147483647");
    std::cout << std::endl;
    ScalarConverter::convert("2147483648");
    std::cout << std::endl;

    std::cout << "----- TEST FLOAT ---------" << std::endl;

    ScalarConverter::convert(".0f");
    std::cout << std::endl;
    ScalarConverter::convert(".0f");
    std::cout << std::endl;
    ScalarConverter::convert("0.0f");
    std::cout << std::endl;
    ScalarConverter::convert("4ff");
    std::cout << std::endl;
    ScalarConverter::convert("4.f");
    std::cout << std::endl;
    ScalarConverter::convert("4f1");
    std::cout << std::endl;
    ScalarConverter::convert("2147483648f");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483649f");
    std::cout << std::endl;    
    ScalarConverter::convert("4.2.f");
    std::cout << std::endl;
    ScalarConverter::convert("4.2f");
    std::cout << std::endl;
    ScalarConverter::convert("-4.2f");
    std::cout << std::endl;
    ScalarConverter::convert("-4.0f");
    std::cout << std::endl;
    ScalarConverter::convert("-4.af");



    std::cout << "----- TEST DOUBLE ---------" << std::endl;

    ScalarConverter::convert("1.0");
    std::cout << std::endl;
    ScalarConverter::convert("2147483648.0");
    std::cout << std::endl;
    ScalarConverter::convert("-2147483649.0");
    std::cout << std::endl;  
    ScalarConverter::convert("4.2.");
    std::cout << std::endl;
    ScalarConverter::convert("4.2");
    std::cout << std::endl;
    ScalarConverter::convert("-4.2");
    std::cout << std::endl;
    ScalarConverter::convert("-4.a");

    std::cout << "----- TEST PSEUDOLITTERAL ---------" << std::endl;

    ScalarConverter::convert("+inff");
    std::cout << std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    std::cout << "--------- TEST ERROR -----------------" << std::endl;
    ScalarConverter::convert("\t");

    std::cout << "--------- TEST PERSO -----------------" << std::endl;
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    return 0;
}