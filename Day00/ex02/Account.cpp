//my code goes here
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::makeDeposit( int deposit )
{
    int x = _amount;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    _nbDeposits++;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";p_amount:" << x;
    std::cout << ";deposit:" << deposit;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_deposits:" << _nbDeposits<<"\n";
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int x = _amount;
    _displayTimestamp();
    if (_amount >= withdrawal)
    {
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        _amount -= withdrawal;
        _nbWithdrawals++;
        std::cout << "index:"<< _accountIndex;
        std::cout << ";p_amount:"<< x;
        std::cout << ";withdrawal:"<< withdrawal;
        std::cout << ";amount:"<< _amount;
        std::cout << ";nb_withdrawals:"<< _nbWithdrawals<<"\n";
        return (1);
    }
    else
    {
        std::cout << "index:" << _accountIndex;
        std::cout << ";p_amount:" << x ;
        std::cout << ";withdrawal:refused\n";
        return (0);
    }
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"<< "amount:"<< _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:"<< _nbWithdrawals <<"\n";
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
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"<< "amount:"<< _amount <<";closed\n";
}
