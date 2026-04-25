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

class INotification
{
public:
  virtual string getContent() const = 0;
  virtual ~INotification() {}
};

class SimpleNotification : public INotification
{
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
class INotificationDecorator : public INotification
{
protected:
  INotification *notification;

public:
  INotificationDecorator(INotification *notif)
  {
    this->notification = notif;
  }

  virtual ~INotificationDecorator() {}
};

class BoldTextNotification : public INotificationDecorator
{
public:
  BoldTextNotification(INotification *n) : INotificationDecorator(n) {}
  string getContent() const override
  {
    return "Bold" + notification->getContent();
  }
};

class TImeSTampNotification : public INotificationDecorator
{
public:
  TImeSTampNotification(INotification *n) : INotificationDecorator(n)
  {
  }
  string getContent() const override
  {
    return "timestamp" + notification->getContent();
  }
};

class SignatureDecorator : public INotificationDecorator
{
public:
  SignatureDecorator(INotification *n) : INotificationDecorator(n) {}

  string getContent() const override
  {
    return "signature" + notification->getContent();
  }
};

class IObserver
{
public:
  virtual void update() = 0;
  virtual ~IObserver() {}
};

class IObservable
{
public:
  virtual void add(IObserver *newObserver) = 0;
  virtual void remove(IObserver *observer) = 0;
  virtual void notify() = 0;
};

class NotificationObservable : public IObservable
{
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

  void notify() override
  {
    for (auto it : listOfObservers)
    {
      it->update();
    }
  }

  void setNotifications(INotification *n)
  {
    if (currentNotification != nullptr)
      delete currentNotification;
    currentNotification = n;
    notify();
  }

  INotification *getNotification()
  {
    return currentNotification;
  }

  string getNotificationContent()
  {
    return currentNotification->getContent();
  }
};

class Logger : IObserver
{
private:
  NotificationObservable *notificationObservable;

public:
  Logger(NotificationObservable *n)
  {
    this->notificationObservable = n;
  }
  void update() override
  {
    cout << endl
         << "Logging the notification ::::: " << notificationObservable->getNotificationContent();
  }
};

class INOtificationStrategy
{
public:
  virtual void sendNotification(string content) = 0;
};

class EmailNotification : public INOtificationStrategy
{
  string email;

public:
  EmailNotification(string email)
  {
    this->email = email;
  }
  void sendNotification(string content) override
  {
    // process to send the email notifdication;
    cout << endl
         << "Email notification sent to the user: " << content;
  }
};

class SmsNotification : public INOtificationStrategy
{
  string number;

public:
  SmsNotification(string number)
  {
    this->number = number;
  }
  void sendNotification(string content) override
  {
    // process to send the email notifdication;
    cout << endl
         << "Sms notification sent to the user: " << content;
  }
};

class PopUpNotification : public INOtificationStrategy
{
public:
  void sendNotification(string content) override
  {
    // process to send the email notifdication;
    cout << endl
         << "popup notification sent to the user: " << content;
  }
};


class NotificationEngine: public IObserver {
  NotificationObservable* notificationObservable;
  vector<INOtificationStrategy*> notificationStrategies; 
  public:
  NotificationEngine(NotificationObservable* notificationObservable) {
    this->notificationObservable = notificationObservable;
  }
  void addNotificationStrategy(INOtificationStrategy* strategy) {
    this->notificationStrategies.push_back(strategy);
  }
  void update() override {
    string notificationContent = notificationObservable->getNotificationContent();
    for (auto it: notificationStrategies) {
      it->sendNotification(notificationContent);
    }
  }
};


// notificatio serice:
// this service manages the notiufcations
// keeps track of all the notifications
// any client code will interact with this service

class NotificationService {
  private:
  NotificationObservable* observable;
  static NotificationService* instance;
  vector<INotification*> notifications;

  NotificationService() {
    observable = new NotificationObservable();
  }
  public:
  static NotificationService* getIUnstance () {
    if (instance != nullptr) return instance;
    instance = new NotificationService();

    return instance;
  }
  NotificationObservable* getObservable() {
    if (observable == nullptr) {
      observable = new NotificationObservable();
    }
    return observable;
  }

  void sendNotification (INotification* notification) {
    notifications.push_back(notification);
    observable->setNotifications(notification);
  }

  ~NotificationService () {
    delete instance;
  }
};

NotificationService* NotificationService::instance = nullptr;


int main()
{
}