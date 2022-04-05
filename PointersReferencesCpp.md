## Pointers and References For C++
Pointer Vs Reference
```cpp
#include <iostream>
using namespace std;

int main()
{
	int n = 7;
	cout << "n's address is &n = " << &n << " and value is n = " << n << endl;
	int* pointerN = &n;
	cout << "pointerN is : " << pointerN << " and the value/dereferenced of the *pointerN = " << *pointerN << endl;
	*pointerN = 10;
	cout << "After re assaigning to 10 pointerN is : " << pointerN << " and the value/dereferenced of the *pointerN = " << *pointerN << endl;
	cout << "The n value is also changed as n = " << n << endl;

	// other way
	int& refN = n;
	cout << "Now the value of refN = " << refN << endl;

	cout << "\n now create another pointer\n" << endl;

	int* newPN = &refN;
	cout << "Now the newPN = " << newPN << " and *newPN " << *newPN << endl;
	(*newPN)++;
	cout << "\n\nAdding (*newPN)++ newPN = " << newPN << " and *newPN " << *newPN << endl;
	cout << "The n value is also changed as n = " << n << endl;

	// assaigning new value to old pointer
	int anotherVal = 77;
	newPN = &anotherVal;

	cout << "\n\n*newPN = " << *newPN << endl; // *newPN = 77

	// this will not change the n valu as it has separate memory location


	cout << "n = " << n << endl; // n = 11

	cout << "this will not change the n valu as it has separate memory location\n\n" << endl;

	// reassaigning to reference will cange the n's value as both memory location is same;
	refN = anotherVal;

	cout << "New refN = " << refN << endl; // New refN = 77
	cout << "n = " << n << endl; // n = 77

	cout << "reassaigning to reference will cange the n's value as both memory location is same" << endl;

	system("pause>0");
}
```

### void pointer:
Can hold vallue of any data types, but cannot directly dereferences.
> Note: errors/bugs with void pointers are hard to find and debug as most of the time it's a logical bug. And logical bugs are hard to find on programms. like casting wrong type inside the switch case. In those case compiler doesn't throw errors, will throw undefiened bugs.

```cpp
#include <iostream>
using namespace std;

// function receiving void pointer, that will/can be cast ot any type from the function body
void voidPointerPrinting(void* sth, char type) {
	switch (type){
	case 'i': 
		// type casting and dereferencing by *(int*)sth and *((string*)sth), outer parenthesis is optional
		cout << *(int*)sth << endl;
		break;
	case 's': cout << *((string*)sth) << endl; break;
	default:
		cout << "Type isn't matching, returning";
		break;
	}
}

int main()
{
	int someInt = 77;
	string someStr = "Hello World";

	// calling function with int argument
	voidPointerPrinting(&someInt, 'i');

	// string argument
	voidPointerPrinting(&someStr, 's');

	system("pause>0");
}
```

### pointers and arrays

### Return multiple values from a function

### Dynamic arrays - How to create/change

### Multidimensional dynamic arrays

### detect errors and bugs in code

### Memory Leaks in C++

### Function Pointers


### Smart pointers (unique, shared, weak)