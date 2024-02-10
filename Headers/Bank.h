#ifndef BANK_H
#define BANK_H
#include <string>
using namespace std;
class BankAccount
{
	protected:
	string name, number;
	double balance;

	public:

	BankAccount(string owner, string accNum, double bal);
	string retrieve_Name();
	string retrieve_Num();
	double retrieve_Bal();
	void set_Name(string owner);
	void set_Num(string accNum);
	void set_Bal(double bal);
	virtual void monthly_statement() = 0;
	virtual void withdraw(double amount) = 0;
	void deposit(double amount);
	bool checkNum(string accNum);
};
#endif
