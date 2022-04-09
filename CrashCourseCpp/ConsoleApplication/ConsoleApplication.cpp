// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void someFun() {
	cout << "Calling From Function Pointer" << endl;
}

int main()
{
	cout << "Printing Function Address => someFun : " << someFun << endl;
	
	// init function pointer using function's address
	void(*funPointer)() = someFun;
	funPointer(); // Calling From Function Pointer

	system("pause>0");
}