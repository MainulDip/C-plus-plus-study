// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void getMinMax(int arr[], int* min, int* max) {
	// pointer setter(referencing) and getter(dereferencing) is same
	*min = arr[0]; // or arr
	*max = arr[0];
	//cout << *min;
	for (int i = 0; i < sizeof(+arr) - 1; i++) {
		if (*min > arr[i]) {
			*min = arr[i];
		}
	}

	for (int i = 0; i < sizeof(+arr) - 1; i++) {
		if (*max < arr[i]) {
			*max = arr[i];
		}
	}
}

int main()
{
	int primeNums[7] = { 1,2,3,5,7,11,-77 };
	int min;
	int max;

	// size(arr) isn't working outsize main function body, find out why
	cout << size(primeNums) << endl;

	// return min and max value of an array using only one function and pointers
	getMinMax(primeNums, &min, &max);
	cout << "min : " << min << " and max : " << max << endl;

	system("pause>0");
}