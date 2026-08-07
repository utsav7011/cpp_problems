#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class IObserver {
  public:
  virtual void update() = 0;
};

class IObservable {
  public:
  vector<IObserver*> list;
  virtual void notify() = 0;
};

class ConcreteObservable: public IObservable {
  public:
  void add(IObserver* newObserver) {
    list.push_back(newObserver);
  }

  void removeObserver(IObserver* observerToRemove) {
    auto it = find(list.begin(), list.end(), observerToRemove);
    if (it == list.end()) {
      cout<<endl<<"Observer not found::::"<<endl;
      return;
    }
    list.erase(it);
    cout<<endl<<"Removed the observer"<<endl;
    return;
  }

  string getLatestValue() {
    return "latest value";
  }
  void notify() override{
    for (auto observer:list) {
      observer->update();
    }
  }
};

class ConcreteObserver: public IObserver {
  ConcreteObservable* conObservable;
  public:
  ConcreteObserver(ConcreteObservable* observable) : conObservable(observable) {}
  
  void update() override{
    cout<<endl<<conObservable->getLatestValue();
  }
};

int main () {
  ConcreteObservable* observable = new ConcreteObservable();
  ConcreteObserver* observer1 = new ConcreteObserver(observable);
  ConcreteObserver* observer2 = new ConcreteObserver(observable);
  observable->add(observer1);
  observable->add(observer2);

  observable->notify();
}