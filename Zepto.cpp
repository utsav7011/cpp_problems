#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;


class Product{
  private:
  int sku;
  string name;
  double price;
  public:
  Product(int sku, string name, double price) {
    this->sku = sku;
    this->price = price;
    this->name = name;
  }

  int getSKU() {
    return this->sku;
  }
  string getName() {
    return this->name;
  }

  double getPrice() {
    return this->price;
  }
};

class ProductFactory{
  public:
  static Product* createProduct(int sku) {
    string name;
    double price;
    switch(sku) {
      case 101:
      {
        name = "new Product 1";
        price = 100;
      } break;
      case 102:
      {
        name = "new Product 2";
        price = 101;
      } break;
      case 103:
      {
        name = "new Product 3";
        price = 103;
      } break;
      default: {
        cout<<endl<<"no product with sku found....."<<endl;
      }
    }
    return new Product(sku, name, price);
  }
};

class InventoryStore{
  private:
  public:
  virtual ~InventoryStore() {}
  virtual void addProducts(int quantity, Product* product) = 0;
  virtual void removeProduct(Product* prod, int qty) = 0;
  virtual int checkStock(int sku) = 0;
  virtual vector<Product*> listAllProducts() = 0;
};

class DBinventoryStore: public InventoryStore{
  private:
  map<int, int>* stock;
  map<int, Product*>* products;

  public:
  DBinventoryStore() {
    stock = new map<int, int>();
    products = new map<int, Product*>();
  }

  ~DBinventoryStore() {
    for (auto it: *products) {
      delete it.second;
    }
    delete products;
    delete stock;
  }

  void addProducts(int quantity, Product* product) override {
    int sku = product->getSKU();
    if (products->count(sku) == 0) {
      (*products)[sku] = product;
    } else {
      delete product;
    }
    (*stock)[sku] = quantity;
  }

  void removeProduct(Product* prod, int qty) override {
    int sku = prod->getSKU();
    if ((*stock)[sku] == 0) {
      return;
    }
    int currentQuantity = (*stock)[sku];
    int remainingQuantity = currentQuantity - qty;

    if (remainingQuantity > 0) {
      (*stock)[sku] = remainingQuantity;
    } else {
      stock->erase(sku);
    }
  }

  int checkStock(int sku) override {
    return stock->count(sku) ? (*stock)[sku] : 0;
  }

  vector<Product*> listAllProducts() override {
    vector<Product*> result;
    for (auto it: *products) {
      result.push_back(it.second);
    }
    return result;
  }
};

class InventoryManager {
  InventoryStore* store;
  public:
  InventoryManager(InventoryStore* store) {
    this->store = store;  
  }
  void addProduct(int qty, Product* prod) {
    store->addProducts(qty, prod);
  }
  void removeStock(int sku, int qty) {
    Product* prod = ProductFactory::createProduct(sku);
    store->removeProduct(prod, qty);
    delete prod;
  }
  int checkStock(int sku) {
    return store->checkStock(sku);
  }
  vector<Product*> listAllProdcut() {
    return store->listAllProducts();
  }
};


class ReplenishStrategy{
  public:
  virtual void replenish(InventoryManager* inventoryManager, map<int, Product*> itemsToReplemish)  = 0;
  virtual ~ReplenishStrategy() {}
};

class ThresholdReplenishStrategy: public ReplenishStrategy {
  private:
  int threshold;
  int replenishQuantity;

  public:
  ThresholdReplenishStrategy(int threshold, int replenishQuantity) {
    this->threshold = threshold;
    this->replenishQuantity = replenishQuantity;
  }

  void replenish(InventoryManager* inventoryManager, map<int, Product*> itemsToReplemish) override {
    for (auto it: itemsToReplemish) {
      int sku = it.first;
      Product* product = it.second;
      int currentStock = inventoryManager->checkStock(sku);
      if (currentStock < threshold) {
        int newStock = currentStock + replenishQuantity;
        inventoryManager->addProduct(newStock, product);
        cout<<endl<<"sku "<<sku<<" was below threshold ("<<currentStock<<" < "<<threshold
            <<"), replenished to "<<newStock<<" units"<<endl;
      }
    }
  }
};

