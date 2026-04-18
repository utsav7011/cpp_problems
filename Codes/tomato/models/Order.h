#include<iostream>
#include<vector>
#include<string>
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"
#include "Users.h"
using namespace std;


class Order {
  static int nextOrderId;
  int orderId;
  User* user;
  Restaurant* restaurant;
  vector<MenuItem> items;
  PaymentStrategies* paymentStrategy;
  double total;
  string scheduled;

  public:
  Order() {
    user = nullptr;
    restaurant = nullptr;
    paymentStrategy = nullptr;
    total = 0.0;
    scheduled = "";
    orderId = ++nextOrderId;
  }

  virtual ~Order () {
    delete paymentStrategy;
  }
  
  virtual string getType() const = 0;

  bool processPayment () {
    if (paymentStrategy) {
      paymentStrategy->pay(total);
      return true;
    } else {
      cout<<endl<<"please choose a payment model first"<<endl;
      return false;
    }
  }

  int getOrderId () {
    return orderId;
  }


  void setUser( User* u) {
    this->user = u;
  }

  User* getUser () {
    return this->user;
  }

  void setRestaurant(Restaurant* r) {
    this->restaurant = r;
  }

  Restaurant* getRestaurant() {
    return this->restaurant;
  }

  void setItems (const vector<MenuItem>& items) {
    this->items = items;
    total = 0;
    for (auto &item: items) {
      total += item.getPrice();
    }
  }

  const vector<MenuItem>& getItems() const {
    return items;
  } 

  void setPaymentStrategy (PaymentStrategies* p) {
    this->paymentStrategy = p;
  } 


};