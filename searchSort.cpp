/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter 16: Searching, Sorting, and the vectorType
Objetive : Exercise 2
2.  Write a program to test the function binarySearch. Use either the function
bubbleSortor insertionSortto sort the list before the search.
*/

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

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

/*function to show elements*/
void showArray(int iarray[], int sizeArray)
{
    for (int i = 0; i < sizeArray; i++)
        printf("%d ", iarray[i]);

    cout << "\n";
}

/*Function seach element in array*/
int binarySearch(int larray[], int item, int low, int sizeArray, int opt)
{
    try{
        if (opt == 1)
        {
            if (sizeArray <= low)
                return (item > larray[low]) ? (low + 1) : low;

            int mid = (low + sizeArray) / 2;

            if (item == larray[mid])
                return mid + 1;

            if (item > larray[mid])
                return binarySearch(larray, item, mid + 1, sizeArray, 1);
            return binarySearch(larray, item, low, mid - 1, 1);
        }
        else
        {
            if (sizeArray >= low) {
                int mid = low + (sizeArray - low) / 2;

                if (larray[mid] == item)
                    return (mid + 1);

                if (larray[mid] > item)
                    return binarySearch(larray, item, low, mid - 1, 2);

                return binarySearch(larray, item, mid + 1, sizeArray, 2);
            }
            return -1;
        }
    }
    catch (const std::exception&)
    {
        cout << endl << "Exception has happened." << endl;
        system("pause");
        return -1;
    }
}

void insertionSort(int larray[], int isize)
{
    int i, position, dimention, selected;

    try {
        for (i = 1; i < isize; ++i)
        {
            dimention = i - 1;
            selected = larray[i];

            // location selected 
            position = binarySearch(larray, selected, 0, dimention, 1);

            // Move elements 
            while (dimention >= position)
            {
                larray[dimention + 1] = larray[dimention];
                dimention--;
            }
            larray[dimention + 1] = selected;
        }
    }
    catch (const std::exception&)
    {
        cout << endl << "Exception has happened." << endl;
        system("pause");

    }
}

bool testElement()
{

    int larray[] = { 51, 22, 32, 47, 100, 42,1,201,334,8762,2232,123,23,0 };
    int itemtoLook = 0;
    int sizeArray = sizeof(larray) / sizeof(larray[0]);
    int position = -1;
    int n = 0, nn = 0, key = 0; ; string _val; bool _exit = false;

    try {
        system("CLS");
        cout << endl;
        position = 0;
        cout << endl << "---------------> List of Numbers: " << endl;
        showArray(larray, sizeArray);
        cout << endl << "---------------> Ordered Numbers: " << endl;

        insertionSort(larray, sizeArray);
        showArray(larray, sizeArray);

        cout << endl << "--> Introduce element to search and [ENTER] or [Q] exit <--- " << endl;

        do {
            key = _getche(); // catch key
            if (key == 81 || key == 113) _exit = true; // Exit program
            if (_validate_input(key, 0)) { // validate key for numbers
                _val += key;
            };
            if (key == 13) break;

        } while (!_exit);

        position = binarySearch(larray, stoi(_val), 0, sizeArray, 2);
        (position == -1) ? cout << "Element do not exist." << endl
            : cout << "Element is position: " << position;
        cout << endl << "-----------------------------" << endl;

        system("pause");

        return _exit;

    }
    catch (const std::exception&)
    {
        cout << endl << "Exception has happened." << endl;
        system("pause");
    }
}

void main()
{
    bool result;

    do
    {
        result = testElement();

    } while (!result);


}
