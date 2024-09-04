#include "../Headers/savings.h"
#include <iostream>
#include <string>
using namespace std;

savingsAccount::savingsAccount(string owner, string num, string dt, double bal):BankAccount(owner, num, dt, bal)
{}
savingsAccount::savingsAccount():BankAccount()
{}

double savingsAccount::calculateInterest(string today)
{
	if (accountCheck())
        	return calculateDays(today) / 365 * INTEREST_RATE / 100 * balance;
	else return -1;
}

double savingsAccount::checkBalance(string today)
{
	updateBalance(today);
	return balance;
}

void savingsAccount::updateBalance(string today)
{
	double interest = calculateInterest(today);
	if (interest)
		balance += interest;
}

void savingsAccount::withdraw(double amount, string today)
{
	if (accountCheck())
	{
		updateBalance(today);
		if (amount > balance)
			cout << "INVALID TRANSACTION" << endl;
		else
		{
			balance -= amount;
			cout << "TRANSACTION SUCCESSFUL" << endl;
			cout << "The amount of " << amount << " has been withdrawn" << endl;
			cout << "Your remaining balance is :" << balance << endl;
		}
	}
}
