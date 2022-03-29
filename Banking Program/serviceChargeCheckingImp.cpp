/*
Program: serviceChargeCheckingImp (Implementation File)
*/

#include "serviceChargeChecking.h"

// Function Definition - serviceChargeChecking() (Default Constructor)
serviceChargeChecking::serviceChargeChecking()
{
	firstName = "XXXXXX";
	lastName = "XXXXXXX";
	accountNumber = 111111111;
	accountBalance = 0.0;
	numOfDeposits = 0;
	numOfWithdrawals = 0;

	checksWritten = new int;
	pPaidTo = new string[5];
	pMemo = new string[5];
	pAmount = new double[5];

	pPreviousAccountBalances = new double[5];
}

// Function Definition - ~serviceChargeChecking() (Destructor)
serviceChargeChecking::~serviceChargeChecking()
{
	delete checksWritten;
	checksWritten = nullptr;

	delete[] pPaidTo;
	pPaidTo = nullptr;

	delete[] pMemo;
	pMemo = nullptr;

	delete[] pAmount;
	pAmount = nullptr;

	delete[] pPreviousAccountBalances;
	pPreviousAccountBalances = nullptr;
}

// Function Definition - inputAccountOwnersName()
void serviceChargeChecking::inputAccountOwnersName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

// Function Definition - writeCheck()
void serviceChargeChecking::writeCheck(string payToTheOrderOf, string memo, double Amount)
{
	// Limitation test 
	if (count <= 5)
	{
		// Check if the balance has a sufficient amount of funds in it.
		if (accountBalance <= 0)
		{
			cout << "Insufficient funds for this account." << endl;
			cout << "Can't write any checks" << endl;
			cout << endl;
		}
		else
		{
			pPreviousAccountBalances[count] = accountBalance;

			accountBalance = accountBalance - Amount;
			pPaidTo[count] = payToTheOrderOf;
			pMemo[count] = memo;
			pAmount[count] = Amount;

			count++;
			*checksWritten = count;
			numOfWithdrawals++;

			// Checks if 'count' is greater than 1 for grammar purposes.
			if (count < 4)
			{
				cout << "You have " << 5 - count << " checks left." << endl << endl;
			}
			else if (count == 4)
			{
				cout << "You have 1 check left." << endl << endl;
			}
			else
			{
				cout << "You have ran out of checks." << endl << endl;
			}
		}
	}
	else
	{
		cout << "You may only write 5 checks each month." << endl;
		cout << "You have reached your checking limit." << endl;
	}
}

// Function Definition - inputAccountOwnersNumber()
void serviceChargeChecking::inputAccountOwnersNumber(int acctNum)
{
	accountNumber = acctNum;
}

// Function Definition - getAccountOwnersBalance()
double serviceChargeChecking::getAccountOwnersBalance() const
{
	return accountBalance;
}

// Function Definition - getNumberOfDeposits()
int serviceChargeChecking::getNumberOfDeposits() const
{
	return numOfDeposits;
}

// Function Definition - getNumberOfWithdrawals()
int serviceChargeChecking::getNumberOfWithdrawals() const
{
	return numOfWithdrawals;
}

// Function Definition - accountOwnersDeposit()
void serviceChargeChecking::accountOwnersDeposit(double acctDep)
{
	accountBalance += acctDep;
	numOfDeposits++;
}

// Function Definition - accountOwnersWithdrawal()
void serviceChargeChecking::accountOwnersWithdrawal(double acctWith)
{
	accountBalance -= acctWith;
	numOfWithdrawals++;
}


// Function Definition - accountMonthlyStatement()
void serviceChargeChecking::accountMonthlyStatements() const
{
	cout << "|Monthly Statements|" << endl;
	// Check if any checks have been written.
	if (*checksWritten == 0)
	{
		cout << "No checks have been written yet." << endl;
	}
	else
	{
		// Will loop the specified amount of checks that have been written.
		for (int i = 0; i < *checksWritten; i++)
		{
			cout << "********************Check " << i + 1 << "*******************" << endl;
			cout << "Pay To The Order Of: " << pPaidTo[i] << endl;
			cout << "Memo: " << pMemo[i] << endl;
			cout << "Amount: $" << pAmount[i] << endl;
			cout << "Transaction: $" << pPreviousAccountBalances[i] << " - $" << pAmount[i] << endl;
			cout << "Account Balance: $" << pPreviousAccountBalances[i] - pAmount[i] << endl;
		}
		cout << "********************************************************************" << endl;
	}
}

// Function Definition - print()
void serviceChargeChecking::print() const
{
	cout << "***************Service Charge Checking Account*************" << endl;
	cout << "************************Information************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl; 
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << getAccountOwnersBalance() << endl;
	cout << "Deposits: " << getNumberOfDeposits() << endl;
	cout << "Withdrawals: " << getNumberOfWithdrawals() << endl;
	cout << "Checks Left: " << 5 - count << endl;
	cout << "************************************************************" << endl;
}