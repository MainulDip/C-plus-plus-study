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
Note: &arr is an address, &arr[0] is a pointer also *(&arr) is a pointer and *(&arr[0]) / *(*(&primeNums)) are dereferencing of pointer which is pointing to the first element of the array.

<details>
<summary>Address Pointer Referencing and Dereferencing</summary>

```cpp
	int primeNums[7] = { 1,2,3,5,7,11,13 };
	
	cout << "\nArray decays to pointer here => primeNums : " << primeNums << endl;

	cout << "\n address of the whole array => &primeNums : " << &primeNums << " && address of the first element => &primeNums[0] : " << &primeNums[0] << endl;
	
	// &primeNums is an address, &primeNums[0] is a pointer also *(&primeNums) is a pointer and *(&primeNums[0]) is dereferencing of a pointer

	bool isEqual = *(&primeNums) == &primeNums[0] ? true : false;

	isEqual ? cout << "*(&primeNums) == &primeNums[0] true" << endl : cout << "*(&primeNums) == &primeNums[0] false" << endl;

	// &primeNums is an address, &primeNums[0] is a pointer also *(&primeNums) is a pointer and *(&primeNums[0]) is dereferencing of a pointer
	cout << "\n *(&primeNums[0]) : " << *(&primeNums[0]) << " and &primeNums[0] : " << &primeNums[0] << endl;

	// converting address to pointer and then dereferencing again to integer ( fist element of the array )
	cout << "\n *(*(&primeNums)) : " << *(*(&primeNums)) << endl;

	cout << "\n\n looping \n\n";

	for (int i = 0; i <= size(primeNums) - 1; i++) {
		cout << primeNums[i] << endl;
	}

	// looping using pointers
	cout << "\n\n looping using pointers \n\n";

	for (int i = 0; i <= size(primeNums) - 1; i++) {
		cout << *(primeNums+i) << endl;
	}
```

</details>

<details>
<summary>More On Pointer arithmetic</summary>

> Pointer arithmetic doesn’t allow following operations-
    Addition of 2 pointers
    Multiplication of a pointer with a constant(Integer)
    Division of a pointer with a constant

> Pointer arithmetic allows following operations-
    Addition of a constant(Integer) to a pointer
    Subtraction of a constant(Integer) from a pointer
    Subtraction of 2 pointers

</details>

> How does *(&arr + 1) - arr give the length in elements of array arr?
  https://stackoverflow.com/questions/61237796/how-does-arr-1-arr-give-the-length-in-elements-of-array-arr


> arr vs &arr : arr is an integer pointer (int*) which points the first element of the array. &arr is an integer array pointer (int*)[5] which points the whole array.


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

	// with reference, have to mention array index, and dereference using *
	cout << "&primeNums[1] : " << &primeNums[1] << " && *(&primeNums[1]) : " << *(&primeNums[1]) << endl;
	// &primeNums[1] : 0000004EB936F5AC && *(&primeNums[1]) : 2


	// forcing int size return using unary plus operator, otherwise it will return byte size of the array
	cout << sizeof(+primeNums) - 1 << endl;
	// 7

	// Now Lets find how *(&primeNums + 1) - primeNums : 7 works
	cout << "\n\nNow Lets find how *(&primeNums + 1) - primeNums : 7 works\n\n" << endl;

	// *(&primeNums + 1) returns a pointer and primeNums is the pointer of the first element.
	cout << "\n\n &primeNums : " << &primeNums << " and &primeNums + 1 : " << &primeNums + 1 << " and primeNums : " << primeNums << endl;
	cout << "\n\n *(&primeNums + 1) - primeNums : " << *(&primeNums + 1) - primeNums << endl;

	// &primeNums + 1 >> means next memory address after the full array. and primeNums decays to pointer of the first array element.
	// if we subtract (&primeNums + 1) - primeNums by hex value, we will get the total byte of the array primeNums ( 4 byte x 7 = 28 byte )
	// then we dereference *(&primeNums + 1) to do pointer to pointer calculation, it also convert that to int.
		

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