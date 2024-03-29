#include "../Headers/noServiceChargeChecking.h"
#include <iostream>
#include <string>
using namespace std;
noServiceChargeChecking::noServiceChargeChecking(string owner, string num, string dt, double bal):CheckingAccount(owner, num, dt, bal)
{
}

noServiceChargeChecking::noServiceChargeChecking():CheckingAccount()
{}
double noServiceChargeChecking::calculateInterest(string today)
{
	return calculateDays(today) / 365 * annualInterest;
}

void noServiceChargeChecking::updateBalance(string today)
{
	double interest = calculateInterest(today);
        if (interest)
                balance += interest;
}
double noServiceChargeChecking::checkBalance(string today)
{
	updateBalance(today);
	return balance;
}

 double noServiceChargeChecking::write_check(double amount, string today, string recipient)
{

        updateBalance(today);
        if (!compareDates(today) || balance < amount)
        {
                cout << "Invalid transaction" << endl;
                return 0.0;
        }
        balance -= amount;

        cout << "Account Holder: " << name << endl;
        cout << "Recipient:      " << recipient << endl;
        cout << "Amount:         " << amount << endl;
        cout << "Date:           " << today << endl;
        return amount;

}

