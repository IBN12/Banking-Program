/*
Program: noServiceChargeCheckingImp (Implementation File)
*/

#include "noServiceChargeChecking.h"

// Function Definition - inputAccountOwnersName()
void noServiceChargeChecking::inputAccountOwnersName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

// Function Definition - noServiceChargeChecking() (Constructor with default parameters)
noServiceChargeChecking::noServiceChargeChecking(int numOfChecks)
{
	firstName = "XXXXXXXXXX";
	lastName = "XXXXXXXXXX";
	accountNumber = 11111111;
	accountBalance = 0.0;

	checksToWrite = numOfChecks;
	pPaidTo = new string[checksToWrite];
	pReason = new string[checksToWrite];
	pAmount = new double[checksToWrite];
	pPreviousAccountBalance = new double[checksToWrite];

	amountGainedFromInterest = new double;
	numOfDeposits = 0;
	numOfWithdrawals = 0;
	count = 0;
}

// Function Definition - ~noServiceChargeChecking() (Destructor)
noServiceChargeChecking::~noServiceChargeChecking()
{
	delete amountGainedFromInterest;
	amountGainedFromInterest = nullptr;

	delete[] pPreviousAccountBalance;
	pPreviousAccountBalance = nullptr;

	delete[] pPaidTo;
	pPaidTo = nullptr;

	delete[] pReason;
	pReason = nullptr;

	delete[] pAmount;
	pAmount = nullptr;
}

// Function Definition - inputAccountOwnersNumber()
void noServiceChargeChecking::inputAccountOwnersNumber(int acctNum)
{
	accountNumber = acctNum;
}

// Function Definition -  accountMonthlyStatements()
void noServiceChargeChecking::accountMonthlyStatements() const
{
	cout << "|Monthly Statements|" << endl;
	// Check if any 'checks' have been written. 
	if (count == 0)
	{
		cout << "No checks have been written yet." << endl;
		cout << endl;
	}
	else
	{
		// Will loop the specified amount of checks that have been written.
		for (int i = 0; i < count; i++)
		{
			cout << "***************Check " << i + 1 << "*******************" << endl;
			cout << "Pay To The Order Of: " << pPaidTo[i] << endl;
			cout << "Memo: " << pReason[i] << endl;
			cout << "Amount: $" << pAmount[i] << endl;
			cout << "Transaction: $" << pPreviousAccountBalance[i] << " - $" << pAmount[i] << endl;
			cout << "Account Balance: $" << pPreviousAccountBalance[i] - pAmount[i] << endl;
		}
		cout << "************************************************************" << endl;
	}
}

// Function Definition - writeCheck()
void noServiceChargeChecking::writeCheck(string payToTheOrderOf, string memo, double amount)
{
	// Check if the account balance below the minimum balance.
	if (accountBalance < 500)
	{
		cout << "Balance is below $500" << endl;
		cout << "Must have a minimum balance of $500" << endl;
		cout << "to write checks from this account." << endl;
		cout << endl;
	}
	else
	{
		// Check if the count has exceeded the amount of checks to write for this month.
		if (count >= checksToWrite)
		{
			cout << "You specified that you would like to only write " << count << endl;
			cout << "checks for this month." << endl; 
			cout << "Can't write any more than that amount." << endl;
			cout << endl;
		}
		else
		{
			pPaidTo[count] = payToTheOrderOf;
			pReason[count] = memo;
			pAmount[count] = amount;
			pPreviousAccountBalance[count] = accountBalance;
			count++;
			numOfWithdrawals++;

			accountBalance -= amount;
		}
	}
}

// Function Definition - accountOwnersDeposit()
void noServiceChargeChecking::accountOwnersDeposit(double acctDep)
{
	accountBalance += acctDep;
	numOfDeposits++;
}

// Function Definition - accountOwnersWithdrawal()
void noServiceChargeChecking::accountOwnersWithdrawal(double acctWith)
{
	// Check if the accountBalance is below minimum.
	if (accountBalance < 500)
	{
		cout << "Balance is below $500.00." << endl;
		cout << "Must have minimum balance of $500" << endl;
		cout << "to Withdrawal from this account." << endl;
		cout << endl;
	}
	else
	{
		accountBalance -= acctWith;
		numOfWithdrawals++;
	}
}

// Function Definition - getAccountOwnersBalance()
double noServiceChargeChecking::getAccountOwnersBalance() const
{
	return accountBalance;
}

// Function Definition - getAmountGainedFromInterest()
double noServiceChargeChecking::getAmountGainedFromInterest() const
{
	// if the account balance is less than the minimum balance no interest is gained.
	if (accountBalance < 500)
	{
		return 0;
	}
	else
	{
		return *amountGainedFromInterest = accountBalance * annualPercentYield;
	}
}

// Function Definition - getNumOfDeposits()
int noServiceChargeChecking::getNumOfDeposits() const
{
	return numOfDeposits;
}

// Function Definition - getNumOfWithdrawals()
int noServiceChargeChecking::getNumOfWithdrawals() const
{
	return numOfWithdrawals;
}

// Function Definition - print()
void noServiceChargeChecking::print() const
{
	cout << "*************No Service Charge Checking Account***************" << endl;
	cout << "***********************Information****************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << accountBalance + getAmountGainedFromInterest() << endl;
	cout << "Deposits: " << getNumOfDeposits() << endl;
	cout << "Withdrawals: " << getNumOfWithdrawals() << endl;
	cout << "Amount Gained From Interest: $" << getAmountGainedFromInterest() << endl;
	cout << "**************************************************************" << endl;
}