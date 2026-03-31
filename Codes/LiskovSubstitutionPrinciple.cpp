/**
 *
 * subclasses should be substitutable for threit base classes.
 *
 * A base class
 * B sub-class
 *
 * say client which is expecting the base class referrence and we padss the subclass referrence then there should be no breaking changes.
 * Subclass should be simiarly substitutable and should be able to take place of the base class
 *
 * when can we overwrite the parent class with child class: 
 * 
 * Broader class also called as Parent class
 * narrow Class: Child Class
 * 
 * Signature Rule: during function override, the argumets passed to the functions signature shiould be either the same type or should be of the broader class 
 * Property Rule: 
 * Method Rule: 
 *
 */

#include <iostream>
using namespace std;
class NonWithdrawableAccount
{
  virtual void deposit(double amount) = 0;
};
class WithdrawableAccount
{
  virtual void withdraw(double amount) = 0;
};
class FixedDeposit : public NonWithdrawableAccount
{
private:
  double balance;

public:
  FixedDeposit()
  {
    balance = 0;
  }
  void deposit(double amount)
  {
    balance += amount;
    cout << endl
         << "bhalance is :::::" << balance;
  }
};
class SavingsAccount : public WithdrawableAccount
{
private:
  double balance;

public:
  SavingsAccount()
  {
    balance = 0;
  }
  void deposit(double amount)
  {
    balance += amount;
    cout << endl
         << "Deposited the amopount::::" << balance;
  }

  void withdrawl(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;
    }
    else
    {
      cout << endl
           << "Balance is too looo !!!!!" << endl;
    }
  }
};
class CurrentAccount : public WithdrawableAccount
{
private:
  double balance;

public:
  CurrentAccount()
  {
    balance = 0;
  }
  void deposit(double amount)
  {
    balance += amount;
    cout << endl
         << "Deposited the amopount::::" << balance;
  }

  void withdrawl(double amount)
  {
    if (amount <= balance)
    {
      balance -= amount;
    }
    else
    {
      cout << endl
           << "Balance is too looo !!!!!" << endl;
    }
  }
};


// Signature Rule: during function override, the argumets passed to the functions signature shiould be either the same type or should be of the broader class
// thisis the methjod argument rule in signature rule: 

class Parent {
  public:
  virtual void print (string message) {
    cout<<endl<<"The message is: "<<endl<<message;
    return;
  }
};

class Child: public Parent {
  public:
  void print  (string message) override {
    cout<<endl<<"Child::::"<<message;
  }
};

class Client {
  private:
  Parent *p;
  public:
  Client (Parent* p) {
    this->p = p;
  }
  void printMessage() {
    p->print("hello");
  }
};

// Return type rule: 
/**
 * Animal<- Dog Dog is a animal;
 * when we override a method of parent class then in return type we can either put the same return type as that in base class or 
 * we can put the return type of the narrow type but we cannot put the broader type of the class defined in parent class. 
 * 
 * Co Variance: in return type we can either specify the same class or the narrow class of the already specified class in overridden function
 * 
 * 
 */

/***
 * 
 * Exception Rule: if the function in parent clas tha tis overrriden in child class throws an exception let say a runtime exception, 
 * then overridden fuynction either throws a narrow or same exception but not the exception that belongs to the broader class of the exception. 
 * parent <- child: child is a parent::::: 
 * 
 * Hierarchy of exceptions: 
 * Logical error:
 * - out of range exception
 * runtime error: 
 * 
 */

/*

std:: logic_error:
- incvlidArguement
- domainError
- lengthError
- outOfRange

std::runtimeError:
- rangeError
- overflowError
- udnerflowError
*/

/**
 * 
 * Property Rules: 
 * Class invariant: 
 * history Contraint: 
 * 
 */


 /**
  * Class Invariant:
  * any  fact or rule tha tis true for a class:
  * the rule states that we have a class and we have an invariant r1 so the child class has the reponsibility to follow that invariant and do not break the invarinat.
  * Child class needs to follow the invariant, it can strengthen the invariant but should not make the invariant weak.
  * 
  * just add a comment on top of the parent class about the invariant, nothing else so that the future developer know what invariant needs to be followed in future codes. 
  */


/**
 * history Constraint: 
 * history should nevenr change: the state that parent class maintains should be maintained in child clas as well.
 * 
 */

//  withdrawl should always be allowed.
 class Account {

 };

//  same as we discussed in Liskov Substitution principlpe, this fixedf deposit class brekas the history contraint rule, as the base class 
// mentions that the withdrawl should always be allowed but the fixedDeposit class does not allow the withdrawl, so we can say that it does not
// pass the criteria for the child class of the account. 
class FixedDepositAccount: public Account {};


// Methid Rule: 
/**
 * 
 * precondition: is a condition that must be followed before running a method:
 * as per thius rule, the child class overrriding the method with a pre condition can make 
 * the preconditions weak during the overriding but cannot strengthen the precondition
 * 
 * 
 * 
 * 
 * post condition: condition that must be satisfied after the function is run.
 * 
 * 
 * 
 * 
 * 
 */


//  precondition: numn >= 0 || num < 5
 void func(int num) {

 }


 class Animal {

 };
 class Dog {};



int main()
{
}