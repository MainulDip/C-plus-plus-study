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

	//int lenArrP = *(&primeNums + 1) - primeNums;
	cout << "*(&primeNums + 1) : "<< *(&primeNums + 1) << " && *(&primeNums + 1) - primeNums : " << *(&primeNums + 1) - primeNums << " && *(&primeNums - 1) - primeNums : " << *(&primeNums - 1) - primeNums << endl;
	// *(&primeNums + 1) : 000000966CB6F5A4 && *(&primeNums + 1) - primeNums : 7 && *(&primeNums - 1) - primeNums : -7

	cout << "primeNums[1] : " << primeNums[1] << " && &primeNums[1] : " << &primeNums[1] << " && *(&primeNums[1]) : " << *(&primeNums[1]) << endl;
	// primeNums[1] : 2 && &primeNums[1] : 000000A98B8FF9DC && *(&primeNums[1]) : 2

	cout << "&primeNums : " << &primeNums << " && *(&primeNums) : " << *(&primeNums) << " && *(&primeNums[1] : " << *(&primeNums[1]) << " && *primeNums : " << *primeNums << " && *primeNums + 1 : "<< *primeNums + 1 << endl;
	// &primeNums : 000000E6324FF4C8 && *(&primeNums) : 000000E6324FF4C8 && *(&primeNums[1] : 2 && *primeNums : 1 && *primeNums + 1 : 2

	cout << " &primeNums + 1 : " << &primeNums + 1 << " && primeNums + 1 : " << primeNums + 1 << " && *primeNums + 1 : " << *primeNums + 1 << " && *(&primeNums + 1) : " << *(&primeNums +1) << " && *(&primeNums) + 1 : " << *(&primeNums) + 1 << endl;
	// &primeNums + 1 : 00000098DACFFA94 && primeNums + 1 : 00000098DACFFA7C && *primeNums + 1 : 2 && *(&primeNums + 1) : 00000098DACFFA94 && *(&primeNums) + 1 : 00000098DACFFA7C
	
	// with reference, have to mention array index, and dereference using *
	cout << "&primeNums[1] : " << &primeNums[1] << " && *(&primeNums[1]) : " << *(&primeNums[1]) << endl;
	// &primeNums[1] : 0000004EB936F5AC && *(&primeNums[1]) : 2


	// forcing return using unary plus operator
	cout << sizeof(+primeNums) - 1 << endl;
	// 7

	// Now Lets find how *(&primeNums + 1) - primeNums : 7 works
	cout << "\n\nNow Lets find how *(&primeNums + 1) - primeNums : 7 works\n\n" << endl;

	// this is reducing (minusing) address from address, may be it is using unary minus operator like unary plus;
	cout << "primeNums : " << primeNums << " && *(&primeNums + 1): " << *(&primeNums + 1) << endl;
		

	system("pause>0");
}