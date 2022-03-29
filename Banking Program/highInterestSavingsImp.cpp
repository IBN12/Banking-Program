/*
Program: HighInterestSavingsImp (Implementation File)
*/

#include "highInterestSavings.h"

// Function Definition - highInterestSavings() (Default Constructor)
highInterestSavings::highInterestSavings()
{
	amountGainedFromHighInterest = new double;
}

// Function Definition - ~highInterestSavings() (Destructor)
highInterestSavings::~highInterestSavings()
{
	delete amountGainedFromHighInterest;
	amountGainedFromHighInterest = nullptr;
}

// Function Definition - getAmountGainedFromHighInterest()
double highInterestSavings::getAmountGainedFromHighInterest() const
{
	// Check if the balance is at the minimum balance to continue compounding high interest. 
	if (accountBalance < 500)
	{
		return 0;
	}
	else
	{
		return *amountGainedFromHighInterest = accountBalance * highAnnualPercentYield;
	}
}

// Function Definition - accountOwnersWithdrawal()
void highInterestSavings::accountOwnersWithdrawal(double acctWith)
{
	// Check if the balance is at the minimum balance to withdrawal money.
	if (accountBalance < 500)
	{
		cout << "Balance is below the minimum amount." << endl;
		cout << "Balance must be at least $500 to withdrawal money" << endl;
		cout << "from this account." << endl;
	}
	else
	{
		savingsAccount::accountOwnersWithdrawal(acctWith);
	}
}

// Function Defintion - print()
void highInterestSavings::print() const
{
	cout << "**********High Interest Savings Account*********************" << endl;
	cout << "****************Information*********************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << accountBalance + getAmountGainedFromHighInterest() << endl;
	cout << "Deposits: " << getNumberOfDeposits() << endl;
	cout << "Withdrawals: " << getNumberOfWithdrawals() << endl;
	cout << "Amount Gained From High Interest: $" << getAmountGainedFromHighInterest() << endl;
	cout << "*************************************************************" << endl;
}