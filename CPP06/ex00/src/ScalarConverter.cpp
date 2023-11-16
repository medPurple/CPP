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

    if (value.length() < 1) {displayError(NOPRINT, value);return;}
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
        std::string list[4] = {"char", "int", "float", "double"};
        int i = 0;
        while (i < 4){
            if (list[i] == str)
                break;
            i++;}
        std::cout << list[i] << std::endl;
        switch (i)
        {
            case CHAR:
                std::cout << "\t[" << value << "]" << std::endl; 
                char_converter(value);
                break;
            case INT:
                std::cout << "\t[" << value << "]" << std::endl; 
                int_converter(value);
                break;
            case FLOAT:
                std::cout << "\t[" << value << "]" << std::endl; 
                float_converter(value);
                break;
            case DOUBLE:
                std::cout << "\t[" << value << "]" << std::endl; 
                double_converter(value);
                break;
            default:
                displayError(IMPOSSIBLE, value);
                break;
        }
    }
}

/*--------------- Exception ------------- */

const char*	CharConversion::what() const throw(){
	return IMPOSSIBLE;
}

const char*	Isprintable::what() const throw(){
	return NOPRINT;
}
const char*	IntConversionO::what() const throw(){
	return "\e[0m \e[3m\e[31m Overflow \e[0m";
}

const char*	IntConversionU::what() const throw(){
	return "\e[0m \e[3m\e[31m Underflow \e[0m";
}