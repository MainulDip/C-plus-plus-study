// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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