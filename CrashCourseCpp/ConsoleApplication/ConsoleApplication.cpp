// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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