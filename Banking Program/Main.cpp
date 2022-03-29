/*
Program: Main (Main Function)
Description: This is the user-defined program.

Demonstration: This program will demonstrate the use of
abstract classes and pure virtual functions.

Background: Banks offer various types of accounts, such as savings, checking, 
certificate of deposit, and money market, to attract customers as 
well as meet their specific needs. Two of the most commonly used accounts
are savings and checking. Each of these accounts have various options.
For example, you may have a savings account that requires no minimum 
balance but has a lower interest rate. Similarly, you may have a checking
account that limits the number of checks you may write. Another type of account
that is used to save money for the long term is certificate of deposit (CD).

Date: Feb-9-2022
*/

#include "serviceChargeChecking.h"
#include "noServiceChargeChecking.h"
#include "highInterestChecking.h"
#include "SavingsAccount.h"
#include "highInterestSavings.h"
#include "certificateOfDeposit.h"
#include <iomanip>
using namespace std;

int main()
{
	// local variables
	serviceChargeChecking FirstCheckingAccount;

	// statements
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "$500.00 deposited" << endl;
	FirstCheckingAccount.accountOwnersDeposit(500.00);
	cout << "Account Balance: $" << FirstCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "||||||Selection 1 - Service Charge Checking Account||||||" << endl;
	FirstCheckingAccount.writeCheck("Alec Barstad", "Dinner", 40.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl;

	FirstCheckingAccount.writeCheck("Mother", "Bills", 200.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl;

	FirstCheckingAccount.writeCheck("Aunt", "Birthday", 60.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl;

	FirstCheckingAccount.writeCheck("Jordan", "Money returned for shoes", 200.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl;

	FirstCheckingAccount.writeCheck("Erich", "Pay Back", 20.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl;

	cout << "$100 Deposited" << endl;
	FirstCheckingAccount.accountOwnersDeposit(100.00);
	cout << "Account Balance: $" << FirstCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	FirstCheckingAccount.writeCheck("Anderson", "Money return", 30.00);
	FirstCheckingAccount.accountMonthlyStatements();
	cout << endl << endl;
	
	FirstCheckingAccount.inputAccountOwnersName("Isom", "Brooks-Enge");
	FirstCheckingAccount.inputAccountOwnersNumber(55256320);
	FirstCheckingAccount.print();
	cout << endl;

	cout << "||||||Selection 2 - No Service Charge Checking Account||||||" << endl;
	noServiceChargeChecking SecondCheckingAccount(3);
	cout << "$600.00 Deposited" << endl;
	SecondCheckingAccount.accountOwnersDeposit(600.00);
	SecondCheckingAccount.print();
	cout << endl;

	SecondCheckingAccount.inputAccountOwnersName("Isom", "Brooks-Enge");
	SecondCheckingAccount.inputAccountOwnersNumber(55256666);
	SecondCheckingAccount.accountMonthlyStatements(); 
	SecondCheckingAccount.print();
	cout << endl;

	SecondCheckingAccount.writeCheck("Mother", "Gift", 130.00);
	SecondCheckingAccount.accountMonthlyStatements();
	cout << endl;

	SecondCheckingAccount.print();
	cout << endl;

	SecondCheckingAccount.writeCheck("Aunt", "Gift", 130.00);
	SecondCheckingAccount.accountMonthlyStatements();
	cout << endl;

	cout << "$600 Deposited" << endl;
	SecondCheckingAccount.accountOwnersDeposit(600.00);
	cout << "Account Balance: " << SecondCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	SecondCheckingAccount.writeCheck("Aunt", "Gift", 100.00);
	SecondCheckingAccount.writeCheck("Grandma", "Gift", 200.00);
	SecondCheckingAccount.accountMonthlyStatements();
	cout << endl;

	SecondCheckingAccount.writeCheck("Alec", "Food", 30.00);
	SecondCheckingAccount.accountMonthlyStatements();
	cout << endl;

	SecondCheckingAccount.print();
	cout << endl;

	cout << "||||||Selection 3 - High Interest Checking Account||||||" << endl;
	highInterestChecking ThirdCheckingAccount(5);
	ThirdCheckingAccount.print();
	cout << endl;

	cout << "$2000.00 Deposited" << endl;
	ThirdCheckingAccount.accountOwnersDeposit(2000.00);
	cout << "Account Balance: " << ThirdCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	ThirdCheckingAccount.inputAccountOwnersName("Isom", "Brooks-Enge");
	ThirdCheckingAccount.inputAccountOwnersNumber(02365255);
	ThirdCheckingAccount.writeCheck("Manday", "Gift", 100.00);
	ThirdCheckingAccount.writeCheck("Erich", "Gift", 100.00);
	ThirdCheckingAccount.writeCheck("Jordan", "Repayment for Shoes", 60.00);
	ThirdCheckingAccount.writeCheck("Blade", "Repayment for shoes", 80.00);
	ThirdCheckingAccount.writeCheck("Alec", "Food", 10.00);
	ThirdCheckingAccount.writeCheck("Lynda", "Pity Money", 1.00);
	ThirdCheckingAccount.accountMonthlyStatements();
	cout << endl;

	cout << "Amount Gained From High Interest: " << ThirdCheckingAccount.getAmountGainedFromHighInterest() << endl;
	cout << endl; 

	ThirdCheckingAccount.print();
	cout << endl;

	cout << "Withdrawal $1000" << endl;
	ThirdCheckingAccount.accountOwnersWithdrawal(1000);
	cout << "Account Balance: " << ThirdCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Attempt to Withdraw $100.00" << endl;
	ThirdCheckingAccount.accountOwnersWithdrawal(100.00);
	cout << "Account Balance: " << ThirdCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "$2000 Deposited" << endl;
	ThirdCheckingAccount.accountOwnersDeposit(2000.00);
	cout << "Account Balance: " << ThirdCheckingAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "||||||Selection 4 - Savings Account||||||" << endl;
	savingsAccount FirstSavingsAccount;
	FirstSavingsAccount.accountMonthlyStatements();
	cout << endl;

	FirstSavingsAccount.print();
	cout << endl;

	cout << "Deposits $2000.00" << endl;
	FirstSavingsAccount.accountOwnersDeposit(2000.00);
	cout << "Account Balance: " << FirstSavingsAccount.getAccountOwnersBalance() << endl << endl;

	cout << "Deposits $100.00" << endl; 
	FirstSavingsAccount.accountOwnersDeposit(100.00);
	cout << "Account Balance: " << FirstSavingsAccount.getAccountOwnersBalance() << endl << endl;

	cout << "Deposits $60.00" << endl;
	FirstSavingsAccount.accountOwnersDeposit(60.00);
	cout << "Account Balance: " << FirstSavingsAccount.getAccountOwnersBalance() << endl << endl;

	cout << "Withdrawal $30.00" << endl;
	FirstSavingsAccount.accountOwnersWithdrawal(30.00);
	cout << "Account Balance: " << FirstSavingsAccount.getAccountOwnersBalance() << endl << endl;

	FirstSavingsAccount.accountMonthlyStatements();
	cout << endl;

	FirstSavingsAccount.print();
	cout << endl;

	FirstSavingsAccount.inputAccountOwnersName("Isom", "Brooks-Enge");
	FirstSavingsAccount.inputAccountOwnersNumber(63205525);
	FirstSavingsAccount.print();
	cout << endl;

	cout << "||||||Selection 5 - High Interest Savings Account||||||" << endl;
	highInterestSavings SecondSavingsAccount;
	SecondSavingsAccount.print();
	cout << endl;

	SecondSavingsAccount.inputAccountOwnersName("Bob", "McDonald");
	SecondSavingsAccount.inputAccountOwnersNumber(63201234);
	cout << "Attempt to withdraw money from account." << endl;
	SecondSavingsAccount.accountOwnersWithdrawal(10.00);
	cout << endl;

	cout << "Deposits $1000.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(1000.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $10.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(20.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $130.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(130.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Withdrawal $100.00" << endl;
	SecondSavingsAccount.accountOwnersWithdrawal(100.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	SecondSavingsAccount.accountMonthlyStatements();
	cout << endl;

	cout << "Amount gained from high interest: $" << SecondSavingsAccount.getAmountGainedFromHighInterest() << endl;
	cout << endl;

	SecondSavingsAccount.print();
	cout << endl;

	cout << "Deposits $100.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(100.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $50.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(50.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $5.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(5.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $330.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(330.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $27.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(27.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Number of Deposits: " << SecondSavingsAccount.getNumberOfDeposits() << endl;
	cout << endl;

	cout << "Deposits $1000.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(1000.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $10.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(10.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	SecondSavingsAccount.accountMonthlyStatements();
	cout << endl;

	cout << "Deposits $1.00" << endl;
	SecondSavingsAccount.accountOwnersDeposit(1.00);
	cout << "Account Balance: $" << SecondSavingsAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	SecondSavingsAccount.accountMonthlyStatements();
	cout << endl;

	SecondSavingsAccount.print();
	cout << endl;

	cout << "||||||Selection 6 - Certificate of Deposit||||||" << endl;
	certificateOfDeposit cdAccount;
	
	cdAccount.print();
	cout << endl;
	
	cout << "Deposits $600.00" << endl;
	cdAccount.accountOwnersDeposit(600.00);
	cout << endl;

	cdAccount.print(); 
	cout << endl;

	cout << "Deposits $500.00" << endl;
	cdAccount.accountOwnersDeposit(500.00);
	cout << endl;

	cout << "Account Balance: " << cdAccount.getAccountOwnersBalance() << endl;
	cout << "Months of Maturity: " << cdAccount.getAmountOfMonths() << endl;
	cout << "Current Month: " << cdAccount.getCurrentMonth() << endl;
	cout << endl;

	cdAccount.print();
	cout << endl;

	cdAccount.inputAccountOwnersName("Elhayam", "Van Houten");
	cdAccount.inputAccountOwnersNumber(55256320);
	cdAccount.print();
	cout << endl;

	cout << "Attempting to withdraw $10.00" << endl;
	cdAccount.accountOwnersWithdrawal(10.00);
	cout << endl;

	cout << "Amount Gained From Interest: " << cdAccount.getAmountGainedFromInterest() << endl;
	cout << endl;
	cdAccount.print();
	cout << endl;

	cdAccount.accountMonthlyStatements();
	cout << endl;

	cout << "Withdrawal $20.00" << endl;
	cdAccount.accountOwnersWithdrawal(20.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $120.00" << endl;
	cdAccount.accountOwnersDeposit(120.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $10.00" << endl;
	cdAccount.accountOwnersDeposit(10.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $40.00" << endl;
	cdAccount.accountOwnersDeposit(40.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $5.00" << endl;
	cdAccount.accountOwnersDeposit(5.00); 
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $35.00" << endl;
	cdAccount.accountOwnersDeposit(35.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl; 

	cout << "Deposits $1.00" << endl; 
	cdAccount.accountOwnersDeposit(1.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $2.00" << endl;
	cdAccount.accountOwnersDeposit(2.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $25.00" << endl;
	cdAccount.accountOwnersDeposit(25.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cdAccount.accountMonthlyStatements();
	cout << endl;

	cout << "Deposits $300.00" << endl;
	cdAccount.accountOwnersDeposit(300.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cout << "Deposits $240.00" << endl;
	cdAccount.accountOwnersDeposit(240.00);
	cout << "Account Balance: $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << "Months of Maturity: " << cdAccount.getAmountOfMonths() << endl;
	cout << "Current Month: " << cdAccount.getCurrentMonth() << endl;
	cout << endl;

	cout << "Deposits $10.00" << endl;
	cdAccount.accountOwnersDeposit(10.00);
	cout << "Account Balance:  $" << cdAccount.getAccountOwnersBalance() << endl;
	cout << endl;

	cdAccount.accountMonthlyStatements();
	cout << endl;

	cdAccount.print();
	cout << endl;

	

	return 0;
}