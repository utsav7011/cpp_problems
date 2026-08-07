
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<cstdlib>
using namespace std;

struct PaymentRequest{
  string sender;
  double amount;
  string reciever;
  string currency;

  PaymentRequest(string sender, string reciever, double amount, string currency){
    this->sender = sender;
    this->reciever = reciever;
    this->amount = amount;
    this->currency = currency;
  }
};


class BankingSystem {
public:
  virtual bool processPayment(double amount) = 0;
  virtual ~BankingSystem() {}
};


class PaytmBankingSystem: public BankingSystem {
  public:
  PaytmBankingSystem() {}
  bool processPayment(double amount) override {
    int r = rand() % 100;
    return r < 20;
  }
};


class RazorpayBankingSystem: public BankingSystem {
  public:
  RazorpayBankingSystem() {}
  bool processPayment(double amount) override {
    int r = rand() % 100;
    return r < 90;
  }
};


class PaymentGateway{
  public:
  BankingSystem* bankingSystem;
  PaymentGateway() {
    bankingSystem = nullptr;
  }
  virtual ~PaymentGateway() {
    delete bankingSystem;
  }

  virtual bool processPayment(PaymentRequest* pr) {
    if (!validateRequest(pr)) {
      cout<<"[Payment gateway] Validation failed for: "<<pr->sender<<endl;
      return false;
    }
    if (!initiatePayment(pr)) {
      cout<<endl<<"[Payment gateway] Initiation failed for: "<<pr->sender<<endl;
      return false;
    }
    if (!confirmTransaction(pr)) {
      cout<<endl<<"[Payment Gateway] Confirm transaction failed for: "<<pr->sender;
      return false;
    }
    return true;
  }

  virtual bool validateRequest(PaymentRequest* pr) = 0;
  virtual bool initiatePayment(PaymentRequest* pr) = 0;
  virtual bool confirmTransaction(PaymentRequest* pr) = 0;

};

class PaytmPaymentGateway: public PaymentGateway {
  public:
  PaytmPaymentGateway() {
    bankingSystem = new PaytmBankingSystem();
  }
  bool validateRequest(PaymentRequest* pr) override {
    cout<<endl<<"Validating the payment request"<<endl;
    return true;
  }

  bool initiatePayment(PaymentRequest* pr) override {
    cout<<endl<<"Inititing payment process after validation"<<endl;
    return bankingSystem->processPayment(pr->amount);
  }

  bool confirmTransaction(PaymentRequest* pr) override {
    cout<<endl<<"Confirming Payment request"<<endl;
    return true;
  }
};

class RazorPayPaymentGateway: public PaymentGateway {
  public:
  RazorPayPaymentGateway() {
    bankingSystem = new RazorpayBankingSystem();
  }
  bool validateRequest(PaymentRequest* pr) override {
    cout<<endl<<"Validating the payment request"<<endl;
    return true;
  }

  bool initiatePayment(PaymentRequest* pr) override {
    cout<<endl<<"Inititing payment process after validation"<<endl;
    return bankingSystem->processPayment(pr->amount);
  }

  bool confirmTransaction(PaymentRequest* pr) override {
    cout<<endl<<"Confirming Payment request"<<endl;
    return true;
  }
};

class PaymentgatewayProxy: public PaymentGateway {
  public:
  PaymentGateway * realGateway;
  int retries;
  PaymentgatewayProxy(PaymentGateway* gateway, int retries) {
    this->realGateway = gateway;
    this->retries = retries;
  }

  ~PaymentgatewayProxy() {
    delete realGateway;
  }

  bool processPayment(PaymentRequest* pr) override {
    for (int i = 0; i < retries; i++) {
      if (realGateway->processPayment(pr)) {
        return true;
      }
    }
    return false;
  }

  bool validateRequest(PaymentRequest* pr) override {
    return realGateway->validateRequest(pr);
  }

  bool initiatePayment(PaymentRequest* pr) override {
    return realGateway->initiatePayment(pr);
  }

  bool confirmTransaction(PaymentRequest* pr) override {
    return realGateway->confirmTransaction(pr);
  }
};

class PaymentService {
public:
  bool processPayment(PaymentRequest* request, PaymentGateway* gateway) {
    if (!gateway || !request) {
      cout<<"[Payment Service] Invalid payment request or gateway"<<endl;
      return false;
    }

    cout<<"[Payment Service] Handling payment business logic"<<endl;
    return gateway->processPayment(request);
  }
};

class PaymentController {
private:
  PaymentService paymentService;
  PaymentGateway* gateway;

public:
  PaymentController(PaymentGateway* gateway) : gateway(gateway) {}

  bool makePayment(PaymentRequest* request) {
    cout<<"[Payment Controller] Delegating payment request to service"<<endl;
    return paymentService.processPayment(request, gateway);
  }
};

enum class GatewayType {
  PAYTM,
  RAZORPAY
};

class GatewayFactory{
  private:
  static GatewayFactory instance;
  GatewayFactory() {}
  GatewayFactory(const GatewayFactory&) = delete;
  GatewayFactory& operator=(const GatewayFactory&) = delete;

  public:
  static GatewayFactory& getInstance() {
    return instance;
  }
  PaymentGateway* getGateway(GatewayType type) {
    if (type == GatewayType::PAYTM) {
      PaymentGateway* paymentGateway = new PaytmPaymentGateway();
      return new PaymentgatewayProxy(paymentGateway, 3);
    }

    if (type == GatewayType::RAZORPAY) {
      PaymentGateway* paymentGateway = new RazorPayPaymentGateway();
      return new PaymentgatewayProxy(paymentGateway, 3);
    }

    return nullptr;
  }
};

GatewayFactory GatewayFactory::instance;

int main() {
  PaymentGateway* gateway = GatewayFactory::getInstance().getGateway(GatewayType::PAYTM);
  if (!gateway) {
    cout << "No gateway available" << endl;
    return 1;
  }

  PaymentController controller(gateway);
  PaymentRequest request("Alice", "Bob", 100.0, "INR");

  bool success = controller.makePayment(&request);
  cout << "Payment status: " << (success ? "Success" : "Failed") << endl;

  delete gateway;
  return 0;
}