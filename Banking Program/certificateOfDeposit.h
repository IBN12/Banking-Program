#pragma once
/*
Program: certificateOfDeposit.h (Specification File)
Description: A Certificate of deposit account is a bank account.
Therefore it inherits all the properties of a bank account. 
In addition, it has instance variables to store the number of CD
maturity months, interest rate, and the current CD month.

Notes:
-> Certificate of Deposit (CD) will give the owners account
a higher interest rate because they are keeping the 
money locked in the account for a certain amount of time.
You can get a higher interest rate than savings or money
market accounts in exchange for not touching your money for
a fixed period of time.
CDs are safer than stocks and bonds, practically guaranteeing you 
a set return.
Nearly every bank offers them.
Even though CDs are agreements not to touch your money, there are ways to exit
them early if you run into trouble, so you won't go broke in an
emergency.

->Penalty for early withdrawal will push the amount gained from interest 
back to zero dollars.

*/

#include <iostream>
#include <cmath>
#include "bankAccount.h"
using namespace std;

class certificateOfDeposit : public bankAccount
{
public:
	certificateOfDeposit();
	// Default Constructor

	~certificateOfDeposit();
	// Destructor

	void inputAccountOwnersName(string fName, string lName);
	// Pre: Function will allow the user to enter
	//		their first name and last name.
	// Post: firstName = fName; lastName = lName;

	void inputAccountOwnersNumber(int acctNum);
	// Pre: Function will allow the user to enter
	//		an account number.
	// Post: accountNumber = acctNum;

	double getAccountOwnersBalance() const;
	// Pre: Function will return the account owners
	//		balance.
	// Post: return accountBalace;

	double getAmountGainedFromInterest() const;
	// Pre: Function will return the ammount 
	//		gained from interest. If thes user withdraws
	//		money before the 6 month contractual agreement,
	//		then the amount gained from interest will be pushed back
	//		to zero.
	// Post: return *AmountGainedFromInterest = accountBalanceDuplicate * AnnualPercentYield

	int getAmountOfMonths() const;
	// Pre: Function will return the accounts
	//		months of maturity.
	// Post: return monthsOfMaturity;

	int getNumberOfDeposits() const;
	// Pre: Function will return the number of deposits made.
	// Post: return numOfDeposits; 

	int getNumberOfWithdrawals() const;
	// Pre: Function will return the number of withdrawals made.
	// Post: return numOfWithdrawalss;

	string getCurrentMonth() const;
	// Pre: Function will return the current month that the
	//		account is on.
	// Post: return months[monthsByCalender];

	void accountOwnersDeposit(double acctDep = 0);
	// Pre: Function will allow the user to deposit money.
	//		Each deposit will increase the month by 1.
	//		This increase will make sure the account 
	//		is able to mature where the user can 
	//		withdraw money without violating the accounts
	//		contractual agreements.
	// Post: depPreviousAccountBalance[depCount] = accountBalance;
	//		 lastTenDeposits[depCount] = acctDep;
	//		 accountBalance += acctDep;
	//		 numOfDeposits++;
	//		 monthsByCalender++;
	//		 monthsOfMaturity++;

	void accountOwnersWithdrawal(double acctWith = 0);
	// Pre: Function will allow the user to withdraw money from
	//		the account. Withdrawing money to early violates 
	//		the accounts contractual agreement that states the 
	//		account must mature within six months before any
	//		withdraws are made. The penalty is the amount gained
	//		from interest will be pushed back to zero. 
	// Post: lastTenWithdrawals[withCount] = acctWith;
	//		 withPreviousAccountBalance[withCount] = accountBalance;
	//		 accountBalance -= acctWith;
	//		 numOfWithdrawals++;

	void accountMonthlyStatements() const;
	// Pre: Function will output the last ten deposits + previous account balance
	//		and the last ten withdrawals - previous account balance.
	// Post: Monthly Statement Ouput: 
	//		 Deposits:
	//		 Previous Account Balance + Last Ten Deposits
	//		 Withdrawals:
	//		 Previous Account Balance + Last Ten Withdrawals

	void print() const;
	// Pre: Function will output the content to the
	//		console screen.
	// Post: Certificate of Deposit Information Output:
	//		 First Name
	//		 Last Name
	//		 Account Number
	//		 Account Balance
	//		 Deposits
	//		 Withdrawals
	//		 Amount Gained From Interest
	//		 Months of Maturity
	//		 Current Month
private:
	long double AnnualPercentYield = (pow(1 + (0.03 / 12), 12)) - 1;
	double* AmountGainedFromInterest;

	int certificateOfDepositContract;
	int monthsOfMaturity;
	int monthsByCalender;
	double accountBalanceDuplicate;
	string* months;
	bool accountPenalty;
	bool accountPenaltyMessage;

	int numOfDeposits;
	int numOfWithdrawals;

	double* lastTenDeposits;
	double* lastTenWithdrawals;
	double* depPreviousAccountBalance;
	double* withPreviousAccountBalance;
	int depCount;
	int withCount;
};