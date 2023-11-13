#pragma once

#include <iostream>


class ScalarConverter
{
public			:
                    static void conversion(std::string value);
                    static void displayError(std::string msg);

protected   	:
private     	:
// Coplien
                    ScalarConverter();
                    ScalarConverter(const ScalarConverter& rhs);
                    ScalarConverter &operator=(const ScalarConverter& rhs);
                    ~ScalarConverter();

};
std::ostream& operator<<(std::ostream& o, const ScalarConverter& rhs);

#define NOPRINT "This input isn't a printable character"
#define IMPOSSIBLE "Impossible operation"
#define NOSCALAR    "This input isn't a scalar"