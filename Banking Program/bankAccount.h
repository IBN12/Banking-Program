#pragma once
/*
Program: bankAccount.h (Specification File)
Description: Every bank account has an account number, the
name of the owner, and a balance. Therefore, instance variables such as
name, accountNumber, and balance should be declared in the abstract
class bankAccount. Some operations common to all types of accounts
are retrieve account owner's name, account number, and account balance;
make deposits; withdraw money; and create monthly statements. So
include functions to implement these operations.

Notes:
-> bankAccount will be a abstract class type with all pure virtual functions.

-> Pure Virtual Functions:
	inputAccountOwnersName()	
	inputAccountOwnersNumber()
	getAccountOwnersBalance()
	accountOwnersDeposit()
	accountOwnersWithdrawal()
	accountMonthlyStatements()
*/

#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
public:
	virtual void inputAccountOwnersName(string fName, string lName) = 0;
	// Pre: Function is a pure virtual function.
	//		The user will be able to input their
	//		first name and last name into the any
	//		checking account, savings account, and 
	//		certificate of deposit account.
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

	virtual void inputAccountOwnersNumber(int acctNum) = 0;
	// Pre: Function is a pure virtual function.
	//		The user will be able to input a 
	//		account number for the checking account,
	//		savings account, and certificate of deposit 
	//		account
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

	virtual double getAccountOwnersBalance() const = 0;
	// Pre: Function is a pure virtual function.
	//		The function will return the owners
	//		balance for the checkings account,
	//		savings account, and certificate of deposit 
	//		account.
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

	virtual void accountOwnersDeposit(double acctDep) = 0;
	// Pre: Function is a pure virtual function.
	//		The function will allow the user to
	//		deposit money into the account
	//		for the checking account, savings account, 
	//		and certificate of deposit account.
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

	virtual void accountOwnersWithdrawal(double acctWith) = 0;
	// Pre: Function is a pure virtual function.
	//		The function will allow the user to
	//		withdrawal money from the account for the
	//		checking account, savings account, and
	//		and certificate of deposit account.
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

	virtual void accountMonthlyStatements() const = 0;
	// Pre: Function is a pure virtual function.
	//		The Function will keep tracks of the
	//		monthly statements for the checking
	//		account, savings account, and certificate
	//		of deposit account.
	// Post: Derived Classes:
	//		 Checking Account
	//		 Savings Account
	//		 Certificate of Deposit Account

protected:
	string firstName;
	string lastName;
	int accountNumber;
	double accountBalance;
};