class WeeklyReplenishStrategy: public ReplenishStrategy {
  private:
  int replenishQuantity;

  public:
  WeeklyReplenishStrategy(int replenishQuantity) {
    this->replenishQuantity = replenishQuantity;
  }

  void replenish(InventoryManager* inventoryManager, map<int, Product*> itemsToReplemish) override {
    for (auto it: itemsToReplemish) {
      int sku = it.first;
      Product* product = it.second;
      int currentStock = inventoryManager->checkStock(sku);
      int newStock = currentStock + replenishQuantity;
      inventoryManager->addProduct(newStock, product);
      cout<<endl<<"weekly top-up: sku "<<sku<<" replenished from "<<currentStock
          <<" to "<<newStock<<" units"<<endl;
    }
  }
};

class DarkStore {
  string name;
  double x, y;
  InventoryManager* inventoryManager;
  ReplenishStrategy* replenishStrategy;

  public:
  DarkStore(string n, double x_coord, double y_coord) {
    this->name = n;
    this->x = x_coord;
    this->y = y_coord;
    inventoryManager = new InventoryManager(new DBinventoryStore());
    replenishStrategy = nullptr;
  }
  ~DarkStore() {
    delete inventoryManager;
    delete replenishStrategy;
  }

  string getName() {
    return this->name;
  }

  InventoryManager* getInventoryManager() {
    return inventoryManager;
  }

  void setReplenishStrategy(ReplenishStrategy* strategy) {
    delete replenishStrategy;
    replenishStrategy = strategy;
  }

  double distanceTo(double ux, double uy) {
    return sqrt(pow(x - ux, 2) + pow(y - uy, 2));
  }

  void runReplenishment(map<int, int> itemsToReplenish) {
    if (replenishStrategy == nullptr) {
      cout<<endl<<"no replenish strategy set for store "<<name<<"....."<<endl;
      return;
    }
    map<int, Product*> items;
    for (auto it: itemsToReplenish) {
      int sku = it.first;
      items[sku] = ProductFactory::createProduct(sku);
    }
    replenishStrategy->replenish(inventoryManager, items);
  }
};

// singleton class
class DarkStoreManager {
  private:
  vector<DarkStore*> stores;
  static DarkStoreManager* instance;

  DarkStoreManager() {}

  public:
  DarkStoreManager(const DarkStoreManager&) = delete;
  DarkStoreManager& operator=(const DarkStoreManager&) = delete;

  static DarkStoreManager* getInstance() {
    if (instance == nullptr) {
      instance = new DarkStoreManager();
    }
    return instance;
  }

  void registerDarkStore(DarkStore* store) {
    stores.push_back(store);
  }

  vector<DarkStore*> getAllDarkStores() {
    return stores;
  }

  vector<DarkStore*> getNearestDarkStores(double ux, double uy, int count) {
    vector<DarkStore*> sorted = stores;
    sort(sorted.begin(), sorted.end(), [ux, uy](DarkStore* a, DarkStore* b) {
      return a->distanceTo(ux, uy) < b->distanceTo(ux, uy);
    });
    if ((int)sorted.size() > count) {
      sorted.resize(count);
    }
    return sorted;
  }

  ~DarkStoreManager() {
    for (auto store: stores) {
      delete store;
    }
  }
};

DarkStoreManager* DarkStoreManager::instance = nullptr;

class Cart {
  private:
  map<int, int> items; // sku -> quantity

  public:
  void addItem(int sku, int qty) {
    items[sku] += qty;
  }

  void removeItem(int sku, int qty) {
    if (items.count(sku) == 0) {
      return;
    }
    int remaining = items[sku] - qty;
    if (remaining > 0) {
      items[sku] = remaining;
    } else {
      items.erase(sku);
    }
  }

  map<int, int> getItems() {
    return items;
  }

  bool isEmpty() {
    return items.empty();
  }

  void clear() {
    items.clear();
  }

