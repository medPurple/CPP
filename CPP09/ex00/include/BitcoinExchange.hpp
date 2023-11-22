#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include <regex>
#include <string>
#include <limits>

struct BitcoinPrice {
    std::string date;
    double value;
};

class BitcoinExchange {
    public:
        ~BitcoinExchange();
    // Parametric 
        BitcoinExchange(const std::string& databaseFilename);
        
    // Function
        void calculateBitcoinValue(const std::string& inputFilename);

    // Exception
        class   NoDateException : public std::exception {
                public:
                    virtual const char* what() const throw();
            };
        class   NoRateException : public std::exception {
                public:
                    virtual const char* what() const throw();
            };
    private:
    // Coplien
                BitcoinExchange();
                BitcoinExchange(const BitcoinExchange& rhs);
                BitcoinExchange &operator=(const BitcoinExchange& rhs);

                std::vector<BitcoinPrice> bitcoinPrices;
                double getExchangeRate(const std::string& dateStr);
                std::string findClosestDate(const std::string& targetDate);

                void _display_constructor(std::string msg){
                    std::cout << "\x1b[33m \x1b[3m" << msg << "\x1b[0m" << std::endl;
                } 
        
};


static bool msg_const = false;

#define BE_DC "[Default] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_PC "[Parametric] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_CC "[Copy] Constructor called for BITCOIN_EXCHANGE CLASS"
#define BE_AO "[Attribution] Operator called for BITCOIN_EXCHANGE CLASS"
#define BE_DD "[Default] Destructor called for BITCOIN_EXCHANGE CLASS"