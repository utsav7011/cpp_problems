#ifndef MENUITEM_H
#define MENUITEM_H

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "../models/Restaurant.h"
using namespace std;


class RestaurantManager {
  private:
  vector<Restaurant*> restaurants;
  static RestaurantManager* instance;
  RestaurantManager () {}
  public:

  static RestaurantManager* getInstance() {
    if (!instance) {
      instance = new RestaurantManager ();
    }
    return instance;
  }

  void addRestaurant (Restaurant* newRestaurant) {
    restaurants.push_back(newRestaurant);
  }


  vector<Restaurant*> getRestaurantsByLocation (string location) {
    vector<Restaurant*> filteredRestaurants;
    transform(location.begin(), location.end(), location.begin(), ::tolower);

    for (auto r: restaurants) {
      string restaurantLocation = r->getLocation();
      transform(restaurantLocation.begin(), restaurantLocation.end(), restaurantLocation.begin(), ::tolower);
      if (restaurantLocation == location) {
        filteredRestaurants.push_back(r);
      }
    }
    return filteredRestaurants;
  }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif
