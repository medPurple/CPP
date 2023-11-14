#include "ScalarConverter.hpp"

bool pseudoLitteral(std::string str){
	
	int i = 0;

	std::string list[6] = {"-inff","+inff","nanf","-inf","+inf","nan"};
	while (i < 6){
		if (list[i] == str)
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << str << std::endl
						<< "double\t: " << "-inf" << std::endl;
			return true;
		case 1:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << str << std::endl
						<< "double\t: " << "+inf" << std::endl;
			return true;
		case 2:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << str << std::endl
						<< "double\t: " << "nan" << std::endl;
			return true;
		case 3:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "-inff" << std::endl
						<< "double\t: " << str << std::endl;
			return true;
		case 4:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "+inff" << std::endl
						<< "double\t: " << str << std::endl;
			return true;
		case 5:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "nanf" << std::endl
						<< "double\t: " << str << std::endl;
			return true;				
		default:
			return false;
	}	
}

void char_converter(std::string str){

	std::cout	<< "\t[" << str << "]" << std::endl 
				<< "char\t: " << static_cast<const char>(str[0]) << std::endl 
				<< "int\t: " << static_cast<const int>(str[0]) << std::endl
				<< "float\t: " << static_cast<const float>(str[0]) << ".0f" <<std::endl
				<< "double\t: " << static_cast<const double>(str[0]) << ".0" << std::endl;
	return;
}

void int_converter(std::string str){

	long nb = strtol(str.c_str(), NULL, 10);
	std::cout	<< "\t[" << str << "]" << std::endl 
				<< "char\t: " << IMPOSSIBLE << std::endl;
	if (nb < -2147483648 || nb  > 2147483647)
		std::cout 	<< "int\t: " << INTLIMIT << std::endl;
	else
		std::cout << "int\t: " << static_cast<const int>(nb) << std::endl;
	if (nb <= 1000000 && nb >= -1000000){
		std::cout 	<< "float\t: " << static_cast<const float>(nb) << ".0f" <<std::endl
					<< "double\t: " << static_cast<const double>(nb) << ".0" << std::endl;}
	else{
		std::cout 	<< "float\t: " << static_cast<const float>(nb) << "f" <<std::endl
					<< "double\t: " << static_cast<const double>(nb) << std::endl;}
}

void float_converter(std::string str){
	int dot = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '.')
			dot++;
	std::cout	<< "\t[" << str << "]" << std::endl 
				<< "char\t: " << IMPOSSIBLE << std::endl;
	float nb = strtof(str.c_str(), NULL);
	if (nb < (float)-2147483648 || nb  > (float)2147483647)
		std::cout 	<< "int\t: " << INTLIMIT << std::endl;
	else
		std::cout << "int\t: " << static_cast<const int>(nb) << std::endl;
	std::cout 	<< "float\t: " << str << std::endl;
	if (dot == 1)
		std::cout 	<< "double\t: " <<  static_cast<const double>(nb) << std::endl;
	else
		std::cout 	<< "double\t: " <<  static_cast<const double>(nb) << ".0" << std::endl;
}

void double_converter(std::string str){
	int dot = 0;
	for (int i = 0; str[i]; i++)
		if (str[i] == '.')
			dot++;
	double nb = strtod(str.c_str(), NULL);
	std::cout	<< "\t[" << str << "]" << std::endl 
				<< "char\t: " << IMPOSSIBLE << std::endl;
	if (nb < (double)-2147483648 || nb  > (double)2147483647)
		std::cout 	<< "int\t: " << INTLIMIT << std::endl;
	else
		std::cout << "int\t: " << static_cast<const int>(nb) << std::endl;
	if (dot == 1)
		std::cout 	<< "float\t: " <<  static_cast<const float>(nb) << "f" << std::endl;
	else
		std::cout 	<< "float\t: " <<  static_cast<const float>(nb) << ".0f" << std::endl;
	std::cout 	<< "double\t: " << str << std::endl;

}

std::string getType(std::string str){
	int dot = 0;
	bool number = true;
	int f = 0;
	int sign = 0;
	for (int i = 0; str[i]; i++){
		if (str[i] == '.')
			dot++;
		if (str[i] == '.' && (!isdigit(str[i + 1]) || !str[i - 1]))
			return "error";}
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') \
		&&  str[i] != '.'  \
		&& str[i] != 'f' \
		&&  str[i] != '-' \
		&&  str[i] != '+')
			number = false;
		if (str[i] == '-' || str[i] == '+')
		{
			if ((str[i] == '-' || str[i] == '+') && i != 0 )
				return "error"; 
			sign++;
		}
		if (str[i] == 'f')
			f++;
	}
	if (str[str.length() - 1] == 'f' && dot < 2 && number == true && sign < 2 && f < 2)
		return "float";
	else if ( dot == 1 && number == true && sign < 2 && f < 1)
		return "double";
	else if (dot < 1 && number == true && sign < 2 && f < 1)
		return "int";
	else if (dot == 0 && number == false && str.length() == 1)
		return "char";
	else
		return "error";
}