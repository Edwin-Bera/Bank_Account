#ifndef SA_H
#define SA_H
#include "Bank.h"
class savingsAccount: public BankAccount
{
	const double INTEREST_RATE = 2.4;
	public:
	savingsAccount(string owner, string num, string dt, double bal);
	savingsAccount();
	double calculateInterest(string today);
        double checkBalance(string today);
        void updateBalance(string today);
	void withdraw(double amount, string today);
};
#endif
