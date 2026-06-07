#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Product {
  private:
  int sku;
  string name;
  double price;
  public:
  Product(int sku, double price, string nmae) {
    this->sku = sku;
    this->price = price;
    this->name = name;
  }

  // getters and setters:
  int getSKU () {
    return this->sku;
  }

  string getName() {
    return this->name;
  }

  double getPrice() {
    return this->price;
  }
};


class ProductFactory {
  public:
  static Product* createProduct(int sku) {
    string name;
    double price;
    if (sku == 101 ) {
      name = "Apple";
      price=20;
    }
    else if (sku == 102) {
      name = "Banana";
      price=40;
    } 
    else if (sku == 103) {
      name = "Chocolate";
      price = 10;
    } else if (sku == 201) {
      name ="T-Shirt";
      price = 1000;
    } else if (sku == 202) {
      name ="Jeans";
      price = 600;
    } else {
      name = "Item" + to_string(sku);
      price = 1020;
    }

    return new Product(sku, price, name);

  }
};


class InventoryStore {
  public:
  virtual ~InventoryStore() {}
  virtual void addProduct(Product* newProduct, int qty) =  0;
  virtual void removeProduct(int sku, int qty) = 0;
  virtual int checkStock(int sku) = 0;
  virtual vector<Product*> listAvailabeProducts() = 0;
};


class DbInventoryStore: public InventoryStore {
  private:
  map<int, int>* stock; // sku, qty
  map<int, Product*>* products;    /// sku, prodcutDetails
  
  public:
  DbInventoryStore() {
    stock = new map<int, int>();
    products = new map<int, Product*>();
  }

  ~DbInventoryStore() {
    for (auto it: *products) {
      delete it.second;
    }
    delete products;
    delete stock;
  }

  void addProduct(Product* newProduct, int qty) override{
    int sku = newProduct->getSKU();
    if (products->count(sku) == 0) {
      (*products)[sku] = newProduct;
    } else {
      delete newProduct;
    }
    (*stock)[sku] += qty;
  }

  void removeProduct(int sku, int qty) override {
    if (stock->count(sku) == 0) {
      cout<<endl<<"No product item to delete"<<endl;
    }
    int currentQuantity = (*stock)[sku];
    int remainingQty = currentQuantity - qty;
    if (remainingQty > 0) {
      (*stock)[sku] = remainingQty;
    } else {
      stock->erase(sku);
    }
  }

  int checkStock(int sku) override {
    if (stock->count(sku) == 0) {
      return 0;
    } else return (*stock)[sku];
  }
  vector<Product*> listAvailabeProducts() override{
    vector<Product*> available;
    for (auto it: *stock) {
      int sku = it.first;
      int qty = it.second;
      if (qty > 0 && products->count(sku)) {
        available.push_back((*products)[sku]);
      }
    }
  }
};



class InventoryManager {
  private:
  InventoryStore* store;
  public:
  InventoryManager(InventoryStore* store) {
    this->store = store;
  }
  void addStock(int sku, int qty) {
    Product* prod = ProductFactory::createProduct(sku);
    store->addProduct(prod, qty);
    cout<<endl<<"Inventory Managet: Added SKU: "<<sku<<" QTY: "<<qty<<endl;
  }

  void removeStock(int sku, int qty) {
    store->removeProduct(sku, qty);
  }

  int checkStock(int sku) {
    return store->checkStock(sku);
  }
  vector<Product*> getAvailableProduct() {
    return store->listAvailabeProducts();
  }
};

class ReplenishStrategy {
  public:
  virtual void replenish (InventoryManager* manager, map<int, int > itemsToReplenish) = 0;
  virtual ~ReplenishStrategy() {} 
};


class ThresholdReplenishStrategy: public ReplenishStrategy {
  private:
  int threshold;
  public:
  ThresholdReplenishStrategy(int threshold) {
    this->threshold = threshold;
  } 
  void replenish (InventoryManager* manager, map<int, int> itemsToReplenish) override {
    cout<<endl<<"Threshold replenishz:::: checking threshold::::::"<<endl;
    for (auto it: itemsToReplenish) {
      int sku = it.first;
      int qtyToAdd = it.second;
      int current = manager->checkStock(sku);
      if (current < threshold) {
        manager->addStock(sku, qtyToAdd);
        cout<<endl<<"SKU::::"<<sku<<"was "<<current;
        cout<<endl<<"replenished by::::"<<qtyToAdd<<endl;
      }
    }
  }
};


class WeeklyReplenish: public ReplenishStrategy {
  public:
  void replenish(InventoryManager* manager, map<int, int> itemsToReplenish) override{
    cout<<endl<<"Weekly replenish strategy selected by the user and replenished....."<<endl;
  }
};


class DarkStore {
  private:
  string name;
  double x, y;
  InventoryManager* inventoryManager;
  ReplenishStrategy* replenishStrategy;

  public:
  DarkStore(string n, double x_coord, double y_coord) {
    this->name = n;
    x = x_coord;
    y = y_coord;
    inventoryManager = new InventoryManager(new DbInventoryStore);
  }
  ~DarkStore() {
    delete inventoryManager;
    if (replenishStrategy) delete replenishStrategy;
  }
  double distanceToUserLocation(double ux, double uy) {
    return sqrt(((x-ux)*(x-ux)) + ((y-uy)*(y-uy)));
  } 
  void runReplenishment(map<int, int> itemsToReplenish) {
    if (replenishStrategy) {
      replenishStrategy->replenish(inventoryManager, itemsToReplenish);
    }
  }
  // delegationMethids:
  vector<Product*> getAllProducts() {
    return inventoryManager->getAvailableProduct();
  }

