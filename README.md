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