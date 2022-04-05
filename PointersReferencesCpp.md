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
> Pointer arithmetic doesn’t allow following operations-
    Addition of 2 pointers
    Multiplication of a pointer with a constant(Integer)
    Division of a pointer with a constant

> Pointer arithmetic allows following operations-
    Addition of a constant(Integer) to a pointer
    Subtraction of a constant(Integer) from a pointer
    Subtraction of 2 pointers

> How does *(&arr + 1) - arr give the length in elements of array arr?
  https://stackoverflow.com/questions/61237796/how-does-arr-1-arr-give-the-length-in-elements-of-array-arr



```cpp
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
```

### Return multiple values from a function

### Dynamic arrays - How to create/change

### Multidimensional dynamic arrays

### detect errors and bugs in code

### Memory Leaks in C++

### Function Pointers


### Smart pointers (unique, shared, weak)