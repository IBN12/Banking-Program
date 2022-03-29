/*
Program: certificateOfDepositImp (Implementation File)
*/

#include "certificateOfDeposit.h"

// Function Definition - certificateOfDeposit() (Default Constructor)
certificateOfDeposit::certificateOfDeposit()
{
	firstName = "XXXXXXXXX";
	lastName = "XXXXXXXXX";
	accountNumber = 11111111;
	accountBalance = 0.0;
	accountBalanceDuplicate = 0.0;

	monthsOfMaturity = 0;
	monthsByCalender = 0;
	certificateOfDepositContract = 6;
	numOfDeposits = 0;
	numOfWithdrawals = 0;
	depCount = 0;
	withCount = 0;
	accountPenalty = false;
	accountPenaltyMessage = false;

	AmountGainedFromInterest = new double;
	months = new string[12];
	months[monthsByCalender] = "January";
	lastTenDeposits = new double[10];
	depPreviousAccountBalance = new double[10];
	lastTenWithdrawals = new double[10];
	withPreviousAccountBalance = new double[10];
}

// Function Definition - ~certificateOfDeposit()
certificateOfDeposit::~certificateOfDeposit()
{
	delete AmountGainedFromInterest;
	AmountGainedFromInterest = nullptr;

	delete[] months;
	months = nullptr;

	delete[] lastTenDeposits;
	lastTenDeposits = nullptr;

	delete[] depPreviousAccountBalance;
	depPreviousAccountBalance = nullptr;

	delete[] lastTenWithdrawals;
	withPreviousAccountBalance = nullptr;
}

// Function Definition - inputAccountOwnersName()
void certificateOfDeposit::inputAccountOwnersName(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
}

// Function Definition - inputAccountOwnersNumber()
void certificateOfDeposit::inputAccountOwnersNumber(int acctNum)
{
	accountNumber = acctNum;
}

// Function Definition - getAccountOwnersBalance()
double certificateOfDeposit::getAccountOwnersBalance() const
{
	return accountBalance;
}

// Function Definition - getAmountGainedFromInterest()
double certificateOfDeposit::getAmountGainedFromInterest() const
{
	return *AmountGainedFromInterest = accountBalanceDuplicate * AnnualPercentYield;	
}

// Function Definition - getAmountOfMonths()
int certificateOfDeposit::getAmountOfMonths() const
{
	return monthsOfMaturity;
}

// Function Definition - getNumberOfDeposits()
int certificateOfDeposit::getNumberOfDeposits() const
{
	return numOfDeposits;
}

// Function Definition - getNumberOfWithdrawals()
int certificateOfDeposit::getNumberOfWithdrawals() const
{
	return numOfWithdrawals;
}

// Function Definition - getCurrentMonth()
string certificateOfDeposit::getCurrentMonth() const
{
	return months[monthsByCalender];
}

// Function Definition - accountOwnersDeposit()
void certificateOfDeposit::accountOwnersDeposit(double acctDep)
{
	// Check if there has been 10 or more deposits.
	if (depCount >= 10)
	{
		/* Note:
		 * Allocate a new space of memory for the last ten deposits
		 * and the previous account balances before those last ten
		 * deposits. This will give the account monthly statements a
		 * new list of statements for the deposits. The deposit count
		 * will be set back to zero.
		 */
		delete[] lastTenDeposits;
		lastTenDeposits = nullptr;

		delete[] depPreviousAccountBalance;
		depPreviousAccountBalance = nullptr;

		lastTenDeposits = new double[10];
		depPreviousAccountBalance = new double[10];

		depCount = 0;

		// Check if a deposit is made after a new space of memory is allocated.
		if (acctDep != 0)
		{
			lastTenDeposits[depCount] = acctDep;
			depPreviousAccountBalance[depCount] = accountBalance;
			accountBalance += acctDep;
			monthsOfMaturity++;
		}
	}
	else
	{
		depPreviousAccountBalance[depCount] = accountBalance;
		lastTenDeposits[depCount] = acctDep;
		accountBalance += acctDep;

		numOfDeposits++;
		monthsByCalender++;
		monthsOfMaturity++;
	}
	depCount++;

	// Check if account has a penalty on it
	if (!accountPenalty)
	{
		accountBalanceDuplicate = accountBalance;
	}
	else
	{
		accountBalanceDuplicate = 0.0;
	}

	// Check which month it is.
	switch (monthsByCalender)
	{
	case 1:
		months[monthsByCalender] = "February";
		break;
	case 2:
		months[monthsByCalender] = "March";
		break;
	case 3:
		months[monthsByCalender] = "April";
		break;
	case 4:
		months[monthsByCalender] = "May";
		break;
	case 5:
		months[monthsByCalender] = "June";
		break;
	case 6:
		months[monthsByCalender] = "July";
		break;
	case 7:
		months[monthsByCalender] = "August";
		break;
	case 8:
		months[monthsByCalender] = "September";
		break;
	case 9:
		months[monthsByCalender] = "October";
		break;
	case 10:
		months[monthsByCalender] = "November";
		break;
	case 11:
		months[monthsByCalender] = "December";
		break;
	default:
		cout << "No months prioritized" << endl;
	}
	

	// Check for a new year
	if (monthsByCalender >= 12)
	{
		monthsByCalender = 0;
		delete[] months;
		months = nullptr;

		months = new string[12];
		months[monthsByCalender] = "January";
	}
}

