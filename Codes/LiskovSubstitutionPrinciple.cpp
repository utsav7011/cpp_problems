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
 * Signature Rule: 
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

int main()
{
}