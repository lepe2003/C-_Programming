/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter : Chapter 10: Classes and Data Abstraction
Objetive : Exercise 10.6

a.Store the number as a positive integer.
b.Convertand store the number as a positive integer.
c.Print the number as a Roman numeral or positive integer as requested by the user.
*/

#include<iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

// Array (roman,value, ascii_lower, ascii_upper)
string Roman_values[7][4] = { { "M","1000","77","109"},
								{"D","500","68","100"},
								{ "C","100","67","99" },
								{ "L","50","76","108" },
								{ "X","10","88","120" },
								{ "V","5","86","118" },
								{ "I","1","73","105" } } ;

std::vector<int> Values_;

// Get size romans number
int long_array = sizeof(Roman_values) / sizeof(*Roman_values);

// function to validate data
bool validate_input(int key)
{
	
	char values[15];
	int number = 0, ck[15] = { 0 }, len = 0;
	bool is_ok = false;

	if (key == 13) return true;
	for (int i = 0; i < long_array; i++)
	{
		if ((key == stoi(Roman_values[i][2])) || (key == stoi(Roman_values[i][3]))) { 

			string str_value = Roman_values[i][1];
			int int_value = stoi(str_value);
			Values_.push_back(int_value) ; is_ok = true; i = long_array;
		}
	}

	if (!is_ok)
	{
		cout << "The '" << char(key) << "' is NOT correct value." << endl << "Enter correct values.." << endl << endl;
		return is_ok;
	}

	return is_ok;
}

// function to print values for roman numbers
void printValue()
{
	int number = 0, ck[15] = { 0 }, len = 0;
	bool ok = false;

	len = Values_.size();

	system("CLS");


	for (int x = 0; x < len; x++)
	{
		cout << "Number Selected: " << Values_[x] << endl ;
		number += Values_[x]; // addition numbers

	}
	cout  << endl<< "Value of Romans Numbers: " << number << endl << endl;
	system("pause");
}

//Function to create menu
void create_Menu()
{

	system("CLS");
	cout << "\tRoman Numeral Values" << endl << endl;

	// Print array with romas and values
	for (int x = 0; x < long_array; x++) 	cout << "\t\t" << Roman_values[x][0] << " = " << Roman_values[x][1] << endl;
	cout << endl << "Enter a Roman Numeral, 'F' finish enter vlaues, 'Q' exit program." << endl;

}

//Function to input Roman numbers
void enter_Roman()
{
	
	string val_string;
	int key;

	do
	{
		
		key = _getche();

		// Validate input data
		if (key == 81 || key==113)
			cout << "Thank you!" << endl;
		else
		{
			
			if (validate_input(key))  val_string += toupper(char(key));
			if (key == 70 || key == 102 || key == 13)
			{
				//strcpy_s(char_array, val_string.c_str());
				printValue();

				// Calll function to create a menu with numbers and romans
				create_Menu();

				//Clean values 
				val_string = "";
				if (Values_.size()>0) Values_.resize(0);
			}

		}


	} while (key != 81);
}


void main()
{
	try
	{
		
		// Calll function to create a menu 
		create_Menu();

		// Call funtion enter romans numbers
		enter_Roman();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}

}

