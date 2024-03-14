#include "../Headers/highInterestChecking.h"
#include <string>
#include <iostream>
using namespace std;

 highInterestChecking::highInterestChecking(string owner, string num, string dt, double bal):noServiceChargeChecking()
{
	if (bal < min_bal)
		set_Bal(0);
	else
	{
		set_Bal(bal);
		set_Name(owner);
        	set_Num(num);
        	set_Date(dt);
	}
      
}
highInterestChecking::highInterestChecking():noServiceChargeChecking()
{
}
double highInterestChecking::calculateInterest(string today)
{
        return calculateDays(today) / 365 * higherInterest;
}

/*void highInterestChecking::updateBalance(string today)
{
        double interest = calculateInterest(today);
        if (interest)
                balance += interest;
}
double highInterestChecking::checkBalance(string today)
{
        updateBalance(today);
        return balance;
}

 double highInterestChargeChecking::write_check(double amount, string today, string recipient)
{

        updateBalance(today);
        if (!compareDates(today) || balance < amount)
        {
                cout << "Invalid transaction" << endl;
                return 0.0;
        }
        balance -= amount;

        cout << "Account Holder: " << name << endl;
        cout << "Recipient:      " << recipient << endl;
        cout << "Amount:         " << amount << endl;
        cout << "Date:           " << today << endl;
        return amount;

}*/

