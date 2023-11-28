#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <limits>


class BitcoinExchange{
	public :
	
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange operator=(const BitcoinExchange &rhs);
		void calcValue(std::string input);

        class ErrorException : public std::exception {
        public:
            virtual const char* what() const throw();

        };

	private :
		std::map<std::string, double>	_data;

		void fill_data(std::ifstream &file);
		std::string checkDate(std::string date, std::string line);
        double checkAmount(std::string amount, std::string line);
		void addValue(std::map<std::string, double> &map, std::string date, double amount);
        
        void _display_constructor(std::string msg) {
            std::cout << "\x1b[33m \x1b[3m" << msg << "\x1b[0m" << std::endl;
        }
	
};

static bool msg_const = false;

#define BE_DC "[Default] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_PC "[Parametric] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_CC "[Copy] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_AO "[Attribution] Operator called for BITCOIN_EXCHANGE CLASS"
#define BE_DD "[Default] Destructor called for BITCOIN_EXCHANGE CLASS"
