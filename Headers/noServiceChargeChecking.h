#ifndef NSCC_H
#define NSCC_H
#include "check.h"
class noServiceChargeChecking: public CheckingAccount
{
	const double annualInterest = 2.29, minimun_bal = 350;
	public:
  	noServiceChargeChecking();
  	noServiceChargeChecking(string owner, string num, string dt, double bal);
 	double write_check(double amount, string today, string recipient);
	double calculateInterest(string today);
	double checkBalance(string today);
	void updateBalance(string today);
};
#endif
