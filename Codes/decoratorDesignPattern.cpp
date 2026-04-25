#include <vector>
#include <iostream>
#include <string>
using namespace std;

/**
 * Decorator design pattern:
 * attaches additional responsibilitties to an objeect dynamically.
 * Decorator provides a flexible alternative to subclassing for extending fdunctionality.
 *
 *
 * Class Exlosion: we have so many classes and with every change a new class is created.
 * decorator is also an object also there is a composition relationship i.e. decorator has an objeect
 * inheritance is used to behave like the object by the decorator.
 * composition is used by the decorator to change/extend the behaviour of the object as expected.
 * Base <-(has - a relation) and (is - a relation )  Decorator
 *
 *
 *
 *
 */

class ICharacter
{
public:
  virtual string getAbilities() = 0;
};

class Mario : public ICharacter
{
public:
  string getAbilities() override
  {
    cout << endl
         << "simple getAbilities called";
    return "Simple Mario";
  }
};

class Decorator : public ICharacter
{
protected:
  ICharacter *character;

public:
  Decorator(ICharacter *character)
  {
    this->character = character;
  }
};

class HeightUp : public Decorator
{
public:
  HeightUp(ICharacter *ch) : Decorator(ch) {}
  string getAbilities()
  {
    return character->getAbilities() + "with heightUp";
  }
};

class GunPower : public Decorator
{
public:
  GunPower(ICharacter *ch) : Decorator(ch) {}
  string getAbilities()
  {
    return character->getAbilities() + "with GunPower";
  }
};

class StarPower : public Decorator
{
public:
  StarPower(ICharacter *ch) : Decorator(ch) {}
  string getAbilities()
  {
    return character->getAbilities() + "with Start power";
  }
};

int main() {
  ICharacter* mario = new Mario();
  cout<<endl<<"Mario abilities"<<mario->getAbilities();

  mario = new HeightUp(mario);
  cout<<endl<<"Mario abilities"<<mario->getAbilities();

  mario = new StarPower(mario);
  cout<<endl<<"Mario abilities"<<mario->getAbilities();

  mario = new GunPower(mario);
  cout<<endl<<"Mario abilities"<<" "<<mario->getAbilities();
}