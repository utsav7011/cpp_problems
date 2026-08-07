#include<iostream>
using namespace std;

class IComponent{
  public:
  virtual void methodA() = 0;
};

class ConcreteComponent: public IComponent {
  public:
  void methodA () override {
    cout<<endl<<"Method A overridden"<<endl;
  }
};


class DecoratorClass: public IComponent {
  public:
  IComponent* comp;
  void methodA() {}
};


class ConcreteDecoratorClass: public DecoratorClass {
  public:
  ConcreteDecoratorClass(IComponent* c) {
    this->comp = c;
  }
  void methodA() override{
    cout<<endl<<"MethodA is overrridden again"<<endl;
  }
};

int main () {
  ConcreteComponent* comcComponent = new ConcreteComponent();
  ConcreteDecoratorClass* concDecClass = new ConcreteDecoratorClass(comcComponent);
}