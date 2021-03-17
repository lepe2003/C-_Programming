/*
Class : CSIS_223_Object-Oriented_Programming_C++_Programming
Student: Juan Ramon Lepe Manzo
ID: S1448233
Chapter 11: Inheritance and Composition 
Problem 13 - The class bankAccount.

a) ----------------class "BANKACCOUNT" --------------

1. set the account number, 
2. retrieve the account number, 
3. retrieve the balance, 
4. deposit 
5. withdraw money, 
6. print account information.

b)  --------------class "CHECKING" account.--------
1. set interest rate, 
2. retrieve interest rate, 
3. set minimum balance, 
4. retrieve minimum balance, 
5. set service charges, 
6. retrieve service charges,
7. post interest, 
8. verify if the balance is less than the minimum balance, 
9. write a check, withdraw(override the method of the base class), 
10. print account information.

c) ------------------------Class"SAVINGS" account.

1. set interest rate, 
2, retrieve interest rate, 
3, post interest, 
4. withdraw(override the method of the base class),  
5. print account information.
*/


#include <iostream>
using namespace std;

/*-------------------------------------------------------------------------*/
/*--------------------- class BankAccount ---------------------------------*/
/*-------------------------------------------------------------------------*/

class Bank_Account {
public:
	double _balance;
	int _account = 0;


	 Bank_Account()
	{
		 _balance = 0;
		 _account = 0;

	};
	 ~Bank_Account() {};

	int get_actNumber()
	{
		return  _account;
	}

	void set_actNumber(int num_act)
	{
		_account = num_act;
	}

	void set_deposit(double amount)
	{
		if (amount >= 0) _balance = _balance + amount; else	cout << "The withdraw ammount is invalid. " << endl;

	}

	void get_money(double amount)
	{
		if (amount >= 0) _balance -= amount; else cout << "The withdraw ammount is invalid." << endl;
	}

	void print_info_bank_account()
	{
		cout << "-----------BANK ACCOUNT----------" << endl;
		cout << "Account Number: " << _account << endl;
		cout << "Account Balance: " << _balance << " dls" << endl;
		cout << "---------------------------------" << endl;
		system("pause");

	}

	double get_balance()
	{
		return _balance;
	}

};

/*--------------------------------------------------------------------------------------------------------*/
/*------------------------------- class CheckingAccount --------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

class Checking_Account :  public Bank_Account
{
public:
	Checking_Account(int _acount, double balance)
	{
		_balance = balance;
		_account = _acount;

		_interest_rate = 0;
		_minBalance = 0;
		_service_charges = 0;
	}

	~Checking_Account() {};
	
protected:
	double _service_charges, _minBalance, _interest_rate;

public:
	void set_interestRate(double rate)
	{
		_interest_rate = rate;
	}
	double get_interestRate()
	{
		return _interest_rate;
	}
	void set_minBalance(double minBal)
	{
		_minBalance = minBal;
	}
	double get_minBalance()
	{
		return _minBalance;
	}
	void set_service_charges(double fee)
	{
		_service_charges = fee;
	}
	double get_service_charges()
	{
		return _service_charges;
	}
	void postInterest()
	{
		_balance *= (1 + _interest_rate / 100);
	}

	bool check_balance_Min()
	{
		return (_balance >= _minBalance) ? true : false;
	}
	void write_Check(double amount)
	{
		if (amount >= 0)  with_drawl(amount); else  cout << "The amount is invalid." << endl;
	}
	void with_drawl(double amount)
	{

		if (amount < 0)
		{
			cout << "The amount is invalid." << endl;
			exit;
		}

		if (_balance < amount)
		{
			cout << "insufficient funds. Withdraw rejected." << endl;
		}
		else
		{
			if (_balance - amount >= _minBalance)
			{
				_balance -= amount;
			}
			else
			{
				_balance -= (amount + _interest_rate);

			}

		}
	}
	void print_info_checking_account()
	{
		cout << endl;
		cout << "-----------CHECKING ACCOUNT----------" << endl;
		cout << "Account Number: " << get_actNumber() << endl;
		cout << "Account Balance: " << get_balance() << endl;
		cout << "Minimum Balance: " << get_minBalance() << " dls" << endl;
		cout << "Interest: " << get_interestRate() << " dls" << endl;
		cout << "Service Charge: " << get_service_charges() << " dls" << endl;
		cout << "Is the balance greater than the minimum balance (1=YES,0=NO). " << check_balance_Min() << endl;
		cout << "-------------------------------------" << endl;
		system("pause");
	}
};

/*--------------------------------------------------------------------------------------------------------*/
/*------------------------------------class SavingAccount -----------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------*/

class Saving_Account : public Bank_Account
{
protected:
	double _rate;

public:
	Saving_Account(int _acount, double balance)
	{
		_balance = balance;
		_account = _acount;

		_rate = 0;
	}

	~Saving_Account(){	}
	
	void set_interestRate(double rate)
	{
		//_balance = get_balance();
		_rate = rate;
	}
	double get_interestRate()
	{
		return _rate;
	}
	void postInterest()
	{
		_balance = _balance;
		//_balance *= (1 + _rate / 100);
	}
	void withdrawl(double amount)
	{
		if (_balance >= amount)	_balance -=  amount; else cout << "Insufficient funds. Withdrawl transaction rejected." << endl;
	}
	void print_info_saving_account()
	{
		cout << endl;
		cout << "-----------SAVING ACCOUNT----------" << endl;
		cout << "Account Number: " << get_actNumber() << endl;
		cout << "Account Balance: " << get_balance() << " dls" << endl;
		cout << "Interest Rate: " << get_interestRate() << " dls" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
	}

};

/*--------------------------------------------------------------------------------------------------------*/
/*---------------------program to test classes------------------------------------------------------------*/
/*------------------------------ -------------------------------------------------------------------------*/

int main()
{
	
	Bank_Account object_Bank;

	/*---------- Bank account ----------*/
	object_Bank.set_actNumber(1010123);
	cout << "\nNew num Account: " << object_Bank.get_actNumber() ;
	object_Bank.set_deposit(5000);
	cout << "\nNew Balance: " << object_Bank.get_balance() << endl << endl;
	object_Bank.print_info_bank_account();

	/*---------- Checking account ----------*/
	Checking_Account Object_checking_Bank(object_Bank.get_actNumber(), object_Bank.get_balance());
	Object_checking_Bank.set_service_charges(15);
	Object_checking_Bank.set_minBalance(450);
	Object_checking_Bank.set_interestRate(3);
	Object_checking_Bank.postInterest();
	Object_checking_Bank.write_Check(100);
	Object_checking_Bank.print_info_checking_account();

	/*---------- Checking account ----------*/
	Saving_Account Object_Saving_Bank(object_Bank.get_actNumber(), object_Bank.get_balance());;
	Object_Saving_Bank.set_interestRate(5.0);
	Object_Saving_Bank.postInterest();
	Object_Saving_Bank.withdrawl(50);
	Object_Saving_Bank.print_info_saving_account();
		
	system("pause");
	return 0;



}
