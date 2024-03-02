#ifndef SERVCHECK_H
#define SERVCHECK_H
#include "Check.h"
class ServiceChargeChecking: public CheckingAccount, public BankAccount
{
	int checkCount;
	const int monthlyLimit = 3;
	public:
	
		serviceChargeChecking(string owner, string num, string dt, double bal); 
		double calculateServiceCharge(string today);
		double checkBalance(string today);
		void updateBalance(string today);

		virtual double write_check(double amount, string dt, string recipient) = 0;
}
