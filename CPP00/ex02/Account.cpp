#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(){

	this->_accountIndex = this->_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	
	std::cout
				<< "index:" << this->_accountIndex << ";"
				<< "amount" << this->_amount << ";"
				<< "created" << std::endl;
};

Account::Account( int initial_deposit ) {
	
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();

	std::cout
				<< "index:" << this->_accountIndex << ";"
				<< "amount" << this->_amount << ";"
				<< "created" << std::endl;
};

Account::~Account() {
	
	Account::_nbAccounts--;
	Account::_displayTimestamp();

	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<
	"index:" <<	this->_accountIndex << ";" <<
	"p_amount" << this->checkAmount() << ";" <<
	"deposit" << deposit << ";";

	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";";
	
	if (withdrawal > checkAmount())
		return(std::cout << "withdrawal:refused" << std::endl, false);
	else
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		std::cout <<
		"withdrawal:" << withdrawal << ";" <<
		"amount:" << this->checkAmount() << ";" <<
		"nb_withdrawals:" << this->_nbWithdrawals <<
		std::endl;

		return (true);
	}
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"amount:" << this->checkAmount() << ";" <<
	"deposits:" << this->_nbDeposits << ";" <<
	"withdrawals:" << this->_nbWithdrawals <<
	std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t actual = std::time(NULL);
	struct tm a_time = *std::localtime(&actual);

	std::cout << "[" << a_time.tm_year + 1900 <<
	std::setfill('0') << std::setw(2) << a_time.tm_mon + 1 <<
	std::setfill('0') << std::setw(2) << a_time.tm_mday << "_" <<
	std::setfill('0') << std::setw(2) << a_time.tm_hour <<
	std::setfill('0') << std::setw(2) << a_time.tm_min <<
	std::setfill('0') << std::setw(2) << a_time.tm_sec <<
	"] ";
}
// https://github.com/tblaase/CPP-Module-00/blob/main/ex02/src/Account.cpp
// https://github.com/izenynn/cpp-modules/blob/main/cpp-module-00/ex02/Account.cpp