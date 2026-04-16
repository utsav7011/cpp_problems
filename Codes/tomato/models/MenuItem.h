#include<iostream>
using namespace std;



class MenuItem {
  private:
  string code;
  string name;
  int price;

  public:
  MenuItem (const string& code, const string& name, int price) {
    this->code = code;
    this->name = name;
    this->price = price;
  }


  string getName () {
    return name;
  }

  void setName (string name) {
    this->name = name;
  }

  int getPrice () {
    return price;
  }

  void setPrice () {
    this-> price = price;
  }

  string getCode () {
    return code;
  }

};