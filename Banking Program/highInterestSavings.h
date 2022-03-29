#pragma once
/*
Program: highInterstSavings.h (Specification File)
Description: A high-interest savings account is a savings account.
Therefore, it inherits all the properties of a savings account. It
also requires a minimum balance.

Notes:
This is high interst savings account will pay 2.5% interest back
using thes APY method for by compund interest.
APY = (1 + (R/N))^N - 1

High interest savings account requires a minimum balance. If
the account balance is below the minimum balances of $500, then
the account owner won't be able to withdrawal money and
the account will discontinue compounding high interest until the 
account meets the minimum balance requirements again. 
*/

#include "savingsAccount.h"

class highInterestSavings : public savingsAccount
{
public:
	highInterestSavings();
	// Default Constructor

	~highInterestSavings();
	// Destructor

	double getAmountGainedFromHighInterest() const;
	// Pre: Function will return the amount of money
	//		gained from high interest. If the balance is
	//		below the minimum amount of $500, then the
	//		account will discontinue componding high
	//		interest and retrun $0.00 until the account
	//		meets the minimum balance requirements again.
	// Post: if (accountBalance < 500)
	//			return 0;
	//		else
	//			return *amountGainedFromHighInterest = accountBalance * highAnnualPercentYield; 

	void accountOwnersWithdrawal(double acctWith);
	// Pre: Function will allow the user to withdrawal money
	//		from the account. The account won't allow the
	//		user to withdrawal any money if the balance is below
	//		the minimum balance of $500.00.
	// Post: if (accountBalance < 500)
	//			Below Minimum Balance
	//		else
	//			accountBalance -= acctWith;

	void print() const;
	// Pre: Function will output the data to the
	//		console screen.
	// Post: High Interest Savings Account Information Output:
	//		 First Name:
	//		 Last Name:
	//		 Account Number:
	//		 Account Balance + Amount Gained From High Interest:
	//		 Number of Deposits:
	//		 Number of Withdrawals:
	//		 Amount Gained From High Interest: 

private:
	long double highAnnualPercentYield = pow(1 + (0.025 / 12), 12) - 1;
	double* amountGainedFromHighInterest;
};