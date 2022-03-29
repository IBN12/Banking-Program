#pragma once
/*
Program: savingsAccount.h (Specification File)
Description: A savings account is a bank account. Therefore, it inherits all the 
properties of a bank account. Furthermore, a savings account also pays interest.

Notes:
->This savings account will pay 1% interest 
using the APY method by compound interest:
APY formula = (1 + (R/N))^N - 1
APY Percent = 1.0%

->The monthly statements will output the last ten transactions 
and the previous account balance. Once ten transactions have 
been reached the statements will be wiped and new allocated 
space of memory will be assigned. The new allocated space of 
memory will contain the last ten transactions for the deposits and
withdrawals, and the previous account balance also for the 
deposits and withdrawals:
double* lastTenDeposits;
double* lastTenWithdrawals;
double* depPreviousAccountBalance;
double* withPreviousAccountBalance;
*/

#include "bankAccount.h"
#include <cmath>

class savingsAccount : public bankAccount
{
public: 
	savingsAccount();
	// Default Constructor

	~savingsAccount();
	// Destructor

	void inputAccountOwnersName(string fName, string lName);
	// Pre: Function will allow the user to input 
	//		their first name and last name.
	// Post: firstName = fName; lastName = lName;

	void inputAccountOwnersNumber(int acctNum);
	// Pre: Function will allow the user to enter
	//		a number for the account.
	// Post: accountNumber = acctNum;

	double getAccountOwnersBalance() const;
	// Pre: Function will return the account owners balance.
	// Post: return accountBalance;

	void accountOwnersDeposit(double acctDep);
	// Pre: Function will allow the user to deposit money
	//		into the account. The last ten deposits will
	//		be recorded and displayed in the monthly statements.
	//		After the ten deposits are made the last ten deposits
	//		and the previous account balance will be wiped from the
	//		monthly statements, and a new monthly statement of the last
	//		ten deposits will be recorded again.
	// Post: depPreviousAccountBalance[depCount] = accountBalance;
	//		 lastTenDeposits[depCount] = acctDep;
	//		 accountBalance += acctDep;

	void accountOwnersWithdrawal(double acctWith);
	// Pre: Function will allow the user to withdrawal money from the
	//		account. The same method using the last ten deposits and
	//		previous account balance for the monthly statements
	//		will also be used for the withdrawals.
	// Post: withPreviousAccountBalance[withCount] = accountBalance;
	//		 lastTenWithdrawals[withCount] = acctWith;
	//		 account -= acctWith;

	void accountMonthlyStatements() const;
	// Pre: Function will output the last ten deposits + Prvious account balance
	//		and the last ten withdrawals - previous account balance.
	// Post: Monthly Statments Output: 
	//		 Deposits:
	//		 Previous Account Balance + Last Ten Deposits
	//		 Withdrawals: 
	//		 Previous Account Balance - Last Ten Withdrawals

	int getNumberOfDeposits() const;
	// Pre: Function will return the number of deposits.
	// Post: return numOfDeposits;

	int getNumberOfWithdrawals() const;
	// Pre: Function will return the number of withdrawals.
	// Post: return numOfWithdrawals;

	double getAmountGainedFromInterest() const;
	// Pre: Function will return the amount gained from
	//		interest.
	// Post: *amountGainedFromInterest = accountBalance * AnnualPercentYield;
	//		 return *amountGainedFromInterest;

	void print() const;
	// Pre: Function will output the account data to the
	//		console screen.
	// Post: Savings Account Information Output:
	//		 First Name
	//		 Last Name
	//		 Account Number
	//		 Account Balance + Amount Gained From Interest
	//		 Number of Deposits
	//		 Number of Withdrawals
	//		 Amount Gained From Interest

private:
	long double AnnualPercentYield = (pow(1 + (0.01 / 12), 12)) - 1;
	double* amountGainedFromInterest;

	int numOfDeposits;
	int numOfWithdrawals;
	int depCount;
	int withCount;

	double* lastTenDeposits;
	double* lastTenWithdrawals;
	double* depPreviousAccountBalance;
	double* withPreviousAccountBalance;
};