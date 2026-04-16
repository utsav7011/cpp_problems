#include<string>
#include<vector>
#include<iostream>
#include"MenuItem.h"
using namespace std;



class Restaurant {
  private:
  static int nextrestaurantId;
  int restaurantId;
  string name;
  string address;
  vector<MenuItem> menu;

  public:
  Restaurant (const string& name, const string& location ) {
    this->name = name;
    this->location = location;
    this->restaurantId = ++ nextrestaurantId;
  }

  ~Restaurant () {
    cout<<endl<<"destroyiog restaurant.,....."<<endl;
    menu.clear();
  }

  string getName () {
    return this->name;
  }
};
