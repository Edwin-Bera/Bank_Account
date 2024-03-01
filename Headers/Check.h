#ifndef CHECK_H
#define CHECK_H
#include "../Headers/Bank.h"
#include <string>
using namespace std;
class CheckingAccount: public BankAccount
{
	public:
		virtual double write_check(double amount, string dt, string recipient) = 0;
		CheckingAccount(string owner, string num, string dt, double bal); 

};
#endif
