// /*****
//  * 
//  * 
//  * inheritance: is - a relationship
//  * Composition: Has-a relationship. represented with a close diamond with diamond cleosewd to parent class | represnets tose parent child replations in which the child class cannot exist without the parent class./
//  * 
//  * Agregation: represented with a hollow diamond | 
//  * 
//  * 
//  * 
//  * 
//  */

#include<iostream>
using namespace std;


// class Car {
//   private:
//   string model, brand;
//   public:
//   Car (string model, string brand) {
//     this->model = model;
//     this-> brand = brand;
//   }
// };

// class ManualCar {
//   Car *car;
//   ManualCar (string model, string brand) {
//     car = new Car(model, brand);
//   } 

//   ~ManualCar () {
//     delete car;
//   }
// };

// class ElectricCar {
//   Car *car;
//   ElectricCar (string brand, string model) {
//     car = new Car(brand, model);
//   }
// };

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


class A {
  public:
  void method1() {
    cout<<endl<<"methoid 1 called";
  }
};

class B {
  public:
  A *a;
  B() {
    a = new A();
  }
  void method2 () {
    cout<<endl<<"tie is method 2"<<endl;
  }
};

int main () {
  B *b = new B();
  b-> method2();
  b->a->method1();
  Car* myCar = new SportsCar("Morris Garages", "WindsorEV");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
}
