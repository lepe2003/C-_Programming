/*
Class : CSIS_223_Object-Oriented_Programming_C++_Programming
Student: Juan Ramon Lepe Manzo
ID: S1448233
Chapter 12: Inheritance and Composition
Problem 5 - SAVING, CHECKING AND CERFIFICATES OD DEPOSITS.


*/


#include <iostream>
using namespace std;

/*-------------------------------------------------------------------------*/
/*--------------------- class BankAccount ---------------------------------*/
/*-------------------------------------------------------------------------*/


class BankAccount {
protected:
	string _name; string _account; double _balance;

public:
	BankAccount()
	{
		 _balance = 0;
		 _account = "";
		 _name = "";
	};
	 ~BankAccount() {};

	 virtual string get_nameOwner()
	 {
		 return  _name;
	 }

	 virtual void set_nameOwner(string name)
	 {
		 _name = name;
	 }
	 
	 virtual string get_actNumber()
	{
		return  _account;
	}

	virtual void set_actNumber(string account)
	{
		_account = account;
	}

	virtual double get_balance()
	{
		return _balance;
	}

	virtual void set_balance(double balance)
	{
		_balance= balance;
	}

	virtual void make_deposit(double amount)
	{
		if (amount >= 0) _balance = _balance + amount; else	cout << "The withdraw ammount is invalid. " << endl;

	}

	virtual void withdraw_money(double amount)
	{
		if (amount >= 0) _balance -= amount; else cout << "The withdraw ammount is invalid." << endl;
	}

	virtual void monthly_statement(string month)
	{
		cout << "-----------BANK ACCOUNT----------" << endl;
		cout << "--------Monthly Statement--------" << endl;
		cout << "Month: " << month << endl;
		cout << "Account Number: " << _account << endl;
		cout << "Name: " << _name << endl;
		cout << "Account Balance: " << _balance << " dls" << endl;
		cout << "---------------------------------" << endl;
		system("pause");

	}

};

/*-----------------------------------------------------------------------------------*/
/*------------------------------- class CheckingAccount -----------------------------*/
/*-----------------------------------------------------------------------------------*/

class Checking_Account :  public BankAccount
{
protected:
	double _service_charges, _minBalance, _interest_rate;
	int _quantity_checks;
	double l_balance;
	string  l_account;
	string l_name;


public:
	Checking_Account(string name, string  account, double balance)
	{
		_account = account;
		_name = name;
		_balance = balance;

		_interest_rate = 0 /* Pay interest*/;
		_quantity_checks = 0; /* older to write checks */
		_minBalance = 0; /*miimal balance*/
		_service_charges = 0; /*No month services charge*/
	}

	~Checking_Account() {};

	virtual void open_account(string account, double balance) {
		make_deposit(balance);
		set_actNumber(account + "_checking");

	}

	virtual void set_interestRate(double rate)
	{
		_interest_rate = rate;
	} 
	
	
	virtual double get_quantity_checks()
	{
		return _quantity_checks;
	}

	virtual void set_quantity_checks(double quantity_checks)
	{
		_quantity_checks = quantity_checks;
	}

	virtual double get_interestRate()
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
		cout << endl << "-----------------" << endl;
		cout << endl << "New check by: " << amount << endl;
		cout << endl << "-----------------" << endl;

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
	void print_info_account(int type_account)
	{
		string leyend = "";
		switch (type_account)
		{
		case 1:
			leyend = "-----------BANK ACCOUNT----------";
			break;
		case 2:
			leyend = "-----------CHECKING ACCOUNT----------";
			break;
		case 3:
			leyend = "-----------SERVICE CHARGE CHECKING----------";
			break;
		case 4:
			leyend = "-----------NO SERVICE CHARGE CHECKING----------";
			break;
		case 5:
			leyend = "-----------HIGH INTEREST CHECKING----------";
			break;
		case 6:
			leyend = "-----------SAVING ACOUNT----------";
			break;
		case 7:
			leyend = "-----------CERTIFICATE OF DEPOSIT----------";
		default:
			exit;
			break;
		}
		cout << endl;
		cout << leyend  << endl;
		cout << "Account Number: " << get_actNumber() << endl;
		cout << "Name : " << get_nameOwner() << endl;
		cout << "Account Balance: " << get_balance() << endl;
		cout << "Minimum Balance: " << get_minBalance() << " dls" << endl;
		cout << "Interest: " << get_interestRate() << " %" << endl;
		cout << "Service Charge: " << get_service_charges() << " dls" << endl;
		//cout << "Is the balance greater than the minimum balance (1=YES,0=NO). " << check_balance_Min() << endl;
		cout << "-------------------------------------" << endl;
		system("pause");
	}
};

