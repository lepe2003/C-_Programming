/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233

Objetive :
Write an app that calculates the cost of all the supplies added to the user’s shopping list.
You create the shopping list.Also, it will give a total + taxes(you create).
Can use an array for this project.
*/


#include<iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

// Array deparment (ID_DEPARMENT, DESCRIPTION)
string deparment_values[5][2] = { { "1","The Produce department"},
								{"2","The Meat department"},
								{ "3","The Beer and Wine section",},
								{ "4","The Health and Beauty department",},
								{ "5","The Deli/Prepared Foods department"}};

// Array items (CODE_ID,ID_DEPARMENT, DESCRIPTION, PRICE, % TAX)
string Items_values[25][5] = { { "1","1","Flowers","109.09","5"},
								{"2","1","Nuts","100.10","10"},
								{ "3","1","Avocados","99.99" ,"4"},
								{ "4","1","Bannana","108.56" ,"6"},
								{ "5","1","Lemon","2.1" ,"15"},
								{ "6","2","Aungus beaf","3.50" ,"20"},
								{ "7","2","Sirlon","1.12" ,"30"},
								{ "8","2","Stake","11.40" ,"40"},
								{ "9","2","Ground Beef","18.30" ,"50"},
								{ "10","2","Lean Beaf","1.50" ,"60"},
								{ "11","3","Corona Extra","23.50" ,"10"},
								{ "12","3","Budweiser","12.12" ,"10"},
								{ "13","3","Heineken","24.10" ,"10"},
								{ "14","3","Tsingtao","12.5" ,"10"},
								{ "15","3","Snow","1.10" ,"10"},
								{ "16","4","Antacid","5.10" ,"5"},
								{ "17","4","Revlon Colorsilk","8.50" ,"15"},
								{ "18","4","Toothpaste","7.50" ,"25"},
								{ "19","4","Ibuprofen","11.50" ,"30"},
								{ "20","4","Spaguetti","1.5" ,"40"},
								{ "21","5","Toffee","2.5" ,"40"},
								{ "22","5","Mac and Cheese","3.5" ,"40"},
								{ "23","5","Chicken parmesan","1.5" ,"40"},
								{ "24","5","Pasta","5" ,"40"},
								{ "25","5","Macaroni","5" ,"40"}
							};

std::vector<int> Values_;

// Get size array
int long_array = sizeof(Items_values) / sizeof(*Items_values);
double _taxes;

// function to validate key for numbers, I dont want exceptions
bool _validate_input(int key)
{

	bool is_ok = false;


	if (key >= 48 && key <= 57) {

		is_ok = true;
	}
	if (!is_ok)
	{
		cout << "\b"; return is_ok;
	}
	return is_ok;
}

//Function to create menu
void _Menu_items(int _menu, int _valueDepto)
{
		// Get num deparment in store
	int long_deparment = sizeof(deparment_values) / sizeof(*deparment_values);
	int list_item = 0;
	int _num_dept ;
	double _total = 0;
	double _price = 0;
	double _tax = 0;

	_taxes = 0;
	_num_dept = _valueDepto;

	switch (_menu) {
	case 1:
		system("CLS");
		cout << "\t--> Welcome to Marketing Store <--" << endl << endl;

		// Print deparments
		for (int x = 0; x < long_deparment; x++) 	cout << "\t\t" << deparment_values[x][0] << " = " << deparment_values[x][1] << endl;
		cout << endl << "Enter # deparment or 'Q' exit program." << endl;

		break; //optional
	case 2:

		system("CLS");
		cout << "\t Deparment: " << deparment_values[_num_dept][1] << endl << endl;

		// Print items by deparment
		for (int x = 0; x < long_array; x++)
		{
			if (Items_values[x][1] == to_string(_valueDepto)) cout << "\t\t" << Items_values[x][0] << ". " << Items_values[x][2] << ". Price: $" << Items_values[x][3] << endl;
		}

		list_item = Values_.size();
		if (list_item > 0)
		{
			cout << "Shopping List" << endl << endl;

			// Print Shopping List
			for (int x = 0; x < list_item; x++)
			{
				for (int xx = 0; xx < long_array; xx++)
				{
					if (Items_values[xx][0] == to_string(Values_[x]))
					{
						_price = stod(Items_values[xx][3]);
						_tax = stod(Items_values[xx][4]);
						cout << "-> " << Items_values[xx][0] << ". " << Items_values[xx][2] << ". Price: $" << Items_values[xx][3] << endl;
						_total +=_price;
						_taxes += ((_tax * _price) / 100) / 100;
						_price = 0;
						_tax = 0;
					}
				}

			}
			cout << endl << "------------- " << endl;
			cout << "Subtotal: $" << _total << endl;
			cout << "Taxes: $" << _taxes << endl;
			cout << "------------- " <<  endl;
			cout << endl << "Total: $" << _total+_taxes << endl << endl;
		}
		cout << endl << "Select # product and ENTER or [Q] back main menu." << endl;
		break;
	default:
		cout << "\t Error option: " << endl << endl;
	}


}


//Function
void store()
{

	string val_string;
	int key=13;
	string _value="";
	int _deparment =0;
	int menu_list = 1;

	do
	{
		 if ((_deparment==0 && menu_list==1) || (menu_list ==2 && key == 13)) _Menu_items(menu_list, _deparment) ;

		key = _getche();
		_value = toupper(char(key));
		// Validate input data
		if (_value =="Q")
		{
			if (_deparment == 0 && menu_list == 1) exit(0);
			_deparment = 0;
			menu_list = 1;

		}
		else
		{
			if (_validate_input(key))
			{
				val_string += toupper(char(key));
				if (_deparment == 0) _deparment= stoi(val_string);
			}

			if (key == 13)
			{
				_value += key;
				if (key >= 49 || key <= 53)
				{
					if (menu_list > 1)
					{
						for (int xx = 0; xx < long_array; xx++)
						{
							if ((Items_values[xx][1] == to_string(_deparment)) && (Items_values[xx][0] == val_string))
							{
								Values_.push_back(stoi(val_string));
							}
						}
					}
					_value = key;
					menu_list = 2;
					val_string = "";

				}

			}

		}


	} while (key != 81);
}




void main()
{
	try
	{
		store();
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception Nr. " << e << '\n';
	}

}