// Function Definition - accountOwnersWithdrawal()
void certificateOfDeposit::accountOwnersWithdrawal(double acctWith)
{
	// check if the account has matured in six months
	if (monthsByCalender < certificateOfDepositContract)
	{
		// Penalty message will appear one time to inform the user of the penalty
		if (!accountPenaltyMessage)
		{
			cout << "This account will terminate the amount gained" << endl;
			cout << "from interest due to an early withdrawal violation." << endl;
			cout << "The owners contractual agreement states that the" << endl;
			cout << "account must mature within six months before any" << endl;
			cout << "withdraws are made." << endl;
			cout << "The amount gained from interest will be pushed back to zero." << endl;
		}
		*AmountGainedFromInterest = 0.0;
		accountBalanceDuplicate = 0.0;

		accountPenalty = true;
		accountPenaltyMessage = true;
	}

	// Check if there has been 10 or more withdrawals
	if (withCount >= 10)
	{
		/* Note:
		 * Allocate a new space of memory for the last ten withdrawals
		 * and the previous account balances before those last ten
		 * withdrawals. This will give the account monthly statements a
		 * new list of statements for the withdrawals. The withdrawal count
		 * will be set back to zero.
		 */
		delete[] lastTenWithdrawals;
		lastTenWithdrawals = nullptr;

		delete[] withPreviousAccountBalance;
		withPreviousAccountBalance = nullptr;

		lastTenWithdrawals = new double[10];
		withPreviousAccountBalance = new double[10];

		withCount = 0;

		// Check if a withdrawal is made after a new space of memory is allocated.
		if (acctWith != 0)
		{
			lastTenWithdrawals[withCount] = acctWith;
			withPreviousAccountBalance[withCount] = accountBalance;
			accountBalance -= acctWith;
		}
	}
	else
	{
		lastTenWithdrawals[withCount] = acctWith;
		withPreviousAccountBalance[withCount] = accountBalance;
		accountBalance -= acctWith;
		numOfWithdrawals++;
	}
	withCount++;
}

// Function Definition - accountMonthlyStatements()
void certificateOfDeposit::accountMonthlyStatements() const
{
	cout << "*********************Monthly Statements*************************" << endl;
	cout << "****************************************************************" << endl;
	// Check if any deposits have been made. 
	if (depCount == 0)
	{
		cout << "No Transactions" << endl;
	}
	else
	{
		for (int i = 0; i < depCount; i++)
		{
			cout << "*********************Deposit #" << i + 1 << "**********************" << endl;
			cout << "Transaction: $" << depPreviousAccountBalance[i] << " + $" << lastTenDeposits[i] << " = $";
			cout << depPreviousAccountBalance[i] + lastTenDeposits[i] << endl;
			cout << "*****************************************************" << endl;
		}
	}
	cout << endl;

	// Check if any withdrawals have been made.
	if (withCount == 0)
	{
		cout << "No Transactions" << endl;
	}
	else
	{
		for (int i = 0; i < withCount; i++)
		{
			cout << "********************Withdrawal #" << i + 1 << "************************" << endl;
			cout << "Transaction $: " << withPreviousAccountBalance[i] << " - $" << lastTenWithdrawals[i] << " = $";
			cout << withPreviousAccountBalance[i] - lastTenWithdrawals[i] << endl;
			cout << "****************************************************" << endl;
		}
	}
}

// Function Definition - print()
void certificateOfDeposit::print() const
{
	cout << "**************Certificate Deposit Account**************" << endl;
	cout << "********************Information************************" << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: $" << accountBalance + getAmountGainedFromInterest() << endl;
	cout << "Deposits: " << getNumberOfDeposits() << endl;
	cout << "Withdrawals: " << getNumberOfWithdrawals() << endl;
	cout << "Amount Gained From Interest: $" << getAmountGainedFromInterest() << endl;
	cout << "Months of Maturity: " << getAmountOfMonths() << endl;
	cout << "Current Month: " << getCurrentMonth() << endl;
	cout << "*********************************************************" << endl;
}
