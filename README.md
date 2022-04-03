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

Note: Reference address and actual adress is same. Modifying Reference value will also modify the actual valu;
Pointer: Pointer creates separate memory address for its own. So when value is assaigned it store it on its own address. it don't change the actual value like reference does.

```cpp
#include <iostream>
using namespace std;
void celebrateBirthday(int* age);

int main()
{
	int myAge = 26;
	int& someRef = myAge;
	celebrateBirthday(&someRef);
	cout << "Now Age Becomes " << myAge << endl;
	celebrateBirthday(&someRef);
	celebrateBirthday(&myAge);
	// Note: address/reference &myAge and &someRef are same/on-par on each etaration


	system("pause>0");
}

void celebrateBirthday(int* g) {
	// converting/de-referencing memory address (pointer) to pointer value
	(*g)++;
	cout << "Happy " << *g << "th Birthday" << endl;

}

// Happy 27th Birthday
// Now Age Becomes 27
// Happy 28th Birthday
// Happy 29th Birthday
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
### OOP on C++
> Without Constructor:

```cpp
#include <iostream>
using namespace std;

class Car {
	// properties are private by default
public:
	string Name;
	string Color;
	double Price;
};

int main()
{
	Car myCar;
	myCar.Name = "Ford";
	myCar.Color = "Black";
	myCar.Price = 7777;

	cout << "myCar Name :" << myCar.Name << " and Color : " << myCar.Color << " and Price : " << myCar.Price << endl;

	Car mySCar;
	mySCar.Name = "Toyota";
	mySCar.Color = "White";
	mySCar.Price = 4444;

	cout << "mySCar Name :" << mySCar.Name << " and Color : " << mySCar.Color << " and Price : " << mySCar.Price << endl;


	system("pause>0");
}
```
> With Constructor:
```cpp
#include <iostream>
using namespace std;

class Car {
	// properties are private by default
public:
	string Name;
	string Color;
	double Price;

	Car(string n, string c, double p) {
		Name = n;
		Color = c;
		Price = p;
	}

	void getInfo() {
		cout << "myCar Name :" << Name << " and Color : " << Color << " and Price : " << Price << endl;
	}
};

int main()
{
	Car myCar("Foed1", "Gewwn", 3333);
	myCar.getInfo();

	system("pause>0");
}
```

### Encapsulation: private/protected/public
```cpp
#include <iostream>
using namespace std;

class Car {
	// properties are private by default
private:
	string Name;
	string Color;
	double Price;
	bool isBroken;

public:

	Car(string n, string c, double p) {
		Name = n;
		Color = c;
		Price = p;
		isBroken = false;
	}

	void getInfo() {
		cout << "myCar Name :" << Name << " and Color : " << Color << " and Price : " << Price << endl;
	}

	void setBroken() {
		isBroken = true;
		cout << "Setting CarBroken True" << endl;
	}

	void getBroken() {
		string res = isBroken ? "Broken" : "Not Broken";
		cout << "The car is " << res << endl;
	}

	void carRepair() {
		cout << "Repairing The Car Done" << endl;
		isBroken = false;
	}
};

int main()
{
	Car myCar("Foed1", "Gewwn", 3333);
	myCar.getInfo();
	myCar.getBroken();
	myCar.setBroken();
	myCar.getBroken();
	myCar.carRepair();
	myCar.getBroken();

	system("pause>0");
}
```

### Enheritance && Polimorphism:
```cpp
#include <iostream>
using namespace std;

class Car {
	// properties are private by default
private:
	string Name;
	string Color;
	double Price;

protected:
	bool isBroken;

public:

	Car(string n, string c, double p) {
		Name = n;
		Color = c;
		Price = p;
		isBroken = false;
	}

	void getInfo() {
		cout << "myCar Name :" << Name << " and Color : " << Color << " and Price : " << Price << endl;
	}

	void setBroken() {
		isBroken = true;
		cout << "Setting CarBroken True" << endl;
	}

	void getBroken() {
		string res = isBroken ? "Broken, so not driveable on the road" : "Not Broken, running on the road smooth";
		cout << "The car is " << res << endl;
	}

	void carRepair() {
		cout << "Repairing The Car Done" << endl;
		isBroken = false;
	}
};

class FlyingCar :public Car {
public:
	FlyingCar(string n, string c, double p) :Car(n, c, p) {}
};

class UnderWaterCar :public Car {
public:
	UnderWaterCar(string n, string c, double p) :Car(n, c, p) {}

	void getBroken() {
		string res = isBroken ? "Broken, so not diveable in the water" : "Not Broken, its moving under water smoothly";
		cout << "The car is " << res << endl;
	}
};

int main()
{
	Car myCar("Foed1", "Gewwn", 3333);
	myCar.getInfo();
	myCar.getBroken();
	myCar.setBroken();
	myCar.getBroken();
	myCar.carRepair();
	myCar.getBroken();

	FlyingCar FCar("Flying Ford", "Gewwn", 33337);
	FCar.getInfo();

	UnderWaterCar UCar("Under Water Car", "Black", 7676766);
	UCar.getBroken();

	cout << "\n\nModification With Pointers\n\n";

	FlyingCar* pointerFCar = &FCar;
	UnderWaterCar* pointerUCar = &UCar;

	pointerFCar->getBroken();
	pointerUCar->getBroken();

	cout << "Setting Broken By Pointers" << endl;

	pointerFCar->setBroken();
	pointerUCar->setBroken();

	cout << "Getting Broken Info Again" << endl;

	pointerFCar->getBroken();
	pointerUCar->getBroken();


	system("pause>0");
}
```