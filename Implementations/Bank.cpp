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
void BankAccount::get_Num(string accNum)
{
	if (checkNum(accNum))
		number = accNum;
	else
		number = "INVALID";
}
void BankAccount::get_Name(string owner)
{
	if (number[0] == 'I')
		name = "";
	else
		name = owner;
}

void BankAccount::get_Bal(double bal)
{
	if (number[0] == 'I')
		balance = 0;
	else
		balance = bal;
}


BankAccount::BankAccount(string owner, string accNum, double bal)
{

	get_Name(owner);
	get_Num(accNum);
	get_Bal(bal);
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
