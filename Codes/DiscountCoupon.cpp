#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

class DiscountStrategy {
  public:
  virtual ~DiscountStrategy() {}
  virtual double calculate(double amount) = 0;
};


class FlatDiscountStrategy: public DiscountStrategy {
  private:
    double amount;
  public:
    FlatDiscountStrategy(double amt) {
      this->amount = amt;
    }

    double calculate (double baseAmount) override {
      return min(amount, baseAmount);
    }
};

class PercentageDiscountStrategy: public DiscountStrategy {
  double percentage;
  public:
  PercentageDiscountStrategy(double percentage) {
    this->percentage = percentage;
  }

  double calculate(double baseAmount) override {
    return (0.01 * percentage) * baseAmount;
  }
};

class PercentageDiscountWithCapStrategy: public DiscountStrategy {
  double percentage;
  double offset;
  public:
  PercentageDiscountWithCapStrategy(double percentage, double offset) {
    this->percentage = percentage;
    this->offset = offset; 
  }

  double calculate(double baseAmount) override {
    return min(offset, ((0.01 * percentage) * baseAmount));
  }
};


enum StrategyType {
  FLAT,
  PERCENT,
  PERCENT_WITH_CAP
};

class DiscountStrategyManager {
  private:
  static DiscountStrategyManager* instance;
  DiscountStrategyManager() {}
  DiscountStrategyManager (const DiscountStrategyManager&) = delete;
  DiscountStrategyManager& operator= (const DiscountStrategyManager&) = delete;

  public:
  static DiscountStrategyManager* getinstance() {
    if (!instance) {
      instance = new DiscountStrategyManager();
    }
    return instance;
  }

  DiscountStrategy* getStrategy (StrategyType type, double param1, double param2 = 0.0) const {
    if (type == StrategyType::FLAT) {
      return new FlatDiscountStrategy(param1);
    } else if (type == StrategyType::PERCENT) {
      return new PercentageDiscountStrategy(param1);
    } else if (type == StrategyType::PERCENT_WITH_CAP) {
      return new PercentageDiscountWithCapStrategy(param1, param2);
    }
    return nullptr;
  }
};

DiscountStrategyManager* DiscountStrategyManager::instance = nullptr;

class Product {
  string name;
  string category;
  double price;
  public:
  Product(string name, string category, double price) {
    this->name = name;
    this->category= category;
    this->price = price;
  }

  string getName() const {
    return this->name;
  }
  string getCategory() const {
    return this->category;
  }

  double getPrice() const {
    return this->price;
  }
};


class CartItem {
  Product* product;
  int quantity;
  public:
  CartItem(Product* product, int quantity) {
    this->product = product;
    this->quantity = quantity;
  }

  double itemTotal() {
    return product->getPrice() * quantity;
  }
  const Product* getproduct() {
    return this->product;
  }
};


class Cart {
  private:
  vector<CartItem*> items;
  double currentTotal;
  double originalTotal;
  bool loyaltyMember;
  string paymentBank;
  public:
  Cart() {
    originalTotal = 0.0;
    currentTotal= 0.0;
    this->loyaltyMember = false;
    this->paymentBank = "";
  }

  void addProduct(Product* prod, int quantity = 1) {
    CartItem* newItem = new CartItem(prod, quantity);
    items.push_back(newItem);
    cout<<endl<<"New Cart Item pushed";
    originalTotal += newItem->itemTotal();
    currentTotal += newItem->itemTotal();
  }
  double getOriginalTtoal() {
    return this->originalTotal;
  }

  double getCurrentTotal () {
    return this->currentTotal;
  }

  void applyDiscount(double d) {
    currentTotal -= d;
    if (currentTotal < 0) {
      currentTotal = 0;
    }
  }
  void setLoyaltyMember(bool member){
    this->loyaltyMember = (member == true);
  }
  bool isLoyaltyMember() const {
    return this->loyaltyMember;
  }
  void setPaymentBank(string paymentsBank) {
    this->paymentBank = paymentsBank;
  }
  vector<CartItem*> getItem() {
    return items;
  }
}; 

