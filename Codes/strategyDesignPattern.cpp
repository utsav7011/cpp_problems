/**
 * Strategy Design patterns: 
 * 
 */

#include<iostream>
using namespace std;

class Robot {
  public:
  // void talk() {}
  // void walk () {}
  // void fly () {}
  void projection () {}
};


class Talkable {
  public:
  virtual void talk () = 0;
};


class NormalTalk: public Talkable {
  public:
  void talk () override {
    cout<<"Talk::::: normalTalk"<<endl;
  }
};

class nonTalkable: public Talkable {
  public:
  void talk () override {
    cout<<endl<<"Non Talkable"<<endl;
  }
};

class Walkable {
  
  public: 
  virtual void walk () = 0;
};

class IsWalkable: public Walkable {
  public:
  void walk () override {
    cout<<endl<<"Is Walkable"<<endl;
  }
};

class NonWalkable: public Walkable {
  public:
  void walk () override {
    cout<<endl<<"is non walable::::"<<endl;
  }
};

class Flyable {
  public:
  virtual void fly () = 0;
};


class IsFlyabl: public Flyable {
  public:
  void fly () override {
    cout<<endl<<"is flyable"<<endl;
  }
};

class NonFlyable: public Flyable {
  public:
  void fly () override{
    cout<<endl<<"is notflyable"<<endl;
  }
};


int main () {

}