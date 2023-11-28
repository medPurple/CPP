/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purple <medpurple@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:32:12 by amiguez           #+#    #+#             */
/*   Updated: 2023/11/28 07:34:10 by purple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src){(void) src;}
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &rhs){(void) rhs; return *this;}

BitcoinExchange::BitcoinExchange(){
	
	std::ifstream fdata("data.csv");
	if(!fdata.is_open())
		throw ErrorException();

	fill_data(fdata);
	fdata.close();
}

void	BitcoinExchange::fill_data(std::ifstream &file){
	
	std::string line;
	std::string::iterator it;
	
	std::getline(file,line,'\n');
	while (std::getline(file, line, '\n')){
		if (line.find(',') == std::string::npos ){
			file.close();
			throw ErrorException();
		}
		std::string date = line.substr(0, line.find(','));
		std::string amount = line.substr(line.find(',') + 1 , line.length());
		addValue(_data, checkDate(date, line), checkAmount(amount, line));
	}
	//addValue(_data, "0000-00-00", -1);
}


void BitcoinExchange::addValue(std::map<std::string, double> &map, std::string date, double amount){
	map[date] = amount;
}


std::string BitcoinExchange::checkDate(std::string date, std::string line){
	(void)line;

    int	y = -1, m = -1, d = -1;
	
	sscanf(date.c_str(), "%d-%d-%d", &y, &m, &d);

	for (size_t i = 0; i < date.length(); i++){
		if (i == 4 || i == 7){
			if (date[i] != '-')
				throw ErrorException(); // check if the date is valid
		}
		else if (!isdigit(date[i]))
				throw ErrorException(); // check if the date is valid
	}
	if (date.length() != 10)
		throw ErrorException(); // check if the date is valid
	if (y < 0 || y > 2023 || m <= 0 || m > 12 || d <= 0 || d > 31) 
		throw ErrorException();; // check if the date is valid
	return (date);
}

double BitcoinExchange::checkAmount(std::string amount, std::string line){
	char *check;
	
    (void) line;
	if (amount.length() == 0)
		throw ErrorException();
	double dAmount = std::strtod(amount.c_str(), &check);
	if (dAmount < 0 || dAmount > 2147483647)
		throw ErrorException();
	if (check[0])
		throw ErrorException();
	if (amount.find(' ') != std::string::npos)
		throw ErrorException();
	return (dAmount);
}


void BitcoinExchange::calcValue(std::string input){

	std::string line;

	std::ifstream finput(input.c_str());
	if(!finput.is_open())
		throw ErrorException();
	
	std::getline(finput,line,'\n');
	while (std::getline(finput, line, '\n')){
	
	try{
			
		if (line.find(" | ") == std::string::npos )
			throw ErrorException();

		std::string date = checkDate(line.substr(0, line.find(" | ")), line);
		double amount = checkAmount(line.substr(line.find(" | ") + 3 , line.length()), line);
		if (amount > 1000)
			throw ErrorException();

		std::map<std::string, double>::iterator it = _data.upper_bound(date);
		it.operator--();
		if (it == _data.begin())
		    throw ErrorException();

		std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;

	} catch (std::exception &e){
		std::cout <<e.what() << std::endl;
	}
	
	}
	finput.close();
}


const char *BitcoinExchange::ErrorException::what() const throw()
{
	return ("\x1b[31m \x1b[3m Error \x1b[0m");
}