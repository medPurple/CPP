#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    if (msg_const == true)
        _display_constructor(BE_DC);
}

BitcoinExchange::BitcoinExchange(const std::string& databaseFilename) {
    populateBitcoinPrices(databaseFilename);
    if (msg_const == true)
        _display_constructor(BE_PC);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) {
    *this = rhs;
    if (msg_const == true)
        _display_constructor(BE_CC);
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs) {
    if (this != &rhs)
        *this = rhs;
    if (msg_const == true)
        _display_constructor(BE_AO);
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
    if (msg_const == true)
        _display_constructor(BE_DD);
}

void BitcoinExchange::calculateBitcoinValue(const std::string& inputFilename) {
    std::ifstream inputFile(inputFilename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.find("date | value") != std::string::npos)
            continue;

        std::istringstream ss(line);
        std::string date;
        double value;

        ss >> date;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), '|');
        ss >> value;

        try {
            double exchangeRate = getExchangeRate(date);
            double result = value * exchangeRate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

double BitcoinExchange::getExchangeRate(const std::string& dateStr) {
    std::string closestDate = findClosestDate(dateStr);
    std::cout << closestDate << std::endl;

    // Use map.find to look up the value for the date
    std::map<std::string, double>::iterator it = bitcoinPrices.find(closestDate);
    if (it != bitcoinPrices.end()) {
        return it->second;
    }

    throw NoRateException();
}

std::string BitcoinExchange::findClosestDate(const std::string& targetDate) {
    std::map<std::string, double>::const_iterator itmp = bitcoinPrices.begin();
    for (std::map<std::string, double>::const_iterator it = bitcoinPrices.begin(); it != bitcoinPrices.end(); ++it) {
        if (it == bitcoinPrices.begin())
            itmp = it;
        if (it->first > targetDate)
            return itmp->first;
        itmp = it;
    }

    throw NoDateException();
}

void BitcoinExchange::populateBitcoinPrices(const std::string& databaseFilename) {
    std::ifstream file(databaseFilename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open bitcoin database file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.find("date,exchange_rate") != std::string::npos)
            continue;

        std::istringstream ss(line);
        std::string date;
        double value;

        ss >> date;
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        ss >> value;

        bitcoinPrices[date] = value; // Store in the map
    }
}
