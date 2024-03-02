#ifndef BANK_H
#define BANK_H
#include <string>
using namespace std;
class BankAccount
{
	protected:
	string name; //name of the account holder
	string number; //account number
	int date[2][3]; //[0]date of account creation. [1]date to be used when calculating interest, maturity and service charges
	double balance;

	public:

	BankAccount(string owner, string accNum, string dt, double bal);
	string retrieve_Name();
	string retrieve_Num();
	string retrieve_Date();
	double retrieve_Bal();
	void set_Name(string owner);
	void set_Num(string accNum);
	void set_Bal(double bal);
	void set_Date(string dt);
	virtual void monthly_statement() = 0;
	virtual void withdraw(double amount) = 0;
	void deposit(double amount);
	bool checkNum(string accNum);
	bool compareDates(string dt);

	private:

	string invert(string input);
};
#endif
