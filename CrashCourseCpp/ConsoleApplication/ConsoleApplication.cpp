// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int primeNums[7] = { 1,2,3,5,7,11,13 };
	cout << primeNums[4] << endl; // 7

	// using pointers
	cout << *(primeNums + 4) << endl; // 7

	// sideof(primeNums) will print the byte size which is 7*4 = 28;
	int lenArr = std::size(primeNums);

	cout << "size(primeNums) : " << lenArr << " && sizeof(primeNums) :" << sizeof(primeNums) << endl;
	// size(primeNums) : 7 && sizeof(primeNums) :28

	// with reference, have to mention array index, and dereference using *
	cout << "&primeNums[1] : " << &primeNums[1] << " && *(&primeNums[1]) : " << *(&primeNums[1]) << endl;
	// &primeNums[1] : 0000004EB936F5AC && *(&primeNums[1]) : 2


	// forcing int size return using unary plus operator, otherwise it will return byte size of the array
	cout << sizeof(+primeNums) - 1 << endl;
	// 7

	// Now Lets find how *(&primeNums + 1) - primeNums : 7 works
	cout << "\n\nNow Lets find how *(&primeNums + 1) - primeNums : 7 works\n\n" << endl;

	// *(&primeNums + 1) returns a pointer and primeNums is the pointer of the first element.
	cout << "\n\n &primeNums : " << &primeNums << " and &primeNums + 1 : " << &primeNums + 1 << " and primeNums : " << primeNums << endl;
	cout << "\n\n *(&primeNums + 1) - primeNums : " << *(&primeNums + 1) - primeNums << endl;

	// &primeNums + 1 >> means next memory address after the full array. and primeNums decays to pointer of the first array element.
	// if we subtract (&primeNums + 1) - primeNums by hex value, we will get the total byte of the array primeNums ( 4 byte x 7 = 28 byte )
	// then we dereference *(&primeNums + 1) to do pointer to pointer calculation, it also convert that to int.
		

	system("pause>0");
}