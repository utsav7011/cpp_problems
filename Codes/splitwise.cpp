#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;


class Observer {
  public:
  // virtual methsd that needs to be overridden and which is called everytime there is an update in the observable.
  virtual void update(string message) = 0;
};

class User: public Observer {
  string name, id, email;

  // map of wha thte user owes or neds to take form other users
  // positiove double value->need to take
  // negative double value -> need to gice to other user.
  map<string, double> balances;
  
  public:
  // simple incremental id generator to ensure unique ids within this process
  static int s_nextId;

  User (string email, string name) {
    this->email = email;
    this->name = name;
    this->id = "U" + to_string(++s_nextId);
  }

  // Update called by observable subjects — print a simple notification.
  void update(string message) override {
    cout << "Notification for " << name << " (" << id << "): " << message << endl;
  }

  // Accessors
  string getId() const { return id; }
  string getName() const { return name; }
  string getEmail() const { return email; }

  // Adjust balance with another user. Positive amount means otherUser owes this user.
  void adjustBalance(const string &otherUserId, double amount) {
    balances[otherUserId] += amount;
    // If the balance becomes very close to zero, erase it for cleanliness
    if (fabs(balances[otherUserId]) < 1e-9) balances.erase(otherUserId);
  }

  // Get balance with another user (0.0 if no entry)
  double getBalanceWith(const string &otherUserId) const {
    auto it = balances.find(otherUserId);
    if (it == balances.end()) return 0.0;
    return it->second;
  }

  // Print all peer balances
  void printBalances() const {
    cout << "Balances for " << name << " (" << id << "):\n";
    if (balances.empty()) {
      cout << "  All settled up." << endl;
      return;
    }
    for (const auto &p : balances) {
      const string &peer = p.first;
      double amt = p.second;
      if (amt > 0)
        cout << "  " << peer << " owes " << name << ": " << amt << '\n';
      else
        cout << "  " << name << " owes " << peer << ": " << -amt << '\n';
    }
  }
};

int User::s_nextId = 0;

class Expenses {
  string Expenseid;
  string description;
  double amount;
  string paidByUserId;
  string groupID;
  public:
  Expenses (string description, double amount, string paidByUserId, string groupId) {
    this->description = description;
    this->amount = amount;
    this->paidByUserId = paidByUserId;
    this->groupID = groupId;
    // TODO Expense Id should be auto generated, maintain a commonj map for the user ID AND EXPSENSE ID AND WHENEVERE THERE IS AN UDPATE AT THAT TIME JUST UPDATE THE MAP AND GET THE LATEST VALUE.
  }
  // TODO Maintain the crud operations for the expenses.
  double getAmount() const { return amount; }
  string getPaidByUserId() const { return paidByUserId; }
  string getDescription() const { return description; }
};

#include<string>
#include<sstream>

class SplitStrategies {
  public:
  virtual ~SplitStrategies() = default;
  // operate on pointers so balances on passed users are updated
  virtual void calculateSplit(double amt, vector<User*> &users, vector<Expenses> &expenses) =  0;
  
  // helper: find user pointer by id
  static User* findUserById(const vector<User*> &users, const string &id) {
    for (auto u : users) if (u->getId() == id) return u;
    return nullptr;
  }
};

class EqualSplit: public SplitStrategies {
  public:
  void calculateSplit(double amt, vector<User*> &users, vector<Expenses> &expenses) override{
    // If explicit expenses provided, split each expense equally among the users
    if (!expenses.empty()) {
      for (auto &e : expenses) {
        double total = e.getAmount();
        int n = (int)users.size();
        if (n <= 0) continue;
        double share = total / n;
        User *payer = findUserById(users, e.getPaidByUserId());
        if (!payer) continue;
        for (auto u : users) {
          if (u->getId() == payer->getId()) continue;
          // payer is owed +share from u
          payer->adjustBalance(u->getId(), share);
          u->adjustBalance(payer->getId(), -share);
        }
      }
      return;
    }

    // No explicit expenses: split provided amt equally assuming users[0] is payer
    if (users.empty()) return;
    User *payer = users[0];
    int n = (int)users.size();
    double share = amt / n;
    for (auto u : users) {
      if (u->getId() == payer->getId()) continue;
      payer->adjustBalance(u->getId(), share);
      u->adjustBalance(payer->getId(), -share);
    }
  }
};

class PercentageSPlit: public SplitStrategies {
  public:
  void calculateSplit(double amt, vector<User*> &users, vector<Expenses> &expenses) override{
    // Expect each expense.description to contain comma-separated pairs of userId:percent
    for (auto &e : expenses) {
      double total = e.getAmount();
      User *payer = findUserById(users, e.getPaidByUserId());
      if (!payer) continue;
      string desc = e.getDescription();
      if (desc.empty()) continue;
      stringstream ss(desc);
      string token;
      while (getline(ss, token, ',')) {
        // token -> id:percent
        size_t pos = token.find(':');
        if (pos==string::npos) continue;
        string id = token.substr(0,pos);
        double pct = stod(token.substr(pos+1));
        double share = total * pct / 100.0;
        if (id == payer->getId()) continue;
        User *u = findUserById(users, id);
        if (!u) continue;
        payer->adjustBalance(u->getId(), share);
        u->adjustBalance(payer->getId(), -share);
      }
    }
  }
};