  double getTotalPrice() {
    double total = 0;
    for (auto it: items) {
      Product* prod = ProductFactory::createProduct(it.first);
      total += prod->getPrice() * it.second;
      delete prod;
    }
    return total;
  }
};

class User {
  private:
  int id;
  string name;
  double x, y;
  Cart* cart;

  public:
  User(int id, string name, double x_coord, double y_coord) {
    this->id = id;
    this->name = name;
    this->x = x_coord;
    this->y = y_coord;
    cart = new Cart();
  }

  ~User() {
    delete cart;
  }

  int getId() {
    return id;
  }

  string getName() {
    return name;
  }

  double getX() {
    return x;
  }

  double getY() {
    return y;
  }

  Cart* getCart() {
    return cart;
  }

  bool placeOrder(DarkStore* store) {
    map<int, int> items = cart->getItems();
    if (items.empty()) {
      cout<<endl<<name<<"'s cart is empty....."<<endl;
      return false;
    }

    InventoryManager* inventoryManager = store->getInventoryManager();
    for (auto it: items) {
      if (inventoryManager->checkStock(it.first) < it.second) {
        cout<<endl<<"order for "<<name<<" failed: insufficient stock for sku "<<it.first<<endl;
        return false;
      }
    }

    for (auto it: items) {
      inventoryManager->removeStock(it.first, it.second);
    }
    cart->clear();
    cout<<endl<<"order placed successfully for "<<name<<" from store "<<store->getName()<<endl;
    return true;
  }
};

class DeliveryAgent {
  private:
  int id;
  string name;
  double x, y;
  bool available;

  public:
  DeliveryAgent(int id, string name, double x_coord, double y_coord) {
    this->id = id;
    this->name = name;
    this->x = x_coord;
    this->y = y_coord;
    this->available = true;
  }

  int getId() {
    return id;
  }

  string getName() {
    return name;
  }

  bool isAvailable() {
    return available;
  }

  double distanceTo(double ux, double uy) {
    return sqrt(pow(x - ux, 2) + pow(y - uy, 2));
  }

  void deliverOrder(User* user) {
    if (!available) {
      cout<<endl<<name<<" is not available for delivery....."<<endl;
      return;
    }
    available = false;
    cout<<endl<<name<<" is delivering order to "<<user->getName()<<endl;
    x = user->getX();
    y = user->getY();
    available = true;
  }
};

class Order {
  private:
  int id;
  User* user;
  DarkStore* store;
  map<int, int> items;
  double totalPrice;
  string status;

  public:
  Order(int id, User* user, DarkStore* store, map<int, int> items, double totalPrice) {
    this->id = id;
    this->user = user;
    this->store = store;
    this->items = items;
    this->totalPrice = totalPrice;
    this->status = "PLACED";
  }

  int getId() {
    return id;
  }

  User* getUser() {
    return user;
  }

  DarkStore* getStore() {
    return store;
  }

  map<int, int> getItems() {
    return items;
  }

  double getTotalPrice() {
    return totalPrice;
  }

  string getStatus() {
    return status;
  }

  void setStatus(string status) {
    this->status = status;
  }
};

// singleton class
class OrderManager {
  private:
  map<int, Order*> orders;
  int nextOrderId;
  static OrderManager* instance;

  OrderManager() {
    nextOrderId = 1;
  }

  public:
  OrderManager(const OrderManager&) = delete;
  OrderManager& operator=(const OrderManager&) = delete;

  static OrderManager* getInstance() {
    if (instance == nullptr) {
      instance = new OrderManager();
    }
    return instance;
  }

