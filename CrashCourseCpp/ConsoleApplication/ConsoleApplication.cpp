// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int n = 7;
	cout << "n's address is &n = " << &n << " and value is n = " << n << endl;
	int* pointerN = &n;
	cout << "pointerN is : " << pointerN << " and the value/dereferenced of the *pointerN = " << *pointerN << endl;
	*pointerN = 10;
	cout << "After re assaigning to 10 pointerN is : " << pointerN << " and the value/dereferenced of the *pointerN = " << *pointerN << endl;
	cout << "The n value is also changed as n = " << n << endl;

	// other way
	int& refN = n;
	cout << "Now the value of refN = " << refN << endl;

	cout << "\n now create another pointer\n" << endl;

	int* newPN = &refN;
	cout << "Now the newPN = " << newPN << " and *newPN " << *newPN << endl;
	(*newPN)++;
	cout << "\n\nAdding (*newPN)++ newPN = " << newPN << " and *newPN " << *newPN << endl;
	cout << "The n value is also changed as n = " << n << endl;

	// assaigning new value to old pointer
	int anotherVal = 77;
	newPN = &anotherVal;
	cout << "\n\n*newPN = " << *newPN << endl; // *newPN = 77
	// this will not change the n valu as it has separate memory location
	cout << "n = " << n << endl; // n = 11
	cout << "this will not change the n valu as it has separate memory location\n\n" << endl;
	// reassaigning to reference will cange the n's value as both memory location is same;
	refN = anotherVal;
	cout << "New refN = " << refN << endl; // New refN = 77
	cout << "n = " << n << endl; // n = 77

	cout << "reassaigning to reference will cange the n's value as both memory location is same" << endl;

	system("pause>0");
}