#ifndef SERVCHECK_H
#define SERVCHECK_H
#include "Check.h"
class serviceChargeChecking: public CheckingAccount
{
	int checkCount;
	const int monthlyLimit = 3;
	double monthlyCharge = 3.70;
	public:
	
		serviceChargeChecking(string owner, string num, string dt, double bal); 
		double calculateServiceCharge(string today);
		double checkBalance(string today);
		void updateBalance(string today);

		double write_check(double amount, string today, string recipient);
};
#endif
