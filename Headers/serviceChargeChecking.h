#ifndef SERVCHECK_H
#define SERVCHECK_H
#include "Check.h"
class ServiceChargeChecking: public CheckingAccount, public BankAccount
{
	int checkCount;
	const int checkLimit = 3;
	public:
		calculateServiceCharge(string today);
		double checkBalance(string today);

		virtual double write_check(double amount, string dt, string recipient) = 0;
}
