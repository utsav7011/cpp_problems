#include <iostream>
using namespace std;
/**
 *
 * Factory Design pattern:
 * we define a new class whose task is to get the oject from the factory class as the clientr need not know how an objest is created....
 * we need to think how can we decouple the client form the business logic, client only says to factory to get the object, and the factory gefts it thge object.
 *
 *
 * We havce 3 types of factory:
 * - Simple factory: a factory class that decides which concrete class to instantiate;
 *
 * - factory method: we introduce a layer of abstraction at the facvtory level as well apart from introducing the abstraction at the object level. Now we can have differnet types of factories as well apart form having the differnet categories of same entity
 * defines an interface for creating object but allows subclass to decide which class to instantiate
 *  
 * - abstract factory method: provides an interfacre for creating families of related objects without specifying their concrete classes.
 *
 *
 *
 *
 */

// Simple factory:
class Burger
{
public:
  virtual void prepare() = 0;
};

class BasicBurger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "prepare the basic burger" << endl;
  }
};
class StandaerdBburger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "prepare the standard burger" << endl;
  }
};
class PremiumBurger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "prepare the premium burger" << endl;
  }
};

class BasicWheatBurger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "Prepare the basic wheat burger" << endl;
  }
};

class StandardWheatBurger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "Prepare the standard whet burger" << endl;
  }
};

class PremiumWheatBurger : public Burger
{
public:
  void prepare() override
  {
    cout << endl
         << "prepare the premium wheat burger" << endl;
  }
};

class BurgerFactory
{
  Burger *b;

public:
  virtual Burger *createBurger(string burgerType) = 0;
};

class SinghBurgerFactory : public BurgerFactory
{
  Burger *b;

public:
  Burger *createBurger(string burgerType) override
  {
    if (burgerType == "simple")
    {
      cout << endl
           << "SImple burger" << endl;
      b = new BasicBurger();
    }
    else if (burgerType == "standard")
    {
      cout << endl
           << "Standard burger" << endl;
      b = new StandaerdBburger();
    }
    else if (burgerType == "premium")
    {
      cout << endl
           << "Premium Burger" << endl;
      b = new PremiumBurger();
    }
    return b;
  }
};
class KingBurgerFactory : public BurgerFactory
{
  Burger *b;

public:
  Burger *createBurger(string burgerType) override
  {
    if (burgerType == "simpleWheat")
    {
      cout << endl
           << "SImple wheat burger" << endl;
      b = new BasicWheatBurger();
    }
    else if (burgerType == "standardWheat")
    {
      cout << endl
           << "Standard wheat burger" << endl;
      b = new StandardWheatBurger();
    }
    else if (burgerType == "premiumWheat")
    {
      cout << endl
           << "Premium wheat Burger" << endl;
      b = new PremiumWheatBurger();
    }
    return b;
  }
};

int main()
{
  string type = "standard";
  BurgerFactory *burgerFactory = new SinghBurgerFactory();
  Burger *burger = burgerFactory->createBurger(type);
  burger->prepare();
}