/*
Program: highInterestCheckingImp (Implementation File)
*/

#include "highInterestChecking.h"

// Function Definition - highInterestChecking() (Default Constructor)
highInterestChecking::highInterestChecking(int numOfChecks) : noServiceChargeChecking(numOfChecks)
{
	amountGainedFromHighInterest = new double;
}

// Function Definition - ~highInterestChecking() (Destructor)
highInterestChecking::~highInterestChecking()
{
	delete amountGainedFromHighInterest;
	amountGainedFromHighInterest = nullptr;
}

// Function Definition - getAmountGainedFromHighInterest()
double highInterestChecking::getAmountGainedFromHighInterest() const
{
	// Check if the balance is at the minimum balance to continue compounding interest.
	if (accountBalance < 1000)
	{
		return 0;
	}
	else
	{
		return *amountGainedFromHighInterest = accountBalance * highAnnualPercentYield;
	}
}

// Function Definition - accountOwnersWithdrawal()
void highInterestChecking::accountOwnersWithdrawal(double acctWith)
{
	// Check if the balance is at the minimum to withdrawal money.
	if (accountBalance < 1000)
	{
		cout << "Account Balance is below the minimum balance." << endl;
		cout << "Cannot Withdrawal money until the balance is at least $1000" << endl;
		cout << endl;
	}
	else
	{
		noServiceChargeChecking::accountOwnersWithdrawal(acctWith);
	}
}

// Function Definition - writeCheck()
void highInterestChecking::writeCheck(string payToTheOrderOf, string memo, double amount)
{
	// Check if the balance is the minimum balance to continue writing checks. 
	if (accountBalance < 1000)
	{
		cout << "Balance is below $1000." << endl;
		cout << "Must have a minimum balance of $1000" << endl; 
		cout << "to write checks from this account." << endl;
	}
	else
	{
		noServiceChargeChecking::writeCheck(payToTheOrderOf, memo, amount);
	}
}

// Function Definition - print()
void highInterestChecking::print() const
{
	cout << "************High Interest Checking Account**************" << endl;
	cout << "********************Information*************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << accountBalance + getAmountGainedFromHighInterest() << endl;
	cout << "Deposits: " << getNumOfDeposits() << endl;
	cout << "Withdrawals: " << getNumOfWithdrawals() << endl;
	cout << "Amount Gained From High Interest: $" << getAmountGainedFromHighInterest() << endl;
	cout << "**********************************************************" << endl;
}