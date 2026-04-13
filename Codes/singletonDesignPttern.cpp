#include <iostream>
using namespace std;

/**
 * Singleton Design Pattern:
 * Singleton class allows you to create only one instance of a class and ensures thsat throughout the applicatiuon lifeline,
 * only one intnace of a class existsa and if the user wants to create a new object, it returns the previously created object.
 *
 * A constructor of a class is called for the first time when a class is insstantiated and its role is to
 * initialize the values if the variables in class.
 *
 * when we write: A* a = new A()
 * because of new keyword, a space is reserved in heap, then  class A cnstructor is called and if we did not create a constructor a default constructor is cralled.
 * an a pointer is kept inn stack and then we assign the heap memory object to stack pointer.
 * 
 * Practical use case oif Singleton:
 * Logging system
 * Database connection
 * Confiuguration manager
 */

class Singleton
{
private:
  Singleton()
  {
    cout << endl
         << "Singleto scontructor called,v new object created" << endl;
  }
  static Singleton *instance;
  static mutex mtx;

public:
  static Singleton *getInstance()
  {
    if (instance == nullptr)
    {
      lock_guard<mutex> lock(mtx);
      if (instance == nullptr)
      {
        instance = new Singleton();
      }
    }
    return instance;
  }
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::mtx;

int main()
{
  Singleton *a = Singleton::getInstance();
  Singleton *b = Singleton::getInstance();
  cout << endl
       << (a == b);
}