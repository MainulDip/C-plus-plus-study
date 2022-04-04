// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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