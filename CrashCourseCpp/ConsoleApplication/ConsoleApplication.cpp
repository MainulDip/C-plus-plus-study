// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Enumaration are created using braces
enum EyeColor {Brown, Blue, Green, Gray, Other};

int main()
{
	bool isSunny = true;
	bool isWeekEnd = true;
	bool haveSomePlan = true;

	if (isSunny && isWeekEnd) {
		cout << "Lets fun" << endl;
		if (haveSomePlan) {
			cout << "Weekend plan" << endl;
		}
	}
	else if (!isSunny && isWeekEnd) {
		cout << "go to work with umbralla" << endl;
	} else {
		cout << "Its raining" << endl;
	}

	// Ternary Operators
	isSunny ? cout << "Ternary: Yeee" << endl : cout << "Ternary: Noo0" << endl;

	// Enum
	EyeColor eyeColor = Brown;

	switch (eyeColor)
	{
	case Brown:
		cout << "Most Common Color" << endl;
		break;
	case Blue: 
		cout << "Colder Region" << endl;
		break;
	case Green:
		cout << "Young mind" << endl;
	default:
		break;
	}

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
