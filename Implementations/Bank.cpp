#include "../Headers/Bank.h"
#include <string>
using namespace std;
bool BankAccount::checkNum(string accNum)
{
	if (accNum.length() != 10)
		return false;
	for (int index = 0; index < 10; index++)
		if (accNum[index] < '0' && accNum[index] > '9')
			return false;
	return true;
}
void BankAccount::set_Num(string accNum)
{
	if (checkNum(accNum))
		number = accNum;
	else
		number = "INVALID";
}
void BankAccount::set_Name(string owner)
{
	if (number[0] == 'I')
		name = "";
	else
		name = owner;
}

void BankAccount::set_Bal(double bal)
{
	if (number[0] == 'I')
		balance = 0;
	else
		balance = bal;
}


BankAccount::BankAccount(string owner, string accNum, double bal)
{

	set_Name(owner);
	set_Num(accNum);
	set_Bal(bal);
}

string BankAccount::retrieve_Name()
{
	return name;
}

string BankAccount::retrieve_Num()
{
	return number;
}

double BankAccount::retrieve_Bal()
{
	return balance;
}


void BankAccount::deposit(double amount)
{
	if (number[0] != 'I')
		balance += amount;
}
