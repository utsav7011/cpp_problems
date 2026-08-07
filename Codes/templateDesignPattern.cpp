#include<iostream>
using namespace std;

class ITemplateClass{
public:
  virtual ~ITemplateClass() = default;
  virtual void method1() const = 0;
  virtual void method2() const = 0;

  // make templateMethod const so it cannot be overridden by subclasses
  // (it's non-virtual) and can be called on const instances
  void templateMethod() const {
    this->method1();
    this->method2();
  }
};

class Client{
public:
  ITemplateClass* newInstance;
  Client(ITemplateClass* ins) {
    this->newInstance = ins;
  }

  void callingMethod() {
    cout<<endl<<"Inside the calling method in client"<<endl;
    newInstance->templateMethod();
  }
};

class ConcreateTemplateClass: public ITemplateClass{
public:
  void method1() const override { cout << "ConcreateTemplateClass::method1\n"; }
  void method2() const override { cout << "ConcreateTemplateClass::method2\n"; }
};

class ConcreateTemplateClass2: public ITemplateClass{
public:
  void method1() const override { cout << "ConcreateTemplateClass2::method1\n"; }
  void method2() const override { cout << "ConcreateTemplateClass2::method2\n"; }
};

int main() {
  ConcreateTemplateClass* obj1 = new ConcreateTemplateClass();
  Client* newClient = new Client(obj1);
  newClient->callingMethod();
  delete newClient;
  delete obj1;
  return 0;
}