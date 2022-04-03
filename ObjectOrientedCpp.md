## Object Oriented C++ Mini Map:

### Abastraction: Like Inheritance in Java
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
	myCar.setEngine();

	FlyingCar FCar("Flying Ford", "Gewwn", 33337);
	FCar.getInfo();
	FCar.setEngine();


	system("pause>0");
}
```