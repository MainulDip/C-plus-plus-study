## Object Oriented C++ Mini Map:

### Abastraction: (Like Inheritance in Java)
```cpp
class AbstractCls {
    // making abstract/virtual function which needs to be implemented to the inherited class
    virtual void abstractMethod()=0;
}

class Employee:AbstractCls {
    void abstractMethod(){
        cout << "Implementing abstract method" << endl;
    }
}
```

### Constructor Manupulating:

```cpp
#include <iostream>
using namespace std;

class Engine {
	virtual void setEngine() = 0;
};

class Car:Engine {
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

	// overriding the abstract/virtual function
	void setEngine() {
		cout << "Setting Engine Through Oberriding Virtual Method" << endl;
	}
};

class FlyingCar :public Car {
private:
	int flyingHeight;
public:
	FlyingCar(string n, string c, double p, int fh) :Car(n, c, p) {
		flyingHeight = fh;
	}

	void getHeight() {
		cout << "The car can fly at " << flyingHeight << " feet height in the sky";
	}
};

class UnderWaterCar : Car {
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
	myCar.setEngine();

	FlyingCar FCar = FlyingCar("Flying Ford", "Gewwn", 33337, 7777);
	FCar.getInfo();
	FCar.setEngine();
	FCar.getHeight();


	system("pause>0");
}
```



### Polymorphic behavour using pointers

> by adding "virtual" 

```cpp
#include <iostream>
using namespace std;

class Engine {
	virtual void setEngine() = 0;
};

class Car:Engine {
	// properties are private by default
private:
	double Price;

protected:
	string Color;
	bool isBroken;

public:
	string Name;

	Car(string n, string c, double p) {
		Name = n;
		Color = c;
		Price = p;
		isBroken = false;
	}

	void getInfo() {
		cout << "myCar Name :" << Name << " and Color : " << Color << " and Price : " << Price << endl;
	}

	// overriding the abstract/virtual function
	void setEngine() {
		cout << "Setting Engine Through Oberriding Virtual Method" << endl;
	}

	// prefix with "virtual" to get polymorphic implementation by pointers
	virtual void movingMedium() {
		cout << "Road Car Moves On the Road" << endl;
	}
};

// to get access of the inherited class add access modifire public

class FlyingCar :public Car {
private:
	int flyingHeight;
public:
	FlyingCar(string n, string c, double p, int fh) :Car(n, c, p) {
		flyingHeight = fh;
	}

	void getHeight() {
		// can access the public/protected properties in the inherited class
		cout << "The "<< Name <<" can fly at " << flyingHeight << " feet height in the sky and the color of the car is : " << Color << endl;
	}

	void movingMedium() {
		cout << "Flying Car Moves On the Sky" << endl;
	}
};

class UnderWaterCar :public Car {
public:
	UnderWaterCar(string n, string c, double p) :Car(n, c, p) {}

	void getBroken() {
		string res = isBroken ? "Broken, so not diveable in the water" : "Not Broken, its moving under water smoothly";
		cout << "The car is " << res << endl;
	}

	void movingMedium() {
		cout << "Under water Car Moves under the water" << endl;
	}
};

int main()
{
	Car myCar("Foed1", "Gewwn", 3333);
	myCar.getInfo();
	myCar.setEngine();

	FlyingCar FCar = FlyingCar("Flying Ford", "Gewwn", 33337, 7777);
	FCar.getInfo();
	FCar.setEngine();
	FCar.getHeight();

	UnderWaterCar UCar = UnderWaterCar("UnderWater Forces", "Gewwn", 7777777);

	// accessing inherited class by base class pointer for polymorphic methods
	Car* mc = &myCar;
	Car* fc = &FCar;
	Car* uc = &UCar;

	mc->movingMedium();
	fc->movingMedium();
	uc->movingMedium();


	system("pause>0");
}
```

### Header files:
Evary source/cpp file compiled seperately and compiled into obj/object file.
After compilation linker will link all those obj files and create the application/exe. If we need to use some code block more than once in other cpp file. Header comes handy to maintain DRY (Don't Repeat Yourself) principle. 
In Header files we declare the signature and in implementaion/cpp file we implement the signature. SameName.h and SameName.cpp is the naming structure. Voila :)