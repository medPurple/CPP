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

void displayError(std::string msg, std::string value){

    std::cerr << "\e[31m"<< "[Error]" << "\e[0m" << " : [" << value << "]" << std::endl;
    std::cerr << ">>>>>>>\t" << msg << "\n" <<std::endl;
}

void ScalarConverter::convert(std::string value){

    for (int i = 0; value[i]; i++)
    {
        if (std::isgraph(value[i]) ==  false){
            displayError(NOPRINT, value);
            return;}
        if (value[i] == '\0' || isspace(value[i]) == true){
            displayError(NOPRINT, value);
            return;}
    }
    if (pseudoLitteral(value) == false)
    {
        std::string str = getType(value);
        std::cout << str;
        std::string list[4] = {"char", "int", "float", "double"};
        int i = 0;
        while (i < 4){
            if (list[i] == str)
                break;
            i++;}
        switch (i)
        {
            case CHAR:
                char_converter(value);
                break;
            case INT:
                int_converter(value);
                break;
            case FLOAT:
                float_converter(value);
                break;
            case DOUBLE:
                double_converter(value);
                break;
            default:
                displayError(IMPOSSIBLE, value);
                break;
        }
    }
}

/*--------------- Exception ------------- */