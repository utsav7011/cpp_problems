#include<iostream>
#include "PaymentStrategy.h"
using namespace std;


class UPIPayments: public PaymentStrategies {
  void pay() {
    cout<<endl<<"payment made by UPI payments"<<endl;
  }
};