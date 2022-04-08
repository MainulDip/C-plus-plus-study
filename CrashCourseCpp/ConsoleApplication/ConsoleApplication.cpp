// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int rows, cols;
	cout << "Rows , Cols" << endl;
	cin >> rows >> cols;

	// create the **table and 1st array / linking pointer table array
	int** table = new int* [rows];

	// create 2nd dynamic array by looping
	for (int i = 0; i < rows; i++) {
		// create the array with the specified values
		table[i] = new int[cols];
	}

	// inter/set value of a col/array slot
	cout << "Enter in the table[1][2] slot : ";
	cin >> table[1][2];

	cout << "You Inserted : " << table[1][2] << endl;

	// delete the last array first 
	for (int i = 0; i < rows; i++) {
		delete[] table[i];
	}

	// delete the linking array
	delete[] table;
	table = NULL;

	system("pause>0");
}