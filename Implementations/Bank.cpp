#include "../Headers/Bank.h"
#include <string>
#include <cmath>
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

void BankAccount::set_Date(string dt)
{

	for (int index = 2, cursor = dt.length() - 1; cursor >= 0; index--, cursor--)
	{
		for (int power = 0; dt[cursor] != '/' && cursor >= 0; cursor--, power++)
		{
			date[index] += (static_cast<int>(dt[cursor]) - 48) * pow(10, power);
			//cout << (static_cast<int>(dt[cursor]) - 48) * pow(10, power)<<  endl;
		}
	}
}

string BankAccount::retrieve_Date()
{
	string output = "";
	int d[3];
	int remainder;
	for (int i = 0; i < 3; i++)
		d[i] = date[i];
	for (int index = 0; index < 3; index++)
	{
		for (int power = 1; d[index]; power++)
		{
			remainder = d[index] % static_cast<int>(pow(10, power));
			d[index] -= remainder;
			remainder /= pow(10, power - 1);
			output += static_cast<char>(remainder + 48);
		}
		if (index < 2)
			output += '/';
	}
	return invert(output);
}
string BankAccount::invert(string input)
{
	string output;
	for (int index = input.length() - 1; index >= 0; index--)
		output+= input[index];
	return output;
}
void BankAccount::set_Bal(double bal)
{
	if (number[0] == 'I')
		balance = 0;
	else
		balance = bal;
}


BankAccount::BankAccount(string owner, string accNum,string dt, double bal)
{

	set_Name(owner);
	set_Num(accNum);
	set_Date(dt);
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
