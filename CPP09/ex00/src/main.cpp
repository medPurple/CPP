#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc != 2){
		std::cout << "Usage : ./btc <input file>" << std::endl;
		return (1);
	}
	(void) argv;
	try {
		BitcoinExchange data;
		data.calcValue(std::string (argv[1]));
	}
	catch (std::exception &e){std::cout << e.what() <<std::endl;}
}
