#include<iostream>
using namespace std;

class Car {
  public: 
  virtual void startEngine() = 0;
  virtual void shiftGear(int geat) = 0;
  virtual void accelerate() = 0;
  virtual void brake () = 0;
  virtual void stopEngine() = 0;
  virtual ~Car() {}
};

class SportsCar: public Car {
  public:
  string brand;
  string model;
  bool isEngineOn;
  int currentSpeed;
  int currentGear = 0;

  SportsCar (string brand, string model) {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
  }

  void startEngine () {
    isEngineOn = true;
    cout<<endl<<"Engine of the Sports car started with a roar !"<<endl;
  }

  void shiftGear (int gear) {
    if (!isEngineOn) {
      cout<<endl<<"Engine is not on";
      return;
    }
    currentGear = gear;
    cout<<endl<<"Gear shifted to: "<<gear;
    return;
  }

  void accelerate () {
    if (!isEngineOn) {
      cout<<endl<<"Engine is not on !!!"<<endl;
      return;
    }
    cout<<endl<<currentSpeed;
    currentSpeed+=10;
    cout<<endl<<currentSpeed;
    return;
  }
  void brake () {
    if (!isEngineOn) {
      cout<<endl<<"Engine is not on;;;;;"<<endl;
      return;
    }
    cout<<endl<<"current Speed: "<<currentSpeed;
    currentSpeed-=10;
    cout<<endl<<"current speed: "<<currentSpeed;
    return;
  }

  void stopEngine() {
    if (!isEngineOn) {
      cout<<endl<<"Engine is not yet on!!!"<<endl;
      return;
    }
    currentGear = 0;
    currentSpeed = 0;
    cout<<endl<<"Engine Stopped !!!!";
    return;
  }
};

int main () {
  Car* myCar = new SportsCar("Morris Garages", "WindsorEV");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
}