class serviceChargeChecking  
{
Checking_Account _Checking_Account;
public:
	serviceChargeChecking(string name, string account, double balance) : _Checking_Account(name, account, balance)
	{

		_Checking_Account.set_interestRate( 0); // Pay interest
		_Checking_Account.set_quantity_checks( 5); // older to write checks 
		_Checking_Account.set_minBalance( 0); //miimal balance
		_Checking_Account.set_service_charges( 0); //No month services charge
	};

	~serviceChargeChecking() {};

	virtual void make_deposit(double amount) {
		_Checking_Account.make_deposit(amount);
	}

	virtual void open_account(string account, double amount) {
		make_deposit(amount);
		_Checking_Account.set_actNumber(account+"_Chk_SCC");
	}

	virtual void write_ckeck(double amount) {
		_Checking_Account.write_Check(amount);
	}

	virtual void print_info_account(int type_account) {
		_Checking_Account.print_info_account( type_account);
	}


};
/*---------------------------------*/
class noServiceChargeChecking 
{
Checking_Account _Checking_Account;
public:
	noServiceChargeChecking(string name, string account, double balance) : _Checking_Account(name,account, balance)
	{

		_Checking_Account.set_interestRate(5); // Pay interest
		_Checking_Account.set_quantity_checks(99); // older to write checks 
		_Checking_Account.set_minBalance(100); //miimal balance
		_Checking_Account.set_service_charges(0); //No month services charge


	};

	~noServiceChargeChecking() {};

	virtual void make_deposit(double amount) {
		_Checking_Account.make_deposit(amount);
	}


	virtual void open_account(string account, double amount) {
		_Checking_Account.make_deposit(amount);
		_Checking_Account.set_actNumber(account + "_Chk_nSCC");

	}

	virtual void write_ckeck(double amount) {
		_Checking_Account.write_Check(amount);
	}

	virtual void print_info_account(int type_account) {
		_Checking_Account.print_info_account(type_account);
	}


};
/*----------------------------*/
class highInterestChecking  
{
	Checking_Account _Checking_Account;
public:
	highInterestChecking(string name, string  account, double balance) : _Checking_Account(name, account, balance)
	{

		_Checking_Account.set_interestRate( 15); // Pay high interest
		_Checking_Account.set_quantity_checks (99); // older to write checks 
		_Checking_Account.set_minBalance( 100); //minimal balance than noServiceChargeChecking accoun
		_Checking_Account.set_service_charges( 0); //No month services charge

		noServiceChargeChecking _noServiceChargeChecking();

	};

	~highInterestChecking() {};

	virtual void make_deposit(double balance) {
		_Checking_Account.make_deposit(balance);
	}

	virtual void open_account(string account, double balance) {
		_Checking_Account.set_actNumber(account + "Chk_HIC");
		make_deposit(balance);
	}

	virtual void print_info_account(int type_account) {
		_Checking_Account.print_info_account(type_account);
	}

};


/*-----------------------------------------------------------------------------------*/
/*------------------------------------class SavingAccount ---------------------------*/
/*-----------------------------------------------------------------------------------*/

class Saving_Account : public BankAccount
{
protected:
	double _rate;
	int _interest_rate ;
	double _min_balance;


public:
	Saving_Account(string name, string  _acount, double balance)
	{

		set_interestRate(5.0);
		postInterest();
		withdrawl(50);

		_balance = balance;
		_account = _acount;
		_name = name;
		_rate = 0;
		_min_balance = 0;
	}

	~Saving_Account(){	}

	virtual void _make_deposit(double balance) {
		make_deposit(balance);
	}

	virtual void open_account(string account, double balance) {
		set_actNumber(account + "_SA");
		_make_deposit(balance);
	}

	void set_interestRate(double rate)
	{
		_rate = rate;
	}
	double get_interestRate()
	{
		return _rate;
	}
	void postInterest()
	{
		_balance *= (1 + _rate / 100);
	}
	void set_min_balance(double min_balance)
	{
		_min_balance = min_balance;
	}
	double get_min_balance()
	{
		return _min_balance;
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
		cout << "Minimal Balance: " << get_min_balance() << endl;
		cout << "Account Balance: " << get_balance() << " dls" << endl;
		cout << "Interest Rate: " << get_interestRate() << " dls" << endl;
		cout << "-----------------------------------" << endl;
		system("pause");
	}

};
/*---------------------------------------------*/
class highInterestSaving  
{
	Saving_Account _Saving_Account;

public:

	highInterestSaving(string name, string account, double balance) : _Saving_Account( name, account, balance)
	{

		noServiceChargeChecking _noServiceChargeChecking();

		/*minimal balance than noServiceChargeChecking account*/
		_Saving_Account.set_min_balance(100);


	};
	~highInterestSaving() {};

	 virtual void make_deposit( double balance) {
		_Saving_Account.make_deposit(balance);
	}

	virtual void open_account(string account, double balance) {
		_Saving_Account.set_actNumber(account + "SA_HIS");
		make_deposit(balance);
	}

