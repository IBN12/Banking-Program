/*
Program: savingsAccountImp (Implementation File)
*/

#include "savingsAccount.h"

// Function Definition - savingsAccount()
savingsAccount::savingsAccount()
{
	amountGainedFromInterest = new double;
	lastTenDeposits = new double[10];
	lastTenWithdrawals = new double[10];
	depPreviousAccountBalance = new double[10];
	withPreviousAccountBalance = new double[10];

	numOfDeposits = 0;
	numOfWithdrawals = 0;
	depCount = 0;
	withCount = 0;

	firstName = "XXXXXXXXX";
	lastName = "XXXXXXXXX";
	accountNumber = 11111111;
	accountBalance = 0.0;
}

// Function Definition - ~savingsAccount()
savingsAccount::~savingsAccount()
{
	delete amountGainedFromInterest;
	amountGainedFromInterest = nullptr;

	delete[] lastTenDeposits;
	lastTenDeposits = nullptr;

	delete[] lastTenWithdrawals;
	lastTenWithdrawals = nullptr;
}

// Function Definition - inputAccountOwnersName()
void savingsAccount::inputAccountOwnersName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

// Function Definition - inputAccountOwnersNumber()
void savingsAccount::inputAccountOwnersNumber(int acctNum)
{
	accountNumber = acctNum;
}

// Function Definition - getAccountOwnersBalance()
double savingsAccount::getAccountOwnersBalance() const
{
	return accountBalance;
}

// Function Definition - getNumberOfDeposits()
int savingsAccount::getNumberOfDeposits() const
{
	return numOfDeposits;
}

// Function Definition - getNumberOfWithdrawals()
int savingsAccount::getNumberOfWithdrawals() const
{
	return numOfWithdrawals;
}

// Function Definition - getAmountGainedFromInterest()
double savingsAccount::getAmountGainedFromInterest() const
{
	return *amountGainedFromInterest = accountBalance * AnnualPercentYield;
}

// Function Definition - accountOwnersDeposit()
void savingsAccount::accountOwnersDeposit(double acctDep)
{
	// Check if the user has made 10+ deposits.
	if (depCount >= 10) 
	{					
		depCount = 0;
		delete[] depPreviousAccountBalance;
		depPreviousAccountBalance = nullptr;

		delete[] lastTenDeposits;
		lastTenDeposits = nullptr;

		depPreviousAccountBalance = new double[10];
		lastTenDeposits = new double[10];

		if (acctDep != 0) // If money is deposited after new memory is assigned.
		{				  	
			depPreviousAccountBalance[depCount] = accountBalance;
			lastTenDeposits[depCount] = acctDep;
			depCount++;
		}
	}
	else
	{
		depPreviousAccountBalance[depCount] = accountBalance;
		lastTenDeposits[depCount] = acctDep;

		depCount++;
	}
	accountBalance += acctDep;
	numOfDeposits++;
}

// Funciton Definition - accountOwnersWithdrawal()
void savingsAccount::accountOwnersWithdrawal(double acctWith)
{
	// Check if the user has made 10+ withdrawals.
	if (withCount >= 10)
	{
		withCount = 0;
		delete[] withPreviousAccountBalance;
		withPreviousAccountBalance = nullptr;

		delete[] lastTenWithdrawals;
		lastTenWithdrawals = nullptr;

		withPreviousAccountBalance = new double[10];
		lastTenWithdrawals = new double[10];

		if (acctWith != 0) // If money is withdrawn after new memory is assigned. 
		{
			withPreviousAccountBalance[withCount] = accountBalance;
			lastTenWithdrawals[withCount] = acctWith;
			withCount++;
		}
	}
	else
	{
		withPreviousAccountBalance[withCount] = accountBalance;
		lastTenWithdrawals[withCount] = acctWith;

		withCount++;
	}
	accountBalance -= acctWith;
	numOfWithdrawals++;
}

// Function Definition - accountMonthlyStatements()
void savingsAccount::accountMonthlyStatements() const
{
	cout << "|Monthly Statements|" << endl;
	if (depCount == 0) // Check if any deposits have been made.
	{
		cout << "No deposits have been made yet." << endl;
	}
	else
	{
		// Output the last ten deposit transactions.
		for (int i = 0; i < depCount; i++)
		{
			cout << "********************Deposit #" << i + 1 << "*********************" << endl;
			cout << "Transaction: $" << depPreviousAccountBalance[i] << " + $" << lastTenDeposits[i] << endl;
			cout << "Amount: $" << depPreviousAccountBalance[i] + lastTenDeposits[i] << endl;
			cout << "***************************************************" << endl;
		}
	}
	cout << endl;

	if (withCount == 0) // Check if any withdrawals have been made. 
	{
		cout << "No withdrawals have been made yet." << endl;
	}
	else
	{
		// Output the last ten withdrawal transactions. 
		for (int i = 0; i < withCount; i++)
		{
			cout << "***********************Withdrawal #" << i + 1 << "**************" << endl;
			cout << "Transaction: $" << withPreviousAccountBalance[i] << " - $" << lastTenWithdrawals[i] << endl;
			cout << "Amount: $" << withPreviousAccountBalance[i] - lastTenWithdrawals[i] << endl;
			cout << "*****************************************************************" << endl;
		}
	}
}

// Function Definition - print()
void savingsAccount::print() const
{
	cout << "********************Savings Account***********************" << endl;
	cout << "**********************Information*************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << accountBalance + getAmountGainedFromInterest() << endl;
	cout << "Deposits: " << numOfDeposits << endl;
	cout << "Withdrawals: " << numOfWithdrawals << endl;
	cout << "Amount Gained From Interest: $" << getAmountGainedFromInterest() << endl;
	cout << "***************************************************************" << endl;
}