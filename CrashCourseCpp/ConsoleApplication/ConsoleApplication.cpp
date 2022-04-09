// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>
using namespace std;

bool ascendingCompare(int a, int b) { return a < b; }

bool descendingCompare(int a, int b) { return a > b; }

void sorting(vector<int>& numberVector, bool(*compare)(int, int)){

	for (int startIndex = 0; startIndex < numberVector.size(); startIndex++) {
		int bestIndex = startIndex;

		for (int currendIndex = startIndex + 1; currendIndex < numberVector.size(); currendIndex++) {
			if (compare(numberVector[currendIndex], numberVector[bestIndex])) {
				bestIndex = currendIndex;
			}
		}

		swap(numberVector[startIndex], numberVector[bestIndex]);
	}
}

void printVectort(vector<int>& numberVector) {

	for (int i = 0; i < numberVector.size(); i++) {
		cout << numberVector[i] << " ";
	}
}

int main()
{
	vector<int>someNumbers = { 1,2,3,4,5,6,7 };

	//bool(*ascCompare)(int, int) = ascendingCompare;
	//bool(*descCompare)(int, int) = descendingCompare;

	// callback can be set directly without making pointer again

	//sorting(someNumbers, ascCompare);
	sorting(someNumbers, ascendingCompare);
	printVectort(someNumbers);

	cout << "\n\n Printing descending order \n" << endl;

	//sorting(someNumbers, descCompare);
	sorting(someNumbers, descendingCompare);
	printVectort(someNumbers);



	system("pause>0");
}