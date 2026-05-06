#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * we need to send a message / request / command from source to reciever
 * so we need to call a method of reciever from source.
 * but in command design pattern we make an object for the command and now thebsource interacts with the command object to get
 * something done.
 * so now the source interacts with the command and command interacts wiht the reciever
 * so command gets the jobn done and returns the object to the source.
 * why we did it? so that we have loose coupling between the source and the reciever.
 * 
 * eg: Smart home automation system:
 * we are building an application, and there are many buttons in the application and on press of the buttons, we are abnle to control the appliances of out home.
 * 
 */

class ICommand;  // Forward declaration

class Remote {
  static const int numButtoms = 100;
  vector<pair<ICommand*, bool>> list;
  public:
  Remote () : list(numButtoms, make_pair(nullptr, false)) {}

  void setCommand(int ind, ICommand* command) {
    if (ind > 0 && ind < numButtoms) {
      if (list[ind].first != nullptr) {
        delete list[ind].first;
      } 
      list[ind] = {command, false};
    }
  }

  void pressButton (int index) {
    if (index > 0 && index < numButtoms  && list[index].first != nullptr) {
      if (list[index].second == false) {
        list[index].first->execute();
      } else {
        list[index].first->undo();
      }
    } else {
      cout<<endl<<"Wrong input priovided, please link a device first / provide the correct input"<<endl;
    }
  }
};

class Light {
  public: 
  void on () {
    cout<<endl<<"Light is on"<<endl;
  }
  void off () {
    cout<<endl<<"Light is foff"<<endl;
  }
};

class Fan {
  public:
  void off () {
    cout<<endl<<"Fan is off"<<endl;
  }
  void on () {
    cout<<endl<<"Fan is Off"<<endl;
  }
};

class ICommand {
  public:
  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual ~ICommand() {}
};

class LightCommand: public ICommand {
  Light* l;
  public:
  LightCommand (Light* l) : l(l) {}
  void execute() override {
    l->on();
  }
  void undo() override {
    l->off();
  }
}; 


class FanCommand: public ICommand {
  Fan* f;
  public:
  FanCommand (Fan* f) : f(f) {}
  void execute() override {
    f->on();
  }
  void undo() override {
    f->off();
  }
};



int main () {
  Remote* newRemote = new Remote();
  Light* light = new Light();
  Fan* fan = new Fan();
  
  newRemote->setCommand(0, new LightCommand(light));
  newRemote->setCommand(1, new FanCommand(fan));
}