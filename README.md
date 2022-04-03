## C++ Study Overview:
This is a personalized docs regarding C++. It could be helpful when youre working with several programming languages. And also it will be a mini map in conjunction with other online documentations. Happy Coding.

### Most Basic Language Tour:

```cpp
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    cout << "This is the first c++ code by me, haha :)";
    system("pause>0");
}
```
### Data types:
```cpp
#include <iostream>
using namespace std;

int main()
{
    int age = 77;
    cout << age;
    const int unmodValue = 74;
    float weight = 66.6;
    double longNum = 7777777.7777777;
    char singleChar = 'g';
    string userName = "some user name";
    bool isTodaySunny = true;

    // Array, cannot change the allocated slot, 
    //if initial allocation size is empty, initial allocation size will is set, then cannot add more to next
    string initialEmpty[] = { "a", "b", "c", "d" };
    
    // slot can be allocated first and can be add later on the empty slots.
    string colors[10] = { "blue", "Green", "Yellow" };
    cout << colors[0];
 //   cin >> colors[0]; // take input in the terminal and store the value to the colors[0] slot of the array
    cout << colors[0]; // prints whatever the input is
    colors[9] = "Pink";
    colors[10] = "someval"; // will throw error as the allocation limit is set to 10 (0 indexing)
    cout << colors[9];

    system("pause>0");
}
```
### Conditionals
```cpp
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
```

### Looping: while, do while

```cpp
cout << "While loop\n" << endl;

int counter = 0;
int second_counter = 0;
string animals[7] = { "dog", "cat", "cow", "goat" };

while (counter < 7) {
    cout << counter << endl;
    counter++;
}

cout << "\nDoWhile loop\n" << endl;

do {
    cout << second_counter << endl;
    second_counter++;
} while (second_counter < 7);

for (int i = 0; i < 4; i++) {
    cout << animals[i] << endl;
}
```

### Functions:
> write function signature (declaration) first, function body after the main block;

```cpp
#include <iostream>
using namespace std;

float sum(float a, float b);
// function with default argument value
void nothingReturn(string str = "Again");

int main()
{
	cout << sum(1, 2) << endl;
	nothingReturn("World");
	nothingReturn();

	system("pause>0");
}

float sum(float a, float b) {
	return a + b;
}

void nothingReturn(string str) {
	cout << "Hello " << str << endl;
}
```

### Pointers: Ram address of variable, objects, value etc.
> pointer with function
```cpp
void celebrateBirthday(int* age);

int main()
{
	int myAge = 26;
	celebrateBirthday(&myAge);
	cout << "Now Age Becomes " << myAge << endl;


	system("pause>0");
}

void celebrateBirthday(int* g) {
	(*g)++;
	cout << "Happy " << *g << "th Birthday" << endl;
	
}
```

> Pointers with arrays:

```cpp
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

// numbers: 000000B715B2F8B8
// & numbers : 000000B715B2F8B8
// numbers[6] : 7
// & numbers[6] : 000000B715B2F8D0
// numPointer Pointing to 000000B715B2F8B8, Value : *numPointer 1
// numPointer++ Pointing to 000000B715B2F8BC, Value : *numPointer 2
// numPointer++ Pointing to 000000B715B2F8C0, Value : *numPointer 3
// & number[6] : 000000B715B2F8D0 where numPointer + 3 = 000000B715B2F8CC and *numpointer + 3 : 6
// & number[6] : 000000B715B2F8D0 where numPointer + 4 = 000000B715B2F8D0 and *numpointer + 4 : 7
```