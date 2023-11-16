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
						<< "float\t: " << "\e[3m\e[32m" << str << "\e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m -inf \e[0m" << std::endl;
			return true;
		case 1:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "\e[3m\e[32m" << str << "\e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m +inf \e[0m" << std::endl;
			return true;
		case 2:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "\e[3m\e[32m" << str << "\e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m nan \e[0m" << std::endl;
			return true;
		case 3:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "\e[3m\e[32m -inff \e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m" << str << "\e[0m" << std::endl;
			return true;
		case 4:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "\e[3m\e[32m +inff \e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m" << str << "\e[0m" <<  std::endl;
			return true;
		case 5:
			std::cout 	<< "\t[" << str << "]" << std::endl
						<< "char\t: " << IMPOSSIBLE << std::endl
						<< "int\t: " << IMPOSSIBLE << std::endl
						<< "float\t: " << "\e[3m\e[32m nanf \e[0m" << std::endl
						<< "double\t: " << "\e[3m\e[32m" << str << "\e[0m" << std::endl;
			return true;				
		default:
			return false;
	}	
}

void char_converter(std::string str){
	try{
		std::cout << "char:\t \e[3m\e[32m";
		char a = toChar(str);
		std::cout << a << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "int:\t \e[3m\e[32m";
		int b = toInt(str);
		std::cout << b << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	float f = toFloat(str);
	std::cout << "float:\t \e[3m\e[32m" << std::fixed << std::setprecision(1) << f << "f" << "\e[0m" << std::endl;
	double d = toDouble(str);
	std::cout << "double:\t \e[3m\e[32m" << d << "\e[0m" << std::endl;
}

void int_converter(std::string str){
	try{
		std::cout << "char:\t \e[3m\e[32m";
		char a = toChar(str);
		std::cout << a << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "int:\t \e[3m\e[32m";
		int b = toInt(str);
		std::cout << b << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	float f = toFloat(str);
	std::cout << "float:\t \e[3m\e[32m" << std::fixed << std::setprecision(1) << f << "f" << "\e[0m" << std::endl;
	double d = toDouble(str);
	std::cout << "double:\t \e[3m\e[32m" << d << "\e[0m" << std::endl;
}

void float_converter(std::string str){
	try{
		std::cout << "char: ";
		char a = toChar(str);
		std::cout << a << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "int:\t \e[3m\e[32m";
		int b = toInt(str);
		std::cout << b << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	float f = toFloat(str);
	std::cout << "float:\t \e[3m\e[32m" << std::fixed << std::setprecision(1) << f << "f" << "\e[0m" << std::endl;
	double d = toDouble(str);
	std::cout << "double:\t \e[3m\e[32m" << d << "\e[0m" << std::endl;
}

void double_converter(std::string str){
	try{
		std::cout << "char:\t \e[3m\e[32m";
		char a = toChar(str);
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try{
		std::cout << "int:\t \e[3m\e[32m";
		int b = toInt(str);
		std::cout << b << "\e[0m" << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	float f = toFloat(str);
	std::cout << "float:\t \e[3m\e[32m" << std::fixed << std::setprecision(1) << f << "f" << "\e[0m" << std::endl;
	double d = toDouble(str);
	std::cout << "double:\t \e[3m\e[32m" << d << "\e[0m" << std::endl;
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
	else if (str.length() == 1 && isChar(str) == true)
		return "char";
	else
		return "error";
}

char	toChar(std::string str){
	char c;
	double num = atof(str.c_str());
	if (isChar(str) == true)
		c = static_cast<const char>(str[0]);
	else{
			if (num < 33 || num > 126)
				throw Isprintable();
			c = static_cast<const char>(num);
	}

	return c;
}

int	toInt(std::string str){
	char	*end;
	long	num;
	num = strtol(str.c_str(), &end, 10);
	if (num > INT_MAX)
		throw IntConversionO();
	if (num < INT_MIN)
		throw IntConversionU();
	if (isChar(str) == false)
		num = strtol(str.c_str(), &end, 10);
	else
		num = static_cast<const int>(str[0]);
	return num;
}

float	toFloat(std::string str){
	char	*end;
	float	num;
	if (isChar(str) == false)
		num = strtof(str.c_str(), &end);
	else
		num = static_cast<const float>(str[0]);
	return num;
}

double	toDouble(std::string str){
	char	*end;
	double	num;
	if (isChar(str) == false)
		num = strtod(str.c_str(), &end);
	else
		num = static_cast<const double>(str[0]);
	return num;
}

bool	isChar(std::string str) {
	if (str.length() == 1 && std::isalpha(str[0]))
		return true;
	return false;
}