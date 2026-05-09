/**
 * Strategy Design patterns: 
 * 
 */

#include<iostream>
using namespace std;

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

class Robot {
  public:
  Talkable* talkableRobot;
  Walkable* walkableRobot;
  Flyable* flyableRobot;

  Robot(Talkable* t, Walkable* w, Flyable* f) {
    this->talkableRobot = t;
    this->flyableRobot = f;
    this->walkableRobot = w;
  }
  virtual void projection () = 0;
};

class CompanionRobot: public Robot {
  CompanionRobot (Talkable* t, Walkable* w, Flyable* f): Robot(t, w, f) {
    cout<<endl<<"Companion Robot initialized";
  }

  void projection () override {
    cout<<endl<<"This projection is called from the projkection form comapnnion robot...."<<endl;
  }
};

class WorkerRobot: public Robot {
  WorkerRobot (Talkable* t, Walkable* w, Flyable* f): Robot(t, w, f) {
    cout<<endl<<"Companion Robot initialized";
  }

  void projection () override {
    cout<<endl<<"This projection is called from the projkection form worker robot...."<<endl;
  }
};


int main () {

}