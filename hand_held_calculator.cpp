/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming 
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter :  Midterm Project – 2020
Objetive : calculator
It will include addition, subtraction, multiplication, division + results from a single calculation.  
Must include a menu to allow the user to choose what arithmetic operation they want to complete.
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Class Calculator using code ASCII

class Calculator
{
public:
    double calculator(double x, int oper, double y)
    {
        // operator code ASCII
        switch (oper)
        {
        case 49:
            return x + y;
        case 50:
            return x - y;
        case 51:
            return x * y;
        case 52:
            return x / y;
        default:
            return 0;
        }
    }

    // function to validate inputs code ASCII
    bool _validate_input(int key, int type_validation)
    {

        int number = 0 ;
        bool is_ok = false;

        if (key == 13) return true;


        if ( key >= 42 &&  key <=59) {

            int int_value = key;
                is_ok = true;
        }

        if (!is_ok)
        {
            return is_ok;
        }

        return is_ok;
    }
    //Function to create menu for calculation
    void _create_Menu()
    {

        system("CLS");
        cout << "--------Menu-------" << endl ;
        cout << "| 1. Addition      |" << endl ;
        cout << "| 2. Subtraction   |" << endl ;
        cout << "| 3. Multiplication|" << endl ;
        cout << "| 4. Division      |" << endl ;
        cout << "-------------------" << endl ;
        cout << endl << "Enter option or 'Q' exit program." ;

    }

    //Function draw table with numbers
    void _screen_numbers(int oper)
    {

        system("CLS");

        switch (oper)
        {
        case 49:
            cout << "-----Addition-----" << endl << endl;
            break;
        case 50:
            cout << "-----Substration-----" << endl << endl;
            break;
        case 51:
            cout << "-----Multiplication-----" << endl << endl;
            break;
        case 52:
            cout << "-----Division-----" << endl << endl;
            break;
        default:
            cout << "The '" << char(oper) << "' is NOT correct value." << endl << "Enter correct values.." << endl << endl;
            system("pause");
        }

        cout << "---------------------" << endl ;
        cout << "| 7 | 8 | 9 |       |" << endl ;
        cout << "| 4 | 5 | 6 |       |" << endl;
        cout << "| 1 | 2 | 3 |       |" << endl;
        cout << "| 0 | . |   | Enter |" << endl;
        cout << "---------------------" << endl << endl;

    }

    //Function input values 
    void _values(int oper)
    {
        double x = 0.0;
        double y = 0.0;
        double result = 0.0;
        string value1 = "", value2 = "", value3="";
        int key = 0;


        switch (oper)
        {
        case 49:
            value1 = "Augend: ";
            value2 = "Avend: ";
            value3 = "multiplier : ";
            x = 0;
            break;
        case 50:
            value1 = "Subtrahend : ";
            value2 = "Minuend : ";
            value3 = "Sum : ";
            x = 0;
            break;
        case 51:
            value1 = "Multiplicand : ";
            value2 = "Multiplier : ";
            value3 = "Product : ";
            x = 0;
            break;
        case 52:
            value1 = "Dividend : ";
            value2 = "Divisor : ";
            value3 = "Quotient : ";
            x = 0;
            break;
        default:
            cout << "The '" << char(oper) << "' is NOT correct value." << endl << "Enter correct values.." << endl << endl;
            system("pause");

        }

        cout << "Enter " << value1;
        string  c ;

        do {

            key = _getche();

            if (!_validate_input(key, 0))
            {
                cout << "\b";
            } else   c += static_cast<char>(key);

        } while (key != 13);

        x = stoi(c); c = "";

        cout << endl << "Enter " << value2;
        do {

            key = _getche();

            if (!_validate_input(key, 0))
            {
                cout << "\b";
            }  else   c += static_cast<char>(key);

        } while (key != 13);

        y = stoi(c);

        result = calculator(x, oper, y);
        cout << endl << "The " << value3 << " is: -->" << result << "<---" <<endl;
        system("pause");


    }


};


// Program to test class
int main()
{
    int key;

    try
    {
        //Create object  calculator
        Calculator object_Cal;

        do {

            // Call menu 
            object_Cal._create_Menu();
            key = _getche();

            if (key == 81 || key == 113)
            {
                system("CLS");
                cout << "Thank you!" << endl; key = 81;
                system("pause");

            }
            else
            {
                // Validate inputs
                if (object_Cal._validate_input(key, 0))
                {
                    // Draw table with numbers
                    object_Cal._screen_numbers(key);
                    //Input values
                    object_Cal._values(key);
                }
            }
        } while (key != 81 );

    }
    catch (int e)
    {
        system("CLS");

        cout << "An exception occurred. Exception Nr. " << e << '\n';
        system("pause");

    }

}

