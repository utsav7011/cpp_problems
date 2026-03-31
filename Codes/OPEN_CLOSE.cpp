/***
 * 
 * 
 * Open Close Principle: A class should eb open for extension but close for modification;
 * 
 * to integrate the new feature, old code should not be touched
 * 
 * 
 * 
 */

#include<iostream>
using namespace std;


class Product {
  private:
  string name;
  double price;
  Product(string name, double price) {
    this->name = name;
    this->price = price;
  }
};
/***
 * 
 * client ||||| interface ||||| class
 * 
 */

// abstract class:
class DBPersistence {
  virtual void save() = 0;
};

class saveToMmongoDB: public DBPersistence {
  void save () {}
};

class SaveToSQL: public DBPersistence {
  void save() {}
};

class SaveToFile: public DBPersistence {
  void save() {}
};

int main () {

}