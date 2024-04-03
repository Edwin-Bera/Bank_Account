#ifndef HISA_H
#define HISA_H
#include "savings.h"
class highInterestSavings: public savingsAccount
{
	const double HIGHER_INTEREST = 3.56, MINIMUM_BALANCE = 250;
	public:
	highInterestSavings(string owner, string num, string dt, double bal);
        highInterestSavings();
	double calculateInterest(string today);
	void withdraw(double amount, string today);
};
#endif
