// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int size;
	cout << "Size : ";
	cin >> size;

	// dynamic allocation
	int* arr = new int[size];
	
	cout << "Create the array " << endl;

	for (int i = 0; i < size; i++) {
		cout << "Array[" << i << "] : ";
		cin >> arr[i];
	}

	// show the user created array

	for (int i = 0; i < size; i++) {
		//cout << arr[i] << "\t";
		cout << *(arr + i) << "\t";
	}

	// deallocate
	delete[]arr;
	arr = NULL;

	system("pause>0");
}