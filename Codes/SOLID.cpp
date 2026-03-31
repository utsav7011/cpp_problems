#include <iostream>
using namespace std;

// SOLID PRINCIPALS
/****
 *
 *
 * Maintainability:
 * Readability.
 * Bugs
 *
 *
 * S: Single responsibility principle
 * A class hsould have only one principle.
 * A class shoould have only one reason to change.
 *
 * O: open close principle
 *
 *
 * L: Liskov Substitution princile
 * I: Interface segregation principle
 * D: Dependency Inversion principle
 *
 *
 *
 */

class ShoppingCart
{

private:
  vector<Product *> products;

public:
  ShoppingCart() {}

  void addProducts(Product *p)
  {
    products.push_back(p);
  }

  const vector<Product *> &getProducts()
  {
    return products;
  }

  double calculateTotal()
  {
    double total = 0;
    for (auto product : products)
    {
      total += product->price;
    }
  }

  void printinvoice()
  {
    cout << endl
         << "invoice is::::: " << endl;
    for (auto p : products)
    {
      cout << endl
           << p->name << ":::" << p->price;
    }
    cout << endl
         << "Total::::" << calculateTotal();
  }

  void saveToDB()
  {
    cout << endl
         << "Save teh data to DB" << endl
         << "::::";
  }
};

class Product
{
public:
  double price;
  string name;
  Product(string name, double price)
  {
    this->price = price;
    this->name = name;
  }
};

class ShoppingCartSRP
{
public:
  vector<Product *> products;
  ShoppingCartSRP() {}

  void addProducts(Product *p)
  {
    products.push_back(p);
  }

  double calculateTotal()
  {
    double total = 0;
    for (auto p : products)
    {
      total += p->price;
    }
    return total;
  }
};

class ShoppingCartPrintingSRP
{
private:
  ShoppingCartSRP *cart;

public:
  ShoppingCartPrintingSRP(ShoppingCartSRP *cart)
  {
    this->cart = cart;
  }

  void printBillingSystem()
  {
    cout << endl
         << "Pirnt Billing System" << endl;
    for (auto p : cart->products)
    {
      cout << endl
           << p->name << ":::::" << p->price;
    }
    cout << endl
         << "Total:::::::" << cart->calculateTotal();
  }
};

class ShoppingCartSaveToDB
{
private:
  ShoppingCartSRP *cart;

public:
  ShoppingCartSaveToDB(ShoppingCartSRP *cart)
  {
    this->cart = cart;
  }

  void saveToDB()
  {
    cout << endl
         << "Saving to DB;;;;;;";
  }
};

int main()
{
}