class FixedAmountSplit: public SplitStrategies {
  public:
  void calculateSplit(double amt, vector<User*> &users, vector<Expenses> &expenses) override{
    // Expect each expense.description to contain comma-separated pairs of userId:amount
    for (auto &e : expenses) {
      double total = e.getAmount();
      User *payer = findUserById(users, e.getPaidByUserId());
      if (!payer) continue;
      string desc = e.getDescription();
      if (desc.empty()) continue;
      stringstream ss(desc);
      string token;
      double accounted = 0.0;
      while (getline(ss, token, ',')) {
        size_t pos = token.find(':');
        if (pos==string::npos) continue;
        string id = token.substr(0,pos);
        double val = stod(token.substr(pos+1));
        accounted += val;
        if (id == payer->getId()) continue;
        User *u = findUserById(users, id);
        if (!u) continue;
        payer->adjustBalance(u->getId(), val);
        u->adjustBalance(payer->getId(), -val);
      }
      // if accounted != total, assign remainder to payer self or ignore
      double remainder = total - accounted;
      if (fabs(remainder) > 1e-9 && remainder != 0.0) {
        // payer covers remainder; no balance changes among others
        // If remainder > 0 it means payer paid extra; no action required
      }
    }
  }
};

enum SPLITSTRATEGIES {
  EQUAL,
  PERCENTAGE,
  FIXEDAMOUNT
};

class SplitFactory {
  // This will be a singeton class which will be acting as a factory for the creation of different kinds of split strategies.
  public:
  SplitStrategies* createSplitStrategy(SPLITSTRATEGIES s) {
    switch (s) {
      case EQUAL: return new EqualSplit();
      case PERCENTAGE: return new PercentageSPlit();
      case FIXEDAMOUNT: return new FixedAmountSplit();
      default: return nullptr;
    }
  }
};



class Group {
  string groupId;
  string groupName;
  vector<User*> members;
  vector<Expenses> expenses;
  static int s_nextGroupId;
  
  void notifyUsers(const string &message) {
    for (auto u : members) u->update(message);
  }

  public:
  Group(const string &name) {
    groupName = name;
    groupId = "G" + to_string(++s_nextGroupId);
  }

  string getId() const { return groupId; }
  string getName() const { return groupName; }

  void addUser(User *u) {
    for (auto m : members) if (m->getId() == u->getId()) return;
    members.push_back(u);
    notifyUsers("User " + u->getName() + " added to group " + groupName);
  }

  void removeUser(const string &userId) {
    for (size_t i = 0; i < members.size(); ++i) {
      if (members[i]->getId() == userId) {
        string name = members[i]->getName();
        members.erase(members.begin() + i);
        notifyUsers("User " + name + " removed from group " + groupName);
        return;
      }
    }
  }

  // Add an expense and apply the chosen split strategy
  void addExpense(const string &description, double amount, const string &paidByUserId, SPLITSTRATEGIES strat) {
    Expenses e(description, amount, paidByUserId, groupId);
    expenses.push_back(e);
    // apply split only for the new expense
    vector<Expenses> single = { expenses.back() };
    SplitFactory factory;
    SplitStrategies *strategy = factory.createSplitStrategy(strat);
    if (strategy) {
      strategy->calculateSplit(amount, members, single);
      delete strategy;
    }
    notifyUsers("Expense added in group " + groupName + ": " + description);
  }

  void printGroupBalances() const {
    cout << "Group " << groupName << " balances:\n";
    for (auto u : members) u->printBalances();
  }
};

int Group::s_nextGroupId = 0;


int main () {
  // Demo: create users and a group, perform splits and show balances
  User u1("alice@example.com", "Alice");
  User u2("bob@example.com", "Bob");
  User u3("carol@example.com", "Carol");

  Group g("Trip");
  g.addUser(&u1);
  g.addUser(&u2);
  g.addUser(&u3);

  cout << "--- Equal split: Alice pays 300 split among 3 ---\n";
  g.addExpense("Dinner", 300.0, u1.getId(), EQUAL);
  g.printGroupBalances();

  cout << "--- Percentage split: Bob pays 200 (Alice 50%, Carol 50%) ---\n";
  string percDesc = u1.getId() + ":50," + u3.getId() + ":50";
  g.addExpense(percDesc, 200.0, u2.getId(), PERCENTAGE);
  g.printGroupBalances();

  cout << "--- Fixed split: Carol pays 150 (Alice 40, Bob 60) ---\n";
  string fixedDesc = u1.getId() + ":40," + u2.getId() + ":60";
  g.addExpense(fixedDesc, 150.0, u3.getId(), FIXEDAMOUNT);
  g.printGroupBalances();

  return 0;
}