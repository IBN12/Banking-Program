#pragma once
/*
Program: noServiceChargeChecking.h (Specifications File)

Description: This is a checking account with no monthly
service charge. It inherits all the properties of a checking
account. This type of account will pay interest, allows the
holder to write checks, and require a minimum balance. 

Notes:
->Annual Percentage Yield - the real rate of retrun earned on 
an investmenet, taking into account the effect of compounding interest.
Unlike simple interest, compounding interest is calculated periodically
and the amount is immediately added to the balance: 
APY Formula = (1 + R/N)^N - 1
APY Percent = 1.0%

->This checking account must remain at a minimum balance in order
to continue gaining interest from APY.

->User will be allowed to input the number of checks they 
would like to write for the month. The user must
declare a new object of type noServiceChargeChecking to 
select a new amount checks to write for a new month.
*/

#include "checkingAccount.h"
#include <cmath>

class noServiceChargeChecking : public checkingAccount
{
public:
	noServiceChargeChecking(int numOfChecks = 10);
	// Constructor with default parameters

	~noServiceChargeChecking();
	// Destructor

	void inputAccountOwnersName(string fName, string lName);
	// Pre: Function will allow the user to input
	//		their first name and last name.
	// Post: firstName = fName; lastName = lName;

	void inputAccountOwnersNumber(int acctNum);
	// Pre: Function will allow the user to input
	//		an account number.
	// Post: accountNumber = acctNum;

	double getAccountOwnersBalance() const;
	// Pre: Function will return the account owners 
	//		balance.
	// Post: return accountBalance;

	void accountOwnersDeposit(double acctDep);
	// Pre: Function will allow the user to deposit
	//		money into the bank account.
	// Post: accountBalance += acctDep;

	void accountOwnersWithdrawal(double acctWith);
	// Pre: Function will allow the user to Withdrawal
	//	    money from the bank account. If the account
	//		balance is below the minimum balance the
	//		user cannot Withdrawal any money.
	// Post: accountBalance -= acctWith;

	void accountMonthlyStatements() const;
	// Pre: Function will allow the user to check their 
	//		monthly statements. The monthly statements will 
	//		display the details about the cheacks written
	//		each month.
	// Post: Monthly Statements output:
	//		 Pay To The Order Of
	//		 Memo
	//       Amount
	//	     Transaction
	//	     Account Balance

	void writeCheck(string payToTheOrderOf, string memo, double amount);
	// Pre: Function will allow the user to write a
	//		specified number of checks. If the account
	//		balance is below the minimum balance the
	//		user cannot write any checks until the balance
	//		reaches the minimum again. The user can write 
	//		an unlimited amount of checks but the number
	//		must be specified by the user. The default minimum
	//		amount of checks to write starts at 10. 
	// Post: pPaidTo[count] = payToTheOrderOf;
	//		 pReason[count] = memo;
	//		 pAmount[count] = amount;
	//		 pPreviousAccountBalance[count] = accountBalance;

	double getAmountGainedFromInterest() const;
	// Pre: Function will return the amount of money 
	//		gained from the interest bearing account.
	// Post: return *amountGainedFromInterest = accountBalance * annualPercentYield;

	int getNumOfDeposits() const;
	// Pre: Function will return the number of bank deposits.
	// post: return numOfDeposits;

	int getNumOfWithdrawals() const;
	// Pre: Function will return the number of bank Withdrawals
	// Post: return numOfWithdrawal;

	void print() const;
	// Pre: Function will output the data to the console.
	// Post: No Service Charge Checking Account Information Ouput:
	//		First Name
	//		Last Name
	//		Account Number
	//		Account Balance + Amount Gained From Interest
	//		Number of Deposits
	//		Number of Withdrawals
	//		Amount Gained From Interest

private:
	long double annualPercentYield = (pow((1 + (0.01 / 12)), 12)) - 1;
	double *amountGainedFromInterest; 

	int numOfDeposits;
	int numOfWithdrawals;
	int checksToWrite;
	int count;

	string* pPaidTo;
	string* pReason;
	double* pAmount;
	double* pPreviousAccountBalance;
};