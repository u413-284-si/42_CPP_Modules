/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:49:04 by sqiu              #+#    #+#             */
/*   Updated: 2024/02/14 16:29:44 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int	_nbAccounts = 0;
int	_totalAmount = 0;
int	_totalNbDeposits = 0;
int	_totalNbWithdrawals = 0;

// Constructor with _amount initialised to initial_deposit
Account::Account(int initial_deposit):_amount(initial_deposit),
									  _nbDeposits(1){
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << std::endl; 
	return;
}

// Destructor
Account::~Account(void){
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed" << std::endl; 
	return;
}

int	Account::getNbAccounts(void){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount(void){
	return Account::_totalAmount;
}

int	Account::getNbDeposits(void){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << ";\n";
}

void	Account::makeDeposit(int deposit){
	_amount += deposit;
	_nbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal){
	if (_amount >= withdrawal){
		_amount -= withdrawal;
		_nbWithdrawals++;
		return true;
	}
	return false;
}

int		Account::checkAmount(void) const{
	return _amount;
}

void	Account::displayStatus(void) const{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";\n";
}

void	Account::_displayTimestamp(void){
	std::cout << "[20240214_162033]	";
}
