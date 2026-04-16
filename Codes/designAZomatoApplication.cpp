#include<iostream>
using namespace std;

// functional rtequirements
// user can search for restaurants based on location
// user can add items to cart
// user can checkout by making payments
// user is notified once the order is placed successfully. 

// non-functional requirements
// each part fo design should be scal;able and modifiable

// restaurants -> menu -> order
// take 2 orders: delivery / pickup -> cart -> payment -> notification service to user
// user | delivery agent
// bottom up approach: first make thjose objects that are small and define relations between them and then make the larger oobjects which the smaller ones can be a part of
// top-down approach: first make the largert objects and then make the smaller objects.

class Restaurant {};

int main () {

}