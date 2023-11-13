#include "ScalarConverter.hpp"

bool pseudoLitteral(std::string str){
	
	int i = 0;

	std::string list[6] = {"-inff","+inff","nanf","-inf","+inf","nan"};
	while (i < 6)
		if (list[i++] == str)
			break;
	switch (i)
	{
		case 0:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << str << std::endl
						<< "double	: " << "-inf" << std::endl;
			return true;
		case 1:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << str << std::endl
						<< "double	: " << "+inf" << std::endl;
			return true;
		case 2:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << str << std::endl
						<< "double	: " << "nan" << std::endl;
			return true;
		case 3:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << "-inff" << std::endl
						<< "double	: " << str << std::endl;
			return true;
		case 4:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << "+inff" << std::endl
						<< "double	: " << str << std::endl;
			return true;
		case 5:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char	: " << IMPOSSIBLE << std::endl
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << "nanf" << std::endl
						<< "double	: " << str << std::endl;
			return true;				
		default:
			return false;
	}	
}

void char_converter(std::string str){

	int dot = 0;
	for (int i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if (!isdigit(str[i]) && str[i] != '.')
		{
			std::cout	<< "\t[" << str << "]" << std::endl 
						<< "char	: " << str << std::endl 
						<< "int		: " << IMPOSSIBLE << std::endl
						<< "float	: " << IMPOSSIBLE << std::endl
						<< "double	: " << IMPOSSIBLE << std::endl;
			return;
		}
		if (str[i] == '.')
			dot++;
	}
	if (dot < 1)\
	{
		std::cout	<< "\t[" << str << "]" << std::endl 
					<< "char	: " << str << std::endl 
					<< "int		: " << IMPOSSIBLE << std::endl
					<< "float	: " << IMPOSSIBLE << std::endl
					<< "double	: " << IMPOSSIBLE << std::endl;
		return;
	}
	long vint = strtol(str.c_str(), NULL, 10);
	float vfloat = static_cast<float>(atof(str.c_str()));
	double vdouble = atof(str.c_str());
	std::cout	<< "\t[" << str << "]" << std::endl 
					<< "char	: " << str << std::endl;
	if (vint > 2147483647 || vint < -2147483647)
		std::cout	<< "int		: " << INTLIMIT << std::endl;
	else
		std::cout	<< "int		: " << vint << std::endl;
	std::cout 	<< "float	: " << vfloat << std::endl
				<< "double	: " << vdouble << std::endl;
	return;
}

void int_converter(std::string str){
	(void)str;
}

void float_converter(std::string str){
		(void)str;

}

void double_converter(std::string str){
		(void)str;

}

std::string getType(std::string str){
	int dot = 0;
	bool number = true;
	for (int i = 0; str[i]; i++)
		if (str[i] == '.')
			dot++;
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') ||  str[i] == '.'  || str[i] == 'f')
			number = false;
	}
	if (str[str.length() - 1] == 'f' && dot == 1 && number == true)
		return "float";
	else if ( dot == 1 && number == true)
		return "double";
	else if (dot < 1 && number == true)
		return "int";
	else if (dot == 0 && number == false)
		return "char";
	else
		return "error";
}