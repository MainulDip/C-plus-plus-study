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
> pointer setter and getter is same

```cpp
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
```
### Dynamic arrays - How to create/change
> compare linked_list with array

> creating and deleting dynamic array allocation : int* arr = new int[size]; ==> delete[]arr; ==> arr = NULL;

```cpp
int size;
cout << "Size : ";
cin >> size;

// dynamic allocation
int* arr = new int[size];

cout << "Create the array " << endl;

for (int i = 0; i < size; i++) {
	cout << "Array[" << i << "] : ";
	cin >> arr[i];
}

// show the user created array

for (int i = 0; i < size; i++) {
	//cout << arr[i] << "\t";
	cout << *(arr + i) << "\t";
}

// deallocate
delete[]arr;
arr = NULL;
```

### Multidimensional dynamic arrays
> **table => pointer of pointer.

														0000aa -> { 1, 2, 3, 4}
**table-> 0000xx	0000xx {0000aa, 0000bb, 0000cc}		0000bb -> { 2, 3, 4, 1}
														0000cc -> { 1, 2, 3, 4}


```cpp
	int rows, cols;
	cout << "Rows , Cols" << endl;
	cin >> rows >> cols;

	// create the **table and 1st array / linking pointer table array
	int** table = new int* [rows];

	// create 2nd dynamic array by looping
	for (int i = 0; i < rows; i++) {
		// create the array with the specified values
		table[i] = new int[cols];
	}

	// inter/set value of a col/array slot
	cout << "Enter in the table[1][2] slot : ";
	cin >> table[1][2];

	cout << "You Inserted : " << table[1][2] << endl;

	// delete the last array first 
	for (int i = 0; i < rows; i++) {
		delete[] table[i];
	}

	// delete the linking array
	delete[] table;
	table = NULL;
```

### detect errors and bugs in code, Mamory Leack
> Static file analyzer, PVS Studio

> Prevent mamory leaking by deleting and unallocatin dynamic memory

### Memory Leaks in C++

### Function Pointers
> like variable pointer. Function pointer hold function's address and can be called using the pointer. Usually used as callback function.

```cpp
void someFun() {
	cout << "Calling From Function Pointer" << endl;
}

int main()
{
	cout << "Printing Function Address => someFun : " << someFun << endl;
	
	// init function pointer using function's address
	void(*funPointer)() = someFun;
	funPointer(); // Calling From Function Pointer

	system("pause>0");
}
```

> Function Pointer Callback:

```cpp
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
```
### Smart pointers (unique, shared, weak)
> Smart pointers are container or wrapper of the raw pointer. It deallocate/delete mamory automatically when lifecyle ends, hence prevent memory leak. 

_# Unique smart pointer: unique_ptr<int> name = make_unique<int>(77);

```cpp
#include <iostream>
#include<memory>
using namespace std;

int main()
{
	unique_ptr<int> someUniquePtr = make_unique<int>(77);
	cout << "someUniquePtr address is : " << someUniquePtr << " && *someUniquePtr value is : " << *someUniquePtr << endl;

	// unique pointer cannot be shared, but ownership can be transfered
	// unique_ptr<int> anotherUniquiePtr = someUniquePtr; // this will throw error as it cannot be shared
	unique_ptr<int> anotherUniquiePtr = move(someUniquePtr); // moving ownership, also it sets previous unique pointer to null
	
	cout << "*anotherUniquiePtr : " << anotherUniquiePtr << " && someUniquePtr : " << someUniquePtr << endl;

	// result
	// someUniquePtr address is : 00000177D14CF630 && *someUniquePtr value is : 77
	// * anotherUniquiePtr : 00000177D14CF630 && someUniquePtr : 0000000000000000
	
	// will throw error as the dereference value is null;
	// cout << *someUniquePtr : " << *someUniquePtr << endl;

	system("pause>0");
}
```

### testing constructor and destructor behavour of the unique smart pointer using scopping;

