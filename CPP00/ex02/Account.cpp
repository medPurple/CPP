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




// https://github.com/tblaase/CPP-Module-00/blob/main/ex02/src/Account.cpp
// https://github.com/izenynn/cpp-modules/blob/main/cpp-module-00/ex02/Account.cpp