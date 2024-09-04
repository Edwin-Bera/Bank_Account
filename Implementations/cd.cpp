#include "../Headers/cd.h"
#include <iostream>
#include <string>
using namespace std;
int certificateOfDeposit::setMaturity(int m)
{
	if (m > 6)
		maturity = m;
	else
		maturity = 0;
	return maturity;
}
certificateOfDeposit::certificateOfDeposit(string owner, string accNum, string dt, int months_to_mature, double bal)
	:BankAccount(owner, accNum, dt, bal)
{
	if (!setMaturity(months_to_mature))
	{
		set_Name("");
		set_Num("");
		set_Bal(0);
		set_Date("");
	}
}

certificateOfDeposit::certificateOfDeposit()
{
	setMaturity(0);
}

double certificateOfDeposit::calculateInterest(string today)
{
	if (!accountCheck())
		return -1;
	return INTEREST / 100 * balance * (calculateDays(today) / 365);
}

double certificateOfDeposit:: updateBalance(string today)
{
	double i = calculateInterest(today);
	if (!i)
		return i;
	balance += i;
	set_Date(today);
	return balance;
}

void certificateOfDeposit::penalty()
{
	balance -= 0.05 * balance;
}

void certificateOfDeposit::penaltyCheck(string today)
{
	if (accountCheck())
	{
		if (calculateDays(today) / 30 < maturity)
			penalty();
	}
}


void certificateOfDeposit::withdraw(double amount, string today)
{
	updateBalance(today);
	if (amount > balance - balance * 0.05)
	{
		penaltyCheck(today);
		balance -= amount;
		cout << "The Transactions was SUCCESSFULL! \n The Amount of " << amount << " Has been redacted from your funds." << endl;
		cout << "Remaining Balance: " << balance << endl;
	}
	else
		cout << "Transaction Failed" << endl;
}


void certificateOfDeposit::deposit(double amount, string today)
{
	if (!accountCheck())
	{
		updateBalance(today);
		if (amount)
		{
			balance += amount;
		}
		else
			cout << "Invalid Operation" << endl;

	}
}


double certificateOfDeposit::checkBalance(string today)
{
	if (updateBalance(today) == -1)
		return -1;
	cout << "BALANCE: " << balance <<endl;
	return retrieve_Bal();
}