```cpp
#include <iostream>
#include<memory>
using namespace std;

class MyClass {
public:
	MyClass() {
		cout << "Constructor invoked" << endl;
	}

	// destructor using "~" tilde, in math it means "approximately" but in logic it means "not", so not-constructor in this case or opposite-of-constructor. voila
	~MyClass() {
		cout << "Destructor invoked, Object Deleted" << endl;
	}
};

int main()
{
	// creating scope using braces
	{
		unique_ptr<MyClass> clsPointer = make_unique<MyClass>();
	}

	cout << "Scope Ends" << endl;

	// result
	// Constructor invoked
	// Destructor invoked, Object Deleted
	// Scope Ends
	
	system("pause>0");
}
```


### Shared Smart Pointer : Unlike Unique, it can be shared between owenrs. or one raw pointer can be shared between multiple owenrs.

```cpp
#include <iostream>
#include<memory>
using namespace std;

class MyClass {
public:
	MyClass() {
		cout << "Constructor invoked" << endl;
	}

	// destructor
	~MyClass() {
		cout << "Destructor invoked, Object Deleted" << endl;
	}
};

int main()
{

	// initializing shared pointer
	shared_ptr<MyClass> clsSharedPtr = make_shared<MyClass>();

	// shared pointer can keep track of other owenrs.
	cout << "Shared count : " << clsSharedPtr.use_count() << endl; // 1

	// second shared pointer
	shared_ptr<MyClass> anotherSharedPtr = clsSharedPtr;

	cout << "Shared count : " << clsSharedPtr.use_count() << endl; // 2
	cout << "Shared count : " << anotherSharedPtr.use_count() << endl; // 2



	{
		// shared_ptr<MyClass> clsSharedPtr = make_shared<MyClass>();

		// cout << "Shared count : " << clsSharedPtr.use_count() << endl; // 1

		// shared_ptr<MyClass> anotherSharedPtr = clsSharedPtr;

		// cout << "Shared count : " << clsSharedPtr.use_count() << endl; // 2
		// cout << "Shared count : " << anotherSharedPtr.use_count() << endl; // 2
	}

	// the memory will be deallocated after all the owner's scope.
	// also note, sharing pointer will not call constructor/destructor again, so it is keeping the singleton pattern
	
	system("pause>0");
}
```

### Weak Smart Pointer : weak pointer will not keep the object alive if nothing needs it. It will not wait for the scope. But shared pointer will keep the object alive untile owners are destroyed by scope.

```cpp
#include <iostream>
#include<memory>
using namespace std;

class MyClass {
public:
	MyClass() {
		cout << "Constructor invoked" << endl;
	}

	// destructor
	~MyClass() {
		cout << "Destructor invoked, Object Deleted" << endl;
	}
};

int main()
{
	// init weak pointer
	weak_ptr<MyClass> wptr1;

	{
		// init shared pointer
		shared_ptr<MyClass> sptr1 = make_shared<MyClass>();
		wptr1 = sptr1;

		cout << "weak pointer tracking " << wptr1.use_count() << endl;
	}

	cout << "weak pointer tracking " << wptr1.use_count() << endl;

	
	system("pause>0");
}
```

### Tree Data Structure:
```cpp
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) {
	// step 1 => create new Node (pointer);
	// step 2 => set data
	// step 3 => takecare of child nodes, initially be null
	// step 4 => return the reference

	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = nullptr; // eatch itaration we're initializing left and right child for every new node
	return newNode;
}

int main()
{
	Node* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);

	//			   root node
	//				   v 
	//				  (1)
	//			 |-----------|
	//			(2)			(3)
	//		  |-----|	 |-------|
	//		 (4)    N	 N		 N

	// N = nullptr


	system("pause>0");
}
```

## Further Note:
1. Need clear info of the weak pointer and use casees.
2. visual studio dibugging c++, locate the debug menu and explore. usually f10 step over and f11 step into. Use f10 f11 combination for line by line. start with breakpoint marking.
3. advanced functions, template, closour and lambda