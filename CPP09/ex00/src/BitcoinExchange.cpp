#include "BitcoinExchange.hpp"




/*----------------- Coplien ------------- */

BitcoinExchange::BitcoinExchange(){
    if (msg_const == true)
        _display_constructor(BE_DC);
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFilename) {
    std::ifstream file(databaseFilename.c_str());  // c_str() is needed in C++98
    if (!file.is_open()) {
        std::cerr << "Error: could not open bitcoin database file." << std::endl;
        return;
    }

    std::string line;
    std::regex pattern("\\d{4}-\\d{2}-\\d{2},\\d+(\\.\\d+)?");
    
    while (std::getline(file, line)) {
        if (line.find("date,exchange_rate") != std::string::npos)
            continue;
        if (!std::regex_match(line, pattern)){
            std::cerr << "Error: Invalid data format in the bitcoin database file: " << line << std::endl;
            continue;
        }
        std::istringstream ss(line);
        BitcoinPrice price;
        std::getline(ss, price.date, ',');
        ss >> price.value;
        bitcoinPrices.push_back(price);
    }
    if (msg_const == true)
        _display_constructor(BE_PC);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs){
    *this = rhs;
    if (msg_const == true)
        _display_constructor(BE_CC);
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& rhs){
    if (this != &rhs)
        *this = rhs;
    if (msg_const == true)
        _display_constructor(BE_AO);
    return *this;
}

BitcoinExchange::~BitcoinExchange(){
    if (msg_const == true)
        _display_constructor(BE_DD);
}


/*---------------- Operator ------------- */


/*---------- Getter / Setter ------------ */


/*--------------- Function -------------- */

void BitcoinExchange::calculateBitcoinValue(const std::string& inputFilename) {
    std::ifstream inputFile(inputFilename.c_str());  // c_str() is needed in C++98
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.find("date | value") != std::string::npos)
            continue;

        std::regex pattern("\\d{4}-\\d{2}-\\d{2} \\| \\d+(\\.\\d+)?");
        std::istringstream ss(line);
        std::string date;
        double value;

        if (!std::regex_match(line, pattern)){
            std::cerr << "Error: Invalid input format: " << line << std::endl;
            continue;
        }
        std::getline(ss, date, '|');
        ss >> value;

        try {
            double exchangeRate = getExchangeRate(date);
            double result = value * exchangeRate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch(std::exception& e) {
		    std::cerr << e.what() << std::endl;}
    }
}

double BitcoinExchange::getExchangeRate(const std::string& dateStr) {
    std::string closestDate = findClosestDate(dateStr);
    std::cout << closestDate << std::endl;
    for (std::vector<BitcoinPrice>::iterator it = bitcoinPrices.begin(); it != bitcoinPrices.end(); ++it) {
        if (it->date == closestDate) {
            return it->value;
        }
    }
    throw NoRateException();
}

std::string BitcoinExchange::findClosestDate(const std::string& targetDate) {
std::vector<BitcoinPrice>::const_iterator itmp;
    for (std::vector<BitcoinPrice>::const_iterator it = bitcoinPrices.begin(); it != bitcoinPrices.end(); ++it) {
        if (it == bitcoinPrices.begin())
            itmp = it;
        if (it->date > targetDate)
           return itmp->date;
        itmp = it;
    }
    throw NoDateException();
}

/*--------------- Exception ------------- */

const char* BitcoinExchange::NoDateException::what() const throw() {
	return "Error: No date found";
}
const char* BitcoinExchange::NoRateException::what() const throw() {
	return "Error: No rate found";
}











