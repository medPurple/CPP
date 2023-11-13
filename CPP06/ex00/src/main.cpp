#include "ScalarConverter.hpp"

int main(void)
{
    ScalarConverter::conversion("10");
    ScalarConverter::conversion("+inff");
    ScalarConverter::conversion("-inff");
    ScalarConverter::conversion("nanf");
    ScalarConverter::conversion("+inf");
    ScalarConverter::conversion("-inf");
    ScalarConverter::conversion("nan");
    ScalarConverter::conversion("\t");
    return 0;
}