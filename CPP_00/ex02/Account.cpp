/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:52:27 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/06 12:53:12 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout <<
    "index:" << _accountIndex << ";" <<
    "p_amount:" << checkAmount() << ";" <<
    "deposit:" << deposit << ";";
    _amount += deposit;
    _nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout <<
    "amount:" << checkAmount() << ";" <<
    "nb_deposits:" << _nbDeposits <<
    std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout <<
    "index:" << _accountIndex << ";" <<
    "p_amount:" << checkAmount() << ";";
    if (checkAmount() < withdrawal)
    {
        std::cout <<
        "withdrawal:refused" <<
        std::endl;
        return (false);
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        std::cout <<
        "withdrawal:" << withdrawal << ";" <<
        "amount:" << checkAmount() << ";" <<
        "nb_withdrawals:" << _nbWithdrawals <<
        std::endl;
        return (true);
    }
}

int Account::checkAmount( void ) const {
    return _amount;
}

void    Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout <<
    "index:" << _accountIndex << ";" <<
    "amount:" << checkAmount() << ";" <<
    "deposits:" << _nbDeposits << ";" <<
    "withdrawals:" << _nbWithdrawals <<
    std::endl;
}

void Account::_displayTimestamp( void ) {
    std::time_t now = std::time(NULL);
    std::tm *tm = std::localtime(&now);
    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", tm);
    std::cout << "[" << buffer << "] ";
}