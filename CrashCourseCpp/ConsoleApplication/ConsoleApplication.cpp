// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int primeNums[7] = { 1,2,3,5,7,11,13 };
	
	cout << "\nArray decays to pointer here => primeNums : " << primeNums << endl;

	cout << "\n address of the whole array => &primeNums : " << &primeNums << " && address of the first element => &primeNums[0] : " << &primeNums[0] << endl;
	
	// &primeNums is an address, &primeNums[0] is a pointer also *(&primeNums) is a pointer and *(&primeNums[0]) is dereferencing of a pointer

	bool isEqual = *(&primeNums) == &primeNums[0] ? true : false;

	isEqual ? cout << "*(&primeNums) == &primeNums[0] true" << endl : cout << "*(&primeNums) == &primeNums[0] false" << endl;

	// &primeNums is an address, &primeNums[0] is a pointer also *(&primeNums) is a pointer and *(&primeNums[0]) is dereferencing of a pointer
	cout << "\n *(&primeNums[0]) : " << *(&primeNums[0]) << " and &primeNums[0] : " << &primeNums[0] << endl;

	// converting address to pointer and then dereferencing again to integer ( fist element of the array )
	cout << "\n *(*(&primeNums)) : " << *(*(&primeNums)) << endl;

	cout << "\n\n looping \n\n";

	for (int i = 0; i <= size(primeNums) - 1; i++) {
		cout << primeNums[i] << endl;
	}

	// looping using pointers
	cout << "\n\n looping using pointers \n\n";

	for (int i = 0; i <= size(primeNums) - 1; i++) {
		cout << *(primeNums+i) << endl;
	}

	system("pause>0");
}