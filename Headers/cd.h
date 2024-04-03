#ifndef CD_H
#define CD_H
#include "Bank.h"
class certificateOfDeposit: public BankAccount
{
	const double INTEREST = 5.02;
	const int MIN_MATURITY = 6;
	int maturity;
	public:
	certificateOfDeposit();
	certificateOfDeposit(string owner, string accNum, string dt,int months_to_mature, double bal);
        void withdraw(double amount, string today);
	int setMaturity(int m);
	void penalty();
	void penaltyCheck(string today);
	double updateBalance(string today);
	double calculateInterest(string today);
	void deposit(double amount, string today);
	double checkBalance(string today);
};
#endif
