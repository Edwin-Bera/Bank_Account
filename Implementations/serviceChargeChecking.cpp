#include "../Headers/serviceChargeChecking.h"
#include <string>
#include <iostream>
using namespace std;

serviceChargeChecking::serviceChargeChecking(string owner, string num, string dt, double bal):CheckingAccount(owner, num, dt, bal)
{
}

serviceChargeChecking::serviceChargeChecking():CheckingAccount()
{}
double serviceChargeChecking::calculateServiceCharge(string today)
{
	if (accountCheck())
		return calculateDays(today) / 30 * monthlyCharge;
	else
		return -1;
}
void serviceChargeChecking::updateBalance(string today)
{
	double charge =calculateServiceCharge(today);
	if (charge)
		balance -= charge;
}
 
double serviceChargeChecking::checkBalance(string today)
{
	updateBalance(today);
	return balance;
}

double serviceChargeChecking::write_check(double amount, string today, string recipient)
{
	if (!accountCheck())
		return -1;

	updateBalance(today);
	if (!compareDates(today) || balance < amount)
	{
		cout << "Invalid transaction" << endl;
		return 0.0;
	}
	balance -= amount;

	cout << "Account Holder: " << name << endl;
	cout << "Recipient: 	 " << recipient << endl;
	cout << "Amount:	 " << amount << endl;
	cout << "Date:		 " << today << endl;
	return amount;
	
}

