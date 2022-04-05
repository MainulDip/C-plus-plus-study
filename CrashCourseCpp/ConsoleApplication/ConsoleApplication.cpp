// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void voidPointerPrinting(void* sth, char type) {
	switch (type)
	{
	case 'i': cout << *(int*)sth << endl; break;
	case 's': cout << *(string*)sth << endl; break;
	default:
		cout << "Type doesn't matching, returning";
		break;
	}
}

int main()
{
	int someInt = 77;
	string someStr = "Hello World";
	voidPointerPrinting(&someInt, 'i');
	voidPointerPrinting(&someStr, 's');
	system("pause>0");
}