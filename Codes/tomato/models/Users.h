#include"Cart.h"
#include<iostream>
using namespace std;

class User {
  private:
  int userId;
  string name;
  string address;
  Cart* cart;

  public:
  User(int userId, string name, string address) {
    this->userId = userId;
    this->name = name;
    this->address = address;
    cart = new Cart();
  }

  ~User () {
    cout<<endl<<"Deleting user";
    delete cart;
  }


  string getName () {
    return this->name;
  }

  void setName (string name) {
    this->name = name;
  } 

  string getAddresss () {
    return this->address;
  }

  void setAddress (string currentAddress) {
    this->address = currentAddress;
  } 
};