class Coupon {
  Coupon* next;
  public:
  Coupon () {
    next = nullptr;
  }
  virtual ~Coupon() {}
  void  setnext(Coupon* c) {
    this->next = c;
  }

  Coupon* getNext () {
    return next;
  }

  void applyDiscount(Cart* cart) {
    if (isApplicable(cart)) {
      double discount = getDiscount(cart);
      cart->applyDiscount(discount);
      cout<<endl<<name() <<"Applied: "<<discount<<endl;
      if (!isCombinable(cart)){
        return;
      }
    }
    if (next) {
      next->applyDiscount(cart);
    } 
  }

  virtual bool isApplicable(Cart* c) = 0;
  virtual bool isCombinable(Cart* c) = 0;
  virtual double getDiscount(Cart* c) = 0; 
  virtual string name() = 0;
};

class SeasonalCoupon: public Coupon {
  double percent;
  string category;
  DiscountStrategy* strategy;

  public:
  SeasonalCoupon(double percentage, string category) {
    this->percent = percentage;
    this->category = category; 
    strategy = DiscountStrategyManager::getinstance()->getStrategy(StrategyType::PERCENT, percent);
  }
  ~SeasonalCoupon() {
    delete strategy;
  }
  bool isApplicable (Cart* cart) override {
    for (auto item: cart->getItem()) {
      if (item->getproduct()->getCategory() == this->category) {
        return true;
      }
    }
    return false;
  }

  double getDiscount(Cart* cart)override {
    double subtotal = 0;
    for (CartItem* cartItem: cart->getItem()) {
      if (cartItem->getproduct()->getCategory() == category) {
        subtotal += cartItem->itemTotal();
      }
    }
    return strategy->calculate(subtotal);
  }

  bool isCombinable(Cart* cart) override {
    return true;
  }
  string name() override{
    return "SeasonalCoupon";
  }
};


class LoyaltyDiscount: public Coupon {
  private:
  double percent;
  DiscountStrategy* strategy;
  public:
  LoyaltyDiscount(double percentage) {
    this->percent = percentage;
    strategy = DiscountStrategyManager::getinstance()->getStrategy(StrategyType::PERCENT, percent);
  }

  ~LoyaltyDiscount() {
    delete strategy;
  }

  bool isApplicable(Cart* c) override {
    return c->isLoyaltyMember();
  }

  bool isCombinable(Cart* c) override {
    return true;
  }

  double getDiscount(Cart* c) override {
    double total = c->getCurrentTotal();
    return strategy->calculate(total);
  }

  string name() override {
    return "LoyaltyDiscount";
  }

};




int main() {
  Product p1("TShirt", "Clothing", 50.0);
  Product p2("Jeans", "Clothing", 80.0);
  Product p3("Chips", "Grocery", 10.0);

  Cart cart;
  cart.addProduct(&p1, 2); // 2 * 50 = 100
  cart.addProduct(&p2, 1); // 1 * 80 = 80
  cart.addProduct(&p3, 3); // 3 * 10 = 30

  cout<<"Original total: "<<cart.getOriginalTtoal()<<endl;

  // Create coupons
  Coupon* seasonal = new SeasonalCoupon(10.0, "Clothing"); // 10% on clothing
  Coupon* loyalty = new LoyaltyDiscount(5.0); // 5% on entire cart for loyalty members

  // chain coupons: seasonal -> loyalty
  seasonal->setnext(loyalty);

  // mark as loyalty member
  cart.setLoyaltyMember(true);

  // apply chained coupons
  seasonal->applyDiscount(&cart);

  cout<<"Final total after discounts: "<<cart.getCurrentTotal()<<endl;

  delete seasonal;
  delete loyalty;

  return 0;
}