  Order* placeOrder(User* user) {
    Cart* cart = user->getCart();
    if (cart->isEmpty()) {
      cout<<endl<<user->getName()<<"'s cart is empty....."<<endl;
      return nullptr;
    }

    map<int, int> items = cart->getItems();
    double totalPrice = cart->getTotalPrice();

    // assign the order to the nearest dark store that can fulfil it
    vector<DarkStore*> candidates = DarkStoreManager::getInstance()->getAllDarkStores();
    sort(candidates.begin(), candidates.end(), [user](DarkStore* a, DarkStore* b) {
      return a->distanceTo(user->getX(), user->getY()) < b->distanceTo(user->getX(), user->getY());
    });

    for (auto store: candidates) {
      if (user->placeOrder(store)) {
        Order* order = new Order(nextOrderId++, user, store, items, totalPrice);
        orders[order->getId()] = order;
        cout<<endl<<"order "<<order->getId()<<" assigned to dark store "<<store->getName()<<endl;
        return order;
      }
    }

    cout<<endl<<"no dark store could fulfil the order for "<<user->getName()<<"....."<<endl;
    return nullptr;
  }

  Order* getOrder(int orderId) {
    return orders.count(orderId) ? orders[orderId] : nullptr;
  }

  vector<Order*> getOrdersForUser(User* user) {
    vector<Order*> result;
    for (auto it: orders) {
      if (it.second->getUser() == user) {
        result.push_back(it.second);
      }
    }
    return result;
  }

  ~OrderManager() {
    for (auto it: orders) {
      delete it.second;
    }
  }
};

OrderManager* OrderManager::instance = nullptr;

int main (){
  DarkStore* storeA = new DarkStore("Zepto DarkStore - Koramangala", 0, 0);
  DarkStore* storeB = new DarkStore("Zepto DarkStore - Indiranagar", 5, 5);

  storeA->getInventoryManager()->addProduct(50, ProductFactory::createProduct(101));
  storeA->getInventoryManager()->addProduct(30, ProductFactory::createProduct(102));
  storeA->setReplenishStrategy(new ThresholdReplenishStrategy(10, 40));

  storeB->getInventoryManager()->addProduct(5, ProductFactory::createProduct(101));
  storeB->getInventoryManager()->addProduct(20, ProductFactory::createProduct(103));
  storeB->setReplenishStrategy(new WeeklyReplenishStrategy(25));

  DarkStoreManager::getInstance()->registerDarkStore(storeA);
  DarkStoreManager::getInstance()->registerDarkStore(storeB);

  cout<<endl<<"----- initial inventory -----"<<endl;
  for (auto store: DarkStoreManager::getInstance()->getAllDarkStores()) {
    cout<<store->getName()<<":"<<endl;
    for (auto prod: store->getInventoryManager()->listAllProdcut()) {
      cout<<"  sku "<<prod->getSKU()<<" ("<<prod->getName()<<") -> "
          <<store->getInventoryManager()->checkStock(prod->getSKU())<<" units"<<endl;
    }
  }

  User user(1, "Utsav", 1, 1);
  user.getCart()->addItem(101, 45);
  user.getCart()->addItem(102, 5);

  cout<<endl<<"----- placing order -----"<<endl;
  Order* order = OrderManager::getInstance()->placeOrder(&user);

  if (order != nullptr) {
    cout<<endl<<"order "<<order->getId()<<" total: "<<order->getTotalPrice()<<endl;

    DeliveryAgent agent(1, "Ravi", 0, 0);
    agent.deliverOrder(&user);
    order->setStatus("DELIVERED");
    cout<<"order "<<order->getId()<<" status: "<<order->getStatus()<<endl;
  }

  cout<<endl<<"----- replenishing dark stores -----"<<endl;
  map<int, int> storeAReplenishRequest = {{101, 0}, {102, 0}};
  storeA->runReplenishment(storeAReplenishRequest);

  map<int, int> storeBReplenishRequest = {{101, 0}, {103, 0}};
  storeB->runReplenishment(storeBReplenishRequest);

  cout<<endl<<"----- inventory after replenishment -----"<<endl;
  for (auto store: DarkStoreManager::getInstance()->getAllDarkStores()) {
    cout<<store->getName()<<":"<<endl;
    for (auto prod: store->getInventoryManager()->listAllProdcut()) {
      cout<<"  sku "<<prod->getSKU()<<" ("<<prod->getName()<<") -> "
          <<store->getInventoryManager()->checkStock(prod->getSKU())<<" units"<<endl;
    }
  }

  delete DarkStoreManager::getInstance();
  delete OrderManager::getInstance();

  return 0;
}