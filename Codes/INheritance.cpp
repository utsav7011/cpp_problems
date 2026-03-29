#include <iostream>
using namespace std;

class Car
{
  // model, brand
  // startEngine, StopEngine
protected:
  string brand, model;
  bool isEngineOn;
  int currentSpeed;

public:
  Car(string b, string m)
  {
    this->brand = b;
    this->model = m;
    this->isEngineOn = false;
    currentSpeed = 0;
  }

  void startEngine()
  {
    if (isEngineOn)
    {
      cout << endl
           << "Engine is already on";
      return;
    }
    isEngineOn = true;
  }

  void stopEngine()
  {
    if (!isEngineOn)
    {
      cout << endl
           << "Engine is already off";
      return;
    }
    isEngineOn = false;
  }

  virtual void accelerate () = 0;

  void brake()
  {
    if (!isEngineOn)
    {
      cout << endl
           << "Engine is already off";
      return;
    }
    currentSpeed -= 10;
  }
};

class ManualCar : private Car
{
  // define those cahracters that are specific to this manualCar
public:
  int gear;
  ManualCar(string model, string brand): Car (model, brand ) {
    gear = 0;
  }

  void accelerate (int rate) {
    this->currentSpeed += rate;
  }
  void shiftGear(int nextgear)
  {
    nextgear += 1;
  }
};

class ElectricCar : private Car
{
  // define those specific behaviour and attributes that are specific to this electricCar
  void changeBattery () {
    cout<<endl<<"Need to change battery....."<<endl;
  }
};


// Polymorphism:

// are of 2 types;
// dynamic Polymorphism: also called Method overriding
// Static polymorphism: also called as method overloading

// Sttaic Polymorphism: 
bool isDanger () {
  return false;
}


class Animal {

};

class Duck: private Animal {

};

class Human: private Animal {

};

class Tiger: private Animal {

};

int main()
{
}