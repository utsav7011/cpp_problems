#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/***
 *
 *
 * requirementws:
 * plug and play model: with minimal code changes, integrate the notification model to the existing application
 * highly extendable
 * notification should be dynamically extendable (headers, footers)
 * store all notifications
 * log the notifications
 *  we use the oobservabe design pattern, Strategy Design Pattern and Decorator design pattern
 */

class INotification {
public:
  virtual string getContent() const = 0;
  virtual ~INotification() {}
};

class SimpleNotification : public INotification {
  string text;

public:
  SimpleNotification(string text)
  {
    this->text = text;
  }
  string getContent() const override
  {
    return this->text;
  }
};

//  ABstract Decorator: wrpas the noitification object:
class INotificationDecorator : public INotification {
protected:
  INotification *notification;

public:
  INotificationDecorator(INotification *notif)
  {
    this->notification = notif;
  }

  virtual ~INotificationDecorator() {}
};

class BoldTextNotification : public INotificationDecorator {
public:
  BoldTextNotification(INotification *n) : INotificationDecorator(n) {}
  string getContent() const override
  {
    return "Bold" + notification->getContent();
  }
};

class TImeSTampNotification : public INotificationDecorator {
public:
  TImeSTampNotification(INotification *n) : INotificationDecorator(n)
  {
  }
  string getContent() const override
  {
    return "timestamp" + notification->getContent();
  }
};

class SignatureDecorator : public INotificationDecorator {
public:
  SignatureDecorator(INotification *n) : INotificationDecorator(n) {}

  string getContent() const override
  {
    return "signature" + notification->getContent();
  }
};

class IObserver {
public:
  virtual void update() = 0;
  virtual ~IObserver() {}
};

class IObservable {
public:
  virtual void add(IObserver *newObserver) = 0;
  virtual void remove(IObserver *observer) = 0;
  virtual void notify() = 0;
};

class NotificationObservable : public IObservable {
private:
  vector<IObserver *> listOfObservers;
  INotification *currentNotification;

public:
  NotificationObservable()
  {
    currentNotification = nullptr;
  }
  void add(IObserver *newObserver) override
  {
    listOfObservers.push_back(newObserver);
  }

  void remove(IObserver *observer) override
  {
    listOfObservers.erase(remove(listOfObservers.begin(), listOfObservers.end(), observer), listOfObservers.end());
  }
  void notify() override {
    for(auto it: listOfObservers) {
      it->update();
    }
  }

  void setNotifications (INotification* n) {
    currentNotification = n;
  }

  INotification* getNotification () {
    return currentNotification;
  }
};

int main()
{
}