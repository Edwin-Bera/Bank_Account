#include "../Headers/highInterestSavings.h"
#include <string>
#include <iostream>
using namespace std;

highInterestSavings::highInterestSavings():savingsAccount()
{}
highInterestSavings::highInterestSavings(string owner, string num, string dt, double bal):savingsAccount(owner, num, dt, bal)
{
	if (bal < MINIMUM_BALANCE)
	{
   		set_Name("");
        	set_Num("");
        	set_Bal(0);
        	set_Date("0/0/0");
	}
		
}
double highInterestSavings::calculateInterest(string today)
{
	if (accountCheck())
		return calculateDays(today) / 365 * HIGHER_INTEREST / 100 * balance;
	else
		return -1;
}
void highInterestSavings::withdraw(double amount, string today)
{
	if (!accountCheck())
	{
		updateBalance(today);
		if (balance - amount < MINIMUM_BALANCE)
			cout << "Invalid Transaction" << endl;
		else
		{
			balance -= amount;
			cout << "TRANSACTION SUCCESSFUL" << endl;
			cout << "The amount of " << amount << " has been withdrawn" << endl;
			cout << "Your remaining balance is :" << balance << endl;
		}
	}
}
