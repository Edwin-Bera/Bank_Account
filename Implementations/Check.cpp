#include "../Headers/Check.h"
#include "../Headers/Bank.h"
#include <string>
using namespace std;

CheckingAccount::CheckingAccount(string owner, string num, string dt, double bal):BankAccount(owner, num, dt, bal)
{
}


