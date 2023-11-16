#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>


class ScalarConverter
{
public			:
                    static void convert(std::string value);

protected   	:
private     	:
// Coplien
                    ScalarConverter();
                    ScalarConverter(const ScalarConverter& rhs);
                    ScalarConverter &operator=(const ScalarConverter& rhs);
                    ~ScalarConverter();

};

bool        pseudoLitteral(std::string str);
std::string getType(std::string str);
void        char_converter(std::string str);
void        int_converter(std::string str);
void        float_converter(std::string str);
void        double_converter(std::string str);
void        displayError(std::string msg, std::string value);
char	    toChar(std::string str);
int	        toInt(std::string str);
float	    toFloat(std::string str);
double  	toDouble(std::string str);
bool	    isChar(std::string str);

    class CharConversion : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class Isprintable : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class IntConversionO : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class IntConversionU : public std::exception {
        public:
            virtual const char* what() const throw();
    };

#define NOPRINT "\e[0m \e[3m\e[31m This input isn't a printable character \e[0m"
#define IMPOSSIBLE "\e[0m \e[3m\e[31m Impossible operation \e[0m"
#define INTLIMIT "\e[0m \e[3m\e[31m Int limit reached \e[0m"
#define NOSCALAR    "\e[0m \e[3m\e[31m This input isn't a scalar \e[0m"
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3


