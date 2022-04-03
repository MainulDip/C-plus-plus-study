// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


int main()
{
	int numbers[7] = { 1,2,3,4,5,6,7 };
	cout << "numbers : " << numbers << endl;
	cout << "&numbers : " << &numbers << endl;
	cout << "numbers[6] : " << numbers[6] << endl;
	cout << "&numbers[6] : " << &numbers[6] << endl;

	int* numPointer = numbers;
	cout << "numPointer Pointing to " << numPointer << " , Value: *numPointer " << *numPointer << endl;
	numPointer++;
	cout << "numPointer++ Pointing to " << numPointer << " , Value: *numPointer " << *numPointer << endl;
	numPointer++;
	cout << "numPointer++ Pointing to " << numPointer << " , Value: *numPointer " << *numPointer << endl;

	cout << "&number[6] : " << (&numbers[6]) << " where numPointer + 3 = " << numPointer + 3 << " and *numpointer + 3 : " << *numPointer + 3 << endl;
	cout << "&number[6] : " << (&numbers[6]) << " where numPointer + 4 = " << numPointer + 4 << " and *numpointer + 4 : " << *numPointer + 4 << endl;
	system("pause>0");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