	virtual void print_info_account() {
		cout << "-----------HIGH INTEREST SAVING ACCOUNT----------" << endl;
		_Saving_Account.print_info_saving_account();
	}

};
/*-----------------------------------*/
class certificateOfDeposit : public BankAccount
{
protected:

	int _num_CD_maturity_months;
	double _rate;
	string _current_month;

public:

	certificateOfDeposit(string name, string account, double balance)
	{
		noServiceChargeChecking _noServiceChargeChecking();
		_balance = balance;
		_account = account;
		_name = name;

		_num_CD_maturity_months = 12;
		_rate = 5.0;
		 _current_month= "March";

	};
	~certificateOfDeposit() {};
	virtual void _make_deposit(double balance) {
		make_deposit(balance);
	}

	virtual void open_account(string account, double balance) {
		set_actNumber(account + "SA_COD");
		_make_deposit(balance);
	}

	void set_num_CD_maturity_months(int num_CD_maturity_months)
	{
		_num_CD_maturity_months = num_CD_maturity_months;
	}

	double get_num_CD_maturity_months()
	{
		return _num_CD_maturity_months;
	}

	void set_rate(double rate)
	{
		_rate = rate;
	}

	double get_rate()
	{
		return _rate;
	}


	void set_current_month(string current_month)
	{
		_current_month = current_month;
	}

	string get_current_month()
	{
		return _current_month;
	}


	virtual void print_info_account() {
		cout << "-----------CERTIFICATE OF DEPOSIT----------" << endl;
		cout << "Number of CD Maturity months: " + _num_CD_maturity_months << endl;
		cout << "Interest Rate: " + (int)_rate << endl;
		cout << "Current CD Month:" + _current_month << endl;
		monthly_statement(_current_month);
	}


};

/*-----------------------------------------------------------------------------------*/
/*---------------------program to test classes---------------------------------------*/
/*------------------------------ ----------------------------------------------------*/

int main()
{

	BankAccount object_Bank_account;

	/*---------- Open New Bank account ----------*/
	object_Bank_account.set_actNumber("1010123");
	cout << "\nNew num Account: " << object_Bank_account.get_actNumber() ;
	object_Bank_account.set_nameOwner("Juan Lepe");
	cout << "\nNew Client: " << object_Bank_account.get_nameOwner();
	object_Bank_account.make_deposit(5000);
	cout << "\nNew Balance: " << object_Bank_account.get_balance() << endl << endl;
	object_Bank_account.monthly_statement("MARCH");

	/*---------- open new Checking account ----------*/
	Checking_Account Object_checking_Bank(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());
	Object_checking_Bank.open_account(object_Bank_account.get_actNumber(), 7000);
	Object_checking_Bank.write_Check(100);
	Object_checking_Bank.print_info_account(2);

	/*---------- new service charge checking ----------*/
	serviceChargeChecking* object_serviceChargeChecking = new serviceChargeChecking(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());
	object_serviceChargeChecking->open_account(object_Bank_account.get_actNumber(),5000);
	object_serviceChargeChecking->write_ckeck(30);
	object_serviceChargeChecking->print_info_account(3);

	/*---------- new no service charge checking ----------*/
	noServiceChargeChecking* object_noServiceChargeChecking = new noServiceChargeChecking(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());
	object_noServiceChargeChecking->open_account(object_Bank_account.get_actNumber(), 6000);
	object_noServiceChargeChecking->write_ckeck(50);
	object_noServiceChargeChecking->print_info_account(4);

	/*---------- open new highInterestChecking account ----------*/
	highInterestChecking* object_highInterestChecking = new highInterestChecking(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());
	object_highInterestChecking->open_account(object_Bank_account.get_actNumber(),2000);
	object_highInterestChecking->print_info_account(5);

	/*---------- saving account ----------*/
	Saving_Account Object_Saving_Bank(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());;
	Object_Saving_Bank.open_account(object_Bank_account.get_actNumber(),7000);
	Object_Saving_Bank.print_info_saving_account();

	/*---------- highInterestSaving account ----------*/
	highInterestSaving* object_highInterestSaving = new highInterestSaving(Object_Saving_Bank.get_nameOwner(), Object_Saving_Bank.get_actNumber(), Object_Saving_Bank.get_balance());
	object_highInterestSaving->open_account(object_Bank_account.get_actNumber(),1000);
	object_highInterestSaving->print_info_account();

	certificateOfDeposit Object_certificateOfDeposit(object_Bank_account.get_nameOwner(), object_Bank_account.get_actNumber(), object_Bank_account.get_balance());
	Object_certificateOfDeposit.open_account(object_Bank_account.get_actNumber(),8000);
	Object_certificateOfDeposit.print_info_account();
	

	system("pause");
	return 0;



}
