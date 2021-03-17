/* Class: CSIS_223_Object - Oriented_Programming_C++_Programming
Student : Juan Ramon Lepe Manzo
ID : S1448233
Chapter 13: Overloading and Templates
Objetive : Exercise 13.17

// 17. Write a program that uses C++11 random number generators to generate 25 real numbers between 10 and 100.

*/

#include <iostream>


using namespace std;

template <class myType>

myType random_number(myType _parameter) {
	
	myType _result = (10 + rand() % 90); 
	myType _result_bouble = _parameter;

	try
	{
		double _decimal, _int;
		_decimal = modf(_parameter, &_int);
		if (_decimal > 0) return _result_bouble; else return _result;

	}
	catch (int e)
	{
		return 0;
	}

}

int main()
{
	// using template 
	for (int i = 1; i <= 25; i++) {
		cout << "Random number (" << i << ")---> " << random_number<int>(i) << endl;
	};

	// Overloading
	cout << endl << "Overloading function with value: " << random_number<float>(3.1416) << endl;



}

