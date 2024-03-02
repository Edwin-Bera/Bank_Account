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
			date[0][index] += (static_cast<int>(dt[cursor]) - 48) * pow(10, power); 
		}
		date[1][index] = date[0][index];
	}
}

string BankAccount::retrieve_Date()
{
	string output = "";
	int d[3];
	int remainder;
	for (int i = 0; i < 3; i++)
		d[i] = date[0][i];
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
	string output, temp[3];

	int i = 0;
	for (int index = 0; index < 3; index++)
	{
		for (; input[i] != '/' && i < input.length(); i++)
			temp[index] += input[i];
		i++;
		for (int idx = temp[index].length() - 1; idx >= 0; idx--)
			output += temp[index][idx];
		if (index < 2)
			output += '/';
	}
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

bool BankAccount::compareDates(string dt)
{
	int d[3];

	for (int index = 2, cursor = dt.length() - 1; cursor >= 0; index--, cursor--)
	{
		for (int power = 0; dt[cursor] != '/' && cursor >= 0; cursor--, power++)
		{
			d[index] += (static_cast<int>(dt[cursor]) - 48) * pow(10, power); 
		}
	}

	if( date[1][2] > d[2])
		return false;
	else if (date[1][2] == d[2])
		if ((date[1][1] > d[1]) || (date[1][1] == d[1] & date[1][0] > d[0]))
			return false;
		else
			return true;
	else
		return true;
}
