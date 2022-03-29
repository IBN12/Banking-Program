#pragma once
/*
Program: highInterestChecking.h (Specification File)

Description: This is a checking account with high interest that has 
no monthly service charge. Therefore, it inherits all the properties 
of no service charge checking account. Furthermore, this tpye of
account pays higher interest and requires a higher minimum balance
than the no service charge checking account.

Notes:
->Annual Percentage Yield - the real rate of retrun earned on
an investmenet, taking into account the effect of compounding interest.
Unlike simple interest, compounding interest is calculated periodically
and the amount is immediately added to the balance:
APY Formula = (1 + R/N)^N - 1
APY Percent = 2.5%

->Won't be able to compound high interest, withdrawal money, and writeChecks
if the balance is below the minimum balance of $1000.00. 

->User will be allowed to input the number of checks they
would like to write for the month. The user must
declare a new object of type noServiceChargeChecking to
select a new amount checks to write for a new month.
*/

#include "noServiceChargeChecking.h"

class highInterestChecking : public noServiceChargeChecking
{
public:
	highInterestChecking(int numOfChecks = 10);
	// Constructor with default parameters.

	~highInterestChecking();
	// Destructor

	double getAmountGainedFromHighInterest() const;
	// Pre: Function will return an amount of money 
	//		gained from the higher interest bearing 
	//		checking account.
	// Post: return * amountGainedFromHighInterest = accountBalance * highAnnualPercentYield

	void accountOwnersWithdrawal(double acctWith);
	// Pre: Function will allow the user to Withdrawal money 
	//		from the account. If the account balance is
	//		below the minimum balance of $1000, then the 
	//		user may not Withdrawal any money until the
	//		account balance is at the minimum balance
	//		again.
	// Post: accountBalance -= acctWith;

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

	void print() const;
	// Pre: Function will output the data to the console.
	// Post: High Interest Checking Account Information Output:
	//		First Name
	//		Last Name
	//		Account Number
	//		Account Balance + Amount Gained From High Interest
	//		Number of Deposits
	//		Number of Withdrawals
	//		Amount Gained From High Interest

private:
	long double highAnnualPercentYield = (pow(1 + (0.025 / 12), 12)) - 1;
	double* amountGainedFromHighInterest;
};