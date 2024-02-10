#ifndef CHECK_H
#define CHECK_H
#include "../Headers/Bank.h"
#include <string>
using namespace std;
class CheckingAccount: public BankAccount
{
	public:
		virtual double write_check(double amount) = 0;
		CheckingAccount(string owner, string num, double bal); 

};
#endif
