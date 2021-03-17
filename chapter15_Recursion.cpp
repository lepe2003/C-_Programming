/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter 15: Recursion
Objetive : Exercise 2


2. Write a program that prompts the user to enter the number of lines

*/

#include <iostream>
#include <time.h>
#include <string>
#include <conio.h>

using namespace std;

bool recursive_function(int,int,char); // Recursive function 
bool _validate_input(int, int); // Validate numbers


//Function to call the recursive function
int main()
{

    try
    {
        int n = 0, nn = 0, key = 0; char _char = 'X'; string _val; bool _exit = false;

        do {

            system("CLS");
            cout << endl;
            cout << endl << "Introduce number of lines in the pattern and [ENTER] or 'Q' to Exit]:" << endl;

            do
            {
                key = _getche(); // catch key
                if (key == 81 || key == 113) break; // Exit program
                if (_validate_input(key, 0)) { // validate key for numbers
                    _val += key;
                };
            } while (_val.length() < 2);
            if (key == 81 || key == 113) break;
            n = stoi(_val), nn = (n * 2) + 1;
            system("CLS");
            // call recursive function
            recursive_function(n, nn, _char);
            _val = "";
            system("pause");


        } while (!_exit);

        return 0;

    }
    catch (const std::exception&)
    {
        cout << endl << "Exception has happened." << endl;

    }

}

//Recursive function
bool recursive_function(int n, int nn, char pattern)
{   

    int x,i;
    string _str1 = "";
    if (n == 0)
    return false;

    for (i = 0; i < n; i++) {
        _str1 = "";
        _str1.insert(0, n, ' ');
        _str1.insert(_str1.size() , (nn-(n*2)), pattern);
        _str1.insert(_str1.size(), n , ' ');
        cout << _str1;
        cout << endl;
        recursive_function(n - 1, nn, pattern); // call recursive function

        cout << _str1 ;
        cout << endl;
        break;
    }

    return true;
}

// function to validate key for numbers, I dont want exceptions
bool _validate_input(int key, int type_validation)
{

    int number = 0;
    bool is_ok = false;

    if (key == 13) return true;
    if (key >= 48 && key <= 57) {
        int int_value = key;  is_ok = true;
    }
    if (!is_ok)
    {
        cout << "\b"; return is_ok;
    }
    return is_ok;
}

