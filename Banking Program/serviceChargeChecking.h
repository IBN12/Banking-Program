#pragma once
/*
Program: serviceChargeChecking.h (Specification File)

Description: This type of account pays no interest, allows the
account holder to write a limited number of checks each month, 
and does not require any minimum balance.

Notes:
->This accounts is not an interest-bearing checking account, so 
there will be 0% APY for this checking account.

->APY = Annual Percent Yield

->You will only be able to write 5 checks each month for
this account. Checks will allow the user to input the
pay to the order of, memo, and amount. Checks will be
discontinueds after five checks and the user will
have to declare a new object of type serviceChargeChecking 
to write more checks. 
*/

#include "checkingAccount.h"

class serviceChargeChecking : public checkingAccount
{
public:
	serviceChargeChecking();
	// Default Constructor

	~serviceChargeChecking();
	// Destructor

	void inputAccountOwnersName(string fName, string lName);
	// Pre: Function will allow the user to enter their
	//		first name and last name for the bank
	//		account.
	// Post: firstName = fName; lastName = lName;

	void inputAccountOwnersNumber(int acctNum);
	// Pre: Function will allow the user to enter their
	//		bank account number.
	// Post: accountNumber = acctNum;

	void writeCheck(string payToTheOrderOf, string memo, double Amount);
	// Pre: Function will allow the user to write a check.
	//		Five checks is the limit.
	// Post: accountBalance = accountBalance - Amount;
	//		 pPaidTo[count] = payToTheOrderOf;
	//		 pMemo[count] = memo;
	//		 pAmount[count] = Amount;

	double getAccountOwnersBalance() const;
	// Pre: Function will return the account owners balance.
	// Post: return accountBalance;

	int getNumberOfDeposits() const;
	// Pre: Function will return the number of deposits.
	// Post: return numOfDeposits;

	int getNumberOfWithdrawals() const;
	// Pre: Function will return the number of withdrawals.
	// Post: return numOfWithdrawals;

	void accountOwnersDeposit(double acctDep);
	// Pre: Function will allow the user to deposit money and
	//		add to the balance.
	// Post: accountBalance += acctDep;

	void accountOwnersWithdrawal(double acctWith);
	// Pre: Function will allow the user to Withdrawal money 
	//		from the account and subtract from the balance.
	// Post: accountBalance -= acctWith;

	void accountMonthlyStatements() const;
	// Pre: Function will give a monthly statement on
	//		the account. The monthly statements will
	//		output the checks written for the month. 
	// Post: Monthly Statements Output:
	//		 Pay To The Order Of:
	//		 Memo:
	//		 Amount:
	//		 Transaction: 
	//		 Account Balance:


	void print() const;
	// Pre: Funtion will output data to the console.
	// Post: Service Charge Checking Account Information Output:
	//		 First Name
	//		 Last Name
	//		 Account Number
	//		 Account Balance
	//	     Number of Deposits
	//		 Number of Withdrawals
	//		 Number of Checks Left After Being Written

private:
	int count = 0;
	int numOfDeposits;
	int numOfWithdrawals;

	int *checksWritten;
	string *pPaidTo;
	string *pMemo;
	double *pAmount;
	double *pPreviousAccountBalances;
};