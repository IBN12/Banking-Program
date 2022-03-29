#pragma once
/*
Program: checkingAccount.h (Specification file)
Description: A checking account is a bank account.
Therefore, it inherits all the properties of a bank account.
Because one of the objectives of a checking account is to be
able to write checks.

Notes:
-> A pure virtual function writeCheck will be included in the declared
class type. 

-> The declared class type will be a abstract class type since it only has
a pure virtual function.
*/

#include "bankAccount.h"

class checkingAccount : public bankAccount
{
public:
	virtual void writeCheck(string payToTheOrderOf, string memo, double Amount) = 0;
	// Pre: Function is a pure virtual function. 
	//		This function allow the user to write a check for
	//		all the classes derived from the base class 
	//		checking account.
	// Post: Derived Classes:
	//		 serviceChargeChecking
	//		 noServiceChargeChecking 
	//		 Class derived from the base class noServiceChargeChecking:
	//		 highInterestChecking

};