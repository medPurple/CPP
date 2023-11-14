#pragma once

#include <iostream>
#include <stdlib.h>


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
std::ostream& operator<<(std::ostream& o, const ScalarConverter& rhs);

bool        pseudoLitteral(std::string str);
std::string getType(std::string str);
void        char_converter(std::string str);
void        int_converter(std::string str);
void        float_converter(std::string str);
void        double_converter(std::string str);
void        displayError(std::string msg, std::string value);
#define NOPRINT "This input isn't a printable character"
#define IMPOSSIBLE "Impossible operation"
#define INTLIMIT "Int limit reached"
#define NOSCALAR    "This input isn't a scalar"
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
