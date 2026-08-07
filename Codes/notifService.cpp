#include<iostream>
using namespace std;

class INotificationService {
  public:
  string content;
  virtual string getContent() = 0;
};


class ConcreteNotificationService: public INotificationService {
  public:
  string text;
  ConcreteNotificationService(string text) {
    this->text = text;
  }
  string getContent() {
    return text;
  }
};

class ITextDecorator: public INotificationService {
  public:
  INotificationService* notificatioNService;
  virtual string getContent() = 0;
};

class BoldText: public ITextDecorator {
  public:
  BoldText() {
    this->notificatioNService = new ConcreteNotificationService();
  }
  string getContent() {
    return "Bold Text" + notificatioNService->getContent();
  }
};

class ItalicsText: public ITextDecorator {
  ItalicsText() {
    this->notificatioNService = new ConcreteNotificationService();
  }
  string getContent () {
    return "Italics" + notificatioNService->getContent();
  }
};








int main () {

}