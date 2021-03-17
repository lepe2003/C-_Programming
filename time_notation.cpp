/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter 14: Exception Handling
Objetive : Exercise 13.17

// 17. Write a program that uses C++11 random number generators to generate 25 real numbers between 10 and 100.

*/
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// exception class for hours
class invalidHr
{
public:
	invalidHr() {};
	~invalidHr() {};

protected:
	int hrs_max = 12;
	bool v_Hr(int hr) {
		try
		{
			if (hr > hrs_max) { // validation hours
				throw 10;
			}
			else
			{
				return true;
			}
		}
		catch (int e) // exception
		{
			system("CLS");
			cout << endl << "---------------------------------" << endl;
			cout << "--		Invalid hour			--" << endl;
			cout << "--		12-hour notation		--" << endl;
			cout << "---------------------------------" << endl;
			system("pause");
			return false;
		}
	};
};


// exception class for minutes

class invalidMin
{
public:
	invalidMin() {};
	~invalidMin() {};

protected:
	int min_max = 60;
	bool v_Min(int min) {
		try
		{
			if (min > min_max) { //validation minutes
				throw 10;
			}
			else
			{
				return true;
			}
		}
		catch (int e) // exception
		{
			system("CLS");

			cout << endl << "---------------------------------" << endl;
			cout << "--		Invalid minutes" << endl;
			cout << "--		60 minutes max" << endl;
			cout << "--		'Enter' to continue " << endl;
			cout << "---------------------------------" << endl;
			system("pause");
			return false;
		}
	};
};

// exception class for seconds
class invalidSec
{
public:
	invalidSec() {};
	~invalidSec() {};

protected:
	int sec_max = 60;
	bool v_Sec(int sec) {
		try
		{
			if (sec > sec_max) { // validation seconds
				throw 10;
			}
			else
			{
				return true;
			}
		}
		catch (int e) // exception
		{
			system("CLS");
			cout << endl << "---------------------------------" << endl;
			cout << "--		Invalid seconds" << endl;
			cout << "--		60 seconds max" << endl;
			cout << "--		'Enter' to continue " << endl;
			cout << "---------------------------------" << endl;
			system("pause");
			return false;
		}
	};
};

class _time: public invalidHr, invalidMin, invalidSec
{
public:
	~_time() {};

	int _time_values[4]; // HH:mm:ss
	int _time_format; // 0= 12-hour notation, 1= 24-hour notation
	int _time_meridiem ; // AM, PM

	// function to validate inputs code ASCII
	bool _validate_input(int key, int type_validation)
	{

		int number = 0;
		bool is_ok = false;

		if (key == 13) return true;


		if (key >= 48 && key <= 57) {

			int int_value = key;
			is_ok = true;
		}

		if (!is_ok)
		{
			cout << "\b";
			return is_ok;
		}

		return is_ok;
	}

	void set_hrs() {
		string hrs_val ;
		int key =0;

		do
		{
			hrs_val = "";
			system("CLS");
			cout << endl << "Introduce Hours:" << endl;

			do
			{
				key = _getche();
				if (key == 13) break;
				if (_validate_input(key, 0)) {
					hrs_val += key;
				}; 
			} while (hrs_val.length() < 2);
			if (hrs_val.length() == 0) hrs_val = "12";
		} while (!v_Hr(stoi(hrs_val)));
		_time_values[0] = stoi(hrs_val);




	};

	void set_mins() {
		string min_val;
		int key = 0;

		do
		{
			min_val = "";
			system("CLS");
			cout << endl << "Hours:  " << efill(_time_values[0]) << endl;
			cout << endl << "Introduce Minutes:" << endl;

			do
			{
				key = _getche();
				if (key == 13) break;
				if (_validate_input(key, 0)) {
					min_val += key;
				};
			} while (min_val.length() < 2);
			if (min_val.length() == 0) min_val = "0";
		} while (!v_Min(stoi(min_val)));

		_time_values[1] = stoi(min_val);

	};

	void set_secs() {

		string sec_val;
		int key = 0;

		do
		{
			sec_val = "";

			system("CLS");
			cout << endl << "Hours:  " << efill(_time_values[0]) << endl;
			cout << endl << "Minutes:  " << efill(_time_values[1]) << endl;
			cout << endl << "Introduce Seconds:" << endl;

			do
			{
				key = _getche();
				if (key == 13) break;
				if (_validate_input(key, 0)) {
					sec_val += key;
				};

			} while (sec_val.length() < 2);
			if (sec_val.length() == 0) sec_val = "0";
		} while (!v_Sec(stoi(sec_val)));
		_time_values[2] = stoi(sec_val);

	};

	void set_meridian()
	{
		int key = 0;
		string meridiem_val;
		_time_meridiem = 3;

		system("CLS");
		cout << endl << "Hours:  " << efill(_time_values[0]) << endl;
		cout << endl << "Minutes:  " << efill(_time_values[1]) << endl;
		cout << endl << "Seconds:  " << efill(_time_values[2]) << endl;
		cout << endl << "Select 1 = AM or 2 = PM. " << endl;

		do
		{
			key = _getche();
			if (key == 13) break;
			if (_validate_input(key, 0)) {
				if (key == 49 || key == 50) {
					meridiem_val = key;
				}
			};

		} while (!(key == 49 || key == 50));
		_time_meridiem =stoi( meridiem_val);
	};

	string efill(int _value) {
		string _local = to_string(_value);

		return _local.insert(0, 2 - _local.size(), '0');
	}

	void show_time_24_notation()
	{
		string _notation = "";

		_notation = (_time_meridiem == 1) ? "AM" : "PM";
		system("CLS");

		cout << endl << "------------- " << endl;
		cout << endl << "The time in 24-hour notation --> "  << efill(get_hrs(_time_meridiem)) <<":"<< efill(get_mins()) <<":"<< efill(get_secs()) << " "<< _notation  << endl;
		cout << endl << "------------- " << endl;
		system("pause");
	}

	int get_hrs(int _notation) {
		if (_notation == 1)
		{
			return _time_values[0];
		}
		else if (_notation == 2)
		{
			return _time_values[0] + 12;

		}
	}

	int get_mins() {
		return 	_time_values[1];
	}

	int get_secs() {
		return 	_time_values[2];
	}
};

int main()
{
		_time _Mytime;

		system("CLS");
		cout << endl << "-------------------------------------------" << endl;
		cout << endl;
		cout << "Program that prompts the user to enter time in 12-hour notation" << endl;
		cout << "and then outputs time in 24-hour notation." << endl;
		cout << endl << "--------------------------------------------" << endl;
		cout << endl;
		system("pause");
		// Set Hours
		_Mytime.set_hrs();
		// Set Minutes
		_Mytime.set_mins();
		// Set seconds
		_Mytime.set_secs();
		// Set AM, PM
		_Mytime.set_meridian();
		//Display time in 24 notation
		_Mytime.show_time_24_notation();


}

