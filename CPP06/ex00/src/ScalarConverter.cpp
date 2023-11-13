#include "ScalarConverter.hpp"




/*----------------- Coplien ------------- */

ScalarConverter::ScalarConverter(){

}

ScalarConverter::ScalarConverter(const ScalarConverter& rhs){
    *this = rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& rhs){
    if (this != &rhs)
        *this = rhs;
    return *this;
}

ScalarConverter::~ScalarConverter(){

}


/*---------------- Operator ------------- */

/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

void ScalarConverter::displayError(std::string msg){

    std::cerr << "\e[31m"<< "[Error]" << "\e[0m" <<std::endl;
    std::cerr << ">>>>>>>\t" << msg << "\n" <<std::endl;
}

void ScalarConverter::conversion(std::string value){

    for (int i = 0; value[i]; i++)
        if (std::isprint(value[i]) !=  true)
            ScalarConverter::displayError(NOPRINT); return;
    
    
}

/*--------------- Exception ------------- */