  int checkStock(int sku) {
    return inventoryManager->checkStock(sku);
  }

  void removeProduct(int sku, int qty) {
    inventoryManager->removeStock(sku, qty);
  }


  void addStock(int sku, int qty) {
    Product* prod = ProductFactory::createProduct(sku);
    inventoryManager->addStock(sku, qty);
  }

  void setReplenishStrategy(ReplenishStrategy* strategy) {
    this->replenishStrategy = strategy;
  }

  string getName() {
    return this->name;
  }
  double getXCoord() {
    return this->x;
  }

  double getYCoord() {
    return this->y;
  }

  InventoryManager* getInventoryManager() {
    return this->inventoryManager;
  }
};


class DarkStoreManager{
  private:
  vector<DarkStore*>* darkStores;
  static  DarkStoreManager* instance;
  DarkStoreManager() {
    darkStores = new vector<DarkStore*>();
  };
  public:
  static DarkStoreManager* getInstance() {
    if (instance != nullptr) return instance;
    else return new DarkStoreManager();
  }

  void registerDarkStore(DarkStore* store) {
    darkStores->push_back(store);
  }

  vector<DarkStore*> getnearbyDarkStore(double ux, double uy, double maxDistance) {
    vector<pair<double, DarkStore*>> dsList;
    for (auto ds: *darkStores) {
      double d = ds->distanceToUserLocation(ux, uy);
      if (d <= maxDistance) {
        dsList.push_back({d, ds});
      }
    }
    sort(dsList.begin(), dsList.end(), [](auto &a, auto &b) { return a.first < b.first});
    vector<DarkStore*> result;
    for (auto &p: dsList) {
      result.push_back(p.second);
    }
  }

  ~DarkStoreManager() {
    for (auto ds: *darkStores) {
      delete ds;
    }
  }
};

DarkStoreManager* DarkStoreManager::instance = nullptr;


class Cart {
  public:
  vector<pair<Product*, int>> items;
  void addItem(int sku, int qty) {
    Product* prod = ProductFactory::createProduct(sku);
    items.push_back({prod, qty});
    cout<<endl<<"[Cart ] Added Product to the cart"<<endl;
    cout<<"ProductDetails: "<<endl<<prod->getName();
    cout<<endl<<"price: "<<prod->getPrice();
    cout<<endl<<"SKU: "<<prod->getSKU();
  }

  double getTotla() {
    double sum = 0;
    for (auto item: items) {
      sum+= (item.first->getPrice() * item.second);
    }
    return sum;
  }
  vector<pair<Product*, int>> getItems() {
    return items;
  }
  ~Cart() {
    for (auto it: items) {
      delete it.first;
    }
  }
};


class User{
  public:
  string name;
  double x, y;
  Cart* cart;
  User(string n, double x_coord, double y_coord) {
    this->name = n;
    this->x = x_coord;
    this->y = y_coord;
    cart = new Cart();
  }
  ~User() {
    delete cart;
  }

  Cart* getCart() {
    return cart;
  }
};


class DeliveryPartner {
  public:
  string nmae;
  DeliveryPartner(string n) {
    this-> nmae = n;
  }
};


// Order Management: 
class Order {
  public:
  static int nextId;
  int orderId;
  int userId;
  User* user;
  vector<pair<Product*, int>> items;
  vector<DeliveryPartner> deliveryPartners;

  double totalAmount;

  Order(User* user) {
    orderId = nextId++;
    this->user = user;
    totalAmount = 0.0;
  }
};
int Order::nextId = 1;


class OrderManager {
  private:
  vector<Order*>* orders;
  static OrderManager* instance;

  OrderManager() {
    orders = new vector<Order*>();
  }
  public:
  static OrderManager* getInsatnce() {
    if (instance != nullptr) return instance;
    else return new OrderManager();
  }

  void placeOrder(User* user, Cart* cart) {
    cout<<endl<<"[OrderManager::: ] p[lacing order for]"<<user->name<<endl;
    vector<pair<Product*, int>> requestedItems = cart->getItems();

    // find the nearest darksStore in 5 KM:
    double maxDist = 5.0;
    vector<DarkStore*> nearByDarkStore = DarkStoreManager::getInstance()->getnearbyDarkStore(user->x, user->y, maxDist);
    if (nearByDarkStore.empty()) {
      cout<<endl<<"No darkstores are located near the user locations"<<endl;
      return;
    }
    DarkStore* firstStore = nearByDarkStore[0];
    bool allInFirst = true;
    for (pair<Product*, int>&item: requestedItems) {
      int sku = item.first->getSKU();
      int qty = item.second;
      if (firstStore->checkStock(sku)< qty) {
        allInFirst - false;
        break;
      }
    }
    Order* order = new Order(user);

    if (allInFirst){
      cout<<"all items at"<<firstStore->getName()<<endl;
      // remove the items from the store:
      for (pair<Product*, int>&item: requestedItems) {
        int sku = item.first->getSKU();
        int qty = item.second;
        firstStore->removeProduct(sku, qty);
      }
    } else {
        // logic to split the order between multiple da4rkStores and assign new Delivery partners to all orders in multiple splitted darkstores
    }
  }

  vector<Order*> getAllOrders( ){
    return *orders;
  }

  ~OrderManager (){
    for (auto order: *orders) {
      delete order;
    }
    delete orders;
  }
};

OrderManager* OrderManager::instance = nullptr;