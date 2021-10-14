//my code goes here
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::makeDeposit( int deposit )
{
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    _nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (_amount >= withdrawal)
    {
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        return (1);
    }
    else
        return (0);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"<< "amount:"<< _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";"<< "withdrawals:"<< _nbWithdrawals <<";\n";
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:";
    std::cout << _nbAccounts << ";";
    std::cout << "total:";
    std::cout << _totalAmount << ";";
    std::cout << "deposits:";
    std::cout << _totalNbDeposits << ";";
    std::cout << "withdrawals:";
    std::cout << _totalNbWithdrawals << "\n";
}
void	Account::_displayTimestamp( void )
{
    time_t current = time(0);
    tm *local_time = localtime(&current);

    std::cout << 1900 + local_time->tm_year;
    std::cout << 1 + local_time->tm_mon;
    std::cout << local_time->tm_mday;
    std::cout << "_";
    std::cout << local_time->tm_hour;
    std::cout << local_time->tm_min ;
    std::cout << local_time->tm_sec;
    std::cout << " ";
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"<< "amount:"<< _amount <<";created\n";
}
Account::~Account()
{
    std::cout << "index:" << _accountIndex << ";"<< "amount:"<< _amount <<";closed\n";
}
