#include<iostream>
#include<vector>
#include<map>
#include<vector>
#include<string>
#include<cmath>
using namespace std;


class NotificationObserver{
  public:
  virtual ~NotificationObserver() {}
  virtual void update(const string& message) = 0;
};

// concrete Class:
class UserNotificationObserver: public NotificationObserver {
  private:
  string userId;
  public:
  UserNotificationObserver(string userid) {
    this->userId = userid;
  }
  void update(const string& message) override {
    cout<<endl<<"New message recieved: "<<message<<endl;
  }
};

// singleton class
class NotificationService {
  private:
  map<string, NotificationObserver*> observers;
  static NotificationService* instance;

  NotificationService() {}

  public:
  NotificationService(const NotificationService&) = delete;
  NotificationService& operator=(const NotificationService&) = delete;

  static NotificationService* getInstance() {
    if (instance == nullptr) {
      instance = new NotificationService();
    }
    return instance;
  }

  ~NotificationService() {
    for (auto it: observers) {
      delete it.second;
    }
  }

  void addnewObserver(string userId, NotificationObserver* observer) {
    if (observers.count(userId)) {
      delete observers[userId];
    }
    observers[userId] = observer;
  }

  void removeObserver(string userId) {
    if (observers.count(userId) == 0) {
      return;
    }
    delete observers[userId];
    observers.erase(userId);
  }

  void notifyuser(string userID, string message) {
    if (observers.count(userID) == 0) {
      cout<<endl<<"no observer registered for user "<<userID<<"....."<<endl;
      return;
    }
    observers[userID]->update(message);
  }

  void notifyAllusers(string message) {
    for (auto it: observers) {
      it.second->update(message);
    }
  }
};

NotificationService* NotificationService::instance = nullptr;


class Location {
  private:
  double latitude;
  double longitude;
  static constexpr double EARTH_RADIUS_KM = 6371.0;

  static double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
  }

  public:
  Location(double latitude, double longitude) {
    this->latitude = latitude;
    this->longitude = longitude;
  }

  double getLatitude() {
    return latitude;
  }

  double getLongitude() {
    return longitude;
  }

  // returns the great-circle distance to another location, in kilometers
  double calculateDistance(Location* location) {
    double lat1 = toRadians(latitude);
    double lat2 = toRadians(location->latitude);
    double dLat = toRadians(location->latitude - latitude);
    double dLon = toRadians(location->longitude - longitude);

    double a = sin(dLat / 2) * sin(dLat / 2) +
               cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS_KM * c;
  }
};

class Interest {
  private:
  string name;
  string description;

  public:
  Interest(string name, string description) {
    this->name = name;
    this->description = description;
  }

  string getName() {
    return name;
  }

  string getDescription() {
    return description;
  }
};


enum GENDER {
  MALE,
  FEMALE
};

class Profile{
  private:
  string name;
  int age;
  vector<Interest*> interests;
  GENDER preferredGenderInterest;

  public:
  Profile(string name, int age, GENDER preferredgenderInterest) {
    this->name = name;
    this->age = age;
    this->preferredGenderInterest = preferredgenderInterest;
  }

  ~Profile() {
    for (auto interest: interests) {
      delete interest;
    }
  }

  string getName() {
    return name;
  }

  int getAge() {
    return age;
  }

  GENDER getPreferredGenderInterest() {
    return preferredGenderInterest;
  }

  vector<Interest*> getInterests() {
    return interests;
  }

  void updateInsterest(Interest* interest) {
    // this function is used to add new interests to user profile
    interests.push_back(interest);
  }
};

class Preferences {
  int minAge;
  int maxAge;
  double maxDistance;
  vector<Interest*> interestsPreferredInPartner;

  public:
  Preferences(int minAge, int maxAge, double maxDistance) {
    this->minAge = minAge;
    this->maxAge = maxAge;
    this->maxDistance = maxDistance;
  }

  int getMinAge() {
    return this->minAge;
  }
  int getMaxAge() {
    return this->maxAge;
  }
  double getMaxDistance() {
    return this->maxDistance;
  }
  void setMionAge(int age) {
    this->minAge = age;
  }
  void setMaxAge(int age) {
    this->maxAge = age;
  }
};  


enum SwipeHistoryEnum {
  LEFT,
  RIGHT
};

class User {
  // the following class has the following entities and related methis:
  // userid, notiifcationObserver, userPOreprenced, profile, Location, displayProfile method, map of swipeHIstory map amp<userID, swipeHistory>
  // SwipeHistoryEnUm is na enum that tells that a particular ID was swiped ewither right or l;eft bu the current user.
  // method to perform a swipeOperation

  // listAllProfuiles nearby,
  private:
  string userId;
  NotificationObserver* notificationObserver;
  Preferences* preferences;
  Profile* profile;
  Location* location;
  map<string, SwipeHistoryEnum> swipeHistory;

  public:
  User(string userId, Profile* profile, Preferences* preferences, Location* location, NotificationObserver* notificationObserver) {
    this->userId = userId;
    this->profile = profile;
    this->preferences = preferences;
    this->location = location;
    this->notificationObserver = notificationObserver;
  }

  ~User() {
    delete profile;
    delete preferences;
    delete location;
    // notificationObserver is owned by NotificationService, not this User
  }

  string getUserId() {
    return userId;
  }

  Profile* getProfile() {
    return profile;
  }

  Preferences* getPreferences() {
    return preferences;
  }

  Location* getLocation() {
    return location;
  }

  void displayProfile() {
    cout<<endl<<"----- "<<profile->getName()<<"'s profile -----"<<endl;
    cout<<"age: "<<profile->getAge()<<endl;
    cout<<"interests: ";
    for (auto interest: profile->getInterests()) {
      cout<<interest->getName()<<" ";
    }
    cout<<endl;
  }

  void swipe(User* otherUser, SwipeHistoryEnum direction) {
    swipeHistory[otherUser->getUserId()] = direction;
    cout<<endl<<userId<<" swiped "<<(direction == RIGHT ? "right" : "left")
        <<" on "<<otherUser->getUserId()<<endl;
    if (direction == RIGHT && notificationObserver != nullptr) {
      notificationObserver->update(otherUser->getUserId() + " swiped right on you!");
    }
  }

  bool hasSwiped(string otherUserId) {
    return swipeHistory.count(otherUserId) > 0;
  }

  // caller should check hasSwiped() first
  SwipeHistoryEnum getSwipeDirection(string otherUserId) {
    return swipeHistory[otherUserId];
  }

  vector<Profile*> listAllProfilesNearby(vector<User*> allUsers) {
    vector<Profile*> nearby;
    for (auto other: allUsers) {
      if (other->getUserId() == userId || hasSwiped(other->getUserId())) {
        continue;
      }
      double distance = location->calculateDistance(other->getLocation());
      int otherAge = other->getProfile()->getAge();
      if (distance <= preferences->getMaxDistance()
          && otherAge >= preferences->getMinAge()
          && otherAge <= preferences->getMaxAge()) {
        nearby.push_back(other->getProfile());
      }
    }
    return nearby;
  }
};
class Mather {
  // the following class is a matcher stratergy that claculates the score of the user based on interest and return the matscore to the user
  // this ofllows a ChainOfresponsibility principle where there are 3 items in a chain:
  // BasicMatcherStratergy
  // locationStrategy
  // INterestStrategy

  // the flow goes like his: the 3 strategies imherit the current matcher class and has a reference of the nect in chain classs to calculate the score.
  // fglow is Locartion matcher has a reference of InterestMatcher interestMatcher has a BasicInterestMarcher class reference.
  // basicMatcher class is end of chain

  protected:
  Mather* nextMatcher;

  public:
  Mather() {
    nextMatcher = nullptr;
  }
  virtual ~Mather() {
    delete nextMatcher;
  }
  // works off the actual users (rather than bare userIds) since scoring needs
  // their location/profile/preferences, which aren't recoverable from an id alone
  virtual double calculateScore(User* user1, User* user2) = 0;
};

// end of chain: every pair starts with a flat baseline compatibility score
class BasicMatcherStrategy: public Mather {
  public:
  double calculateScore(User* user1, User* user2) override {
    double score = 10.0;
    cout<<endl<<"BasicMatcherStrategy: base score "<<score<<endl;
    return score;
  }
};

class InterestMatcherStrategy: public Mather {
  public:
  InterestMatcherStrategy(Mather* next) {
    nextMatcher = next;
  }

  double calculateScore(User* user1, User* user2) override {
    double score = nextMatcher != nullptr ? nextMatcher->calculateScore(user1, user2) : 0;

    vector<Interest*> interests1 = user1->getProfile()->getInterests();
    vector<Interest*> interests2 = user2->getProfile()->getInterests();

    int commonInterests = 0;
    for (auto interest1: interests1) {
      for (auto interest2: interests2) {
        if (interest1->getName() == interest2->getName()) {
          commonInterests++;
          break;
        }
      }
    }

    double interestScore = commonInterests * 5.0;
    cout<<endl<<"InterestMatcherStrategy: +"<<interestScore<<" for "<<commonInterests<<" common interest(s)"<<endl;
    return score + interestScore;
  }
};

class LocationMatcherStrategy: public Mather {
  public:
  LocationMatcherStrategy(Mather* next) {
    nextMatcher = next;
  }

  double calculateScore(User* user1, User* user2) override {
    double score = nextMatcher != nullptr ? nextMatcher->calculateScore(user1, user2) : 0;

    double distance = user1->getLocation()->calculateDistance(user2->getLocation());
    double locationScore = distance <= user1->getPreferences()->getMaxDistance() ? 20.0 : 0.0;
    cout<<endl<<"LocationMatcherStrategy: +"<<locationScore<<" for "<<distance<<" km apart"<<endl;
    return score + locationScore;
  }
};

// Facade: single entry point that wires together NotificationService, User,
// Preferences, Profile, Location and the Mather chain so callers never touch
// those classes directly.
class Tinder {
  private:
  map<string, User*> users;
  Mather* matcherChain;
  static Tinder* instance;

  Tinder() {
    matcherChain = new LocationMatcherStrategy(new InterestMatcherStrategy(new BasicMatcherStrategy()));
  }

  User* getUser(string userId) {
    if (users.count(userId) == 0) {
      cout<<endl<<"no user found with id "<<userId<<"....."<<endl;
      return nullptr;
    }
    return users[userId];
  }

  public:
  Tinder(const Tinder&) = delete;
  Tinder& operator=(const Tinder&) = delete;

  static Tinder* getInstance() {
    if (instance == nullptr) {
      instance = new Tinder();
    }
    return instance;
  }

  ~Tinder() {
    delete matcherChain;
    for (auto it: users) {
      delete it.second;
    }
  }

  bool registerUser(string userId, string name, int age, GENDER preferredGenderInterest,
                     double latitude, double longitude,
                     int minAge, int maxAge, double maxDistance) {
    if (users.count(userId)) {
      cout<<endl<<"user "<<userId<<" already exists....."<<endl;
      return false;
    }

    Profile* profile = new Profile(name, age, preferredGenderInterest);
    Preferences* preferences = new Preferences(minAge, maxAge, maxDistance);
    Location* location = new Location(latitude, longitude);
    NotificationObserver* observer = new UserNotificationObserver(userId);

    users[userId] = new User(userId, profile, preferences, location, observer);
    NotificationService::getInstance()->addnewObserver(userId, observer);

    cout<<endl<<"user "<<userId<<" ("<<name<<") registered successfully"<<endl;
    return true;
  }

  void addInterest(string userId, string interestName, string interestDescription) {
    User* user = getUser(userId);
    if (user == nullptr) {
      return;
    }
    user->getProfile()->updateInsterest(new Interest(interestName, interestDescription));
  }

  void displayProfile(string userId) {
    User* user = getUser(userId);
    if (user == nullptr) {
      return;
    }
    user->displayProfile();
  }

  vector<Profile*> getNearbyProfiles(string userId) {
    User* user = getUser(userId);
    if (user == nullptr) {
      return {};
    }
    vector<User*> allUsers;
    for (auto it: users) {
      allUsers.push_back(it.second);
    }
    return user->listAllProfilesNearby(allUsers);
  }

  double getMatchScore(string userId, string otherUserId) {
    User* user1 = getUser(userId);
    User* user2 = getUser(otherUserId);
    if (user1 == nullptr || user2 == nullptr) {
      return 0;
    }
    return matcherChain->calculateScore(user1, user2);
  }

  // returns true if this swipe completes a mutual right-swipe (a match)
  bool swipe(string userId, string otherUserId, SwipeHistoryEnum direction) {
    User* user1 = getUser(userId);
    User* user2 = getUser(otherUserId);
    if (user1 == nullptr || user2 == nullptr) {
      return false;
    }

    user1->swipe(user2, direction);

    bool isMatch = direction == RIGHT
        && user2->hasSwiped(userId)
        && user2->getSwipeDirection(userId) == RIGHT;

    if (isMatch) {
      cout<<endl<<"----- it's a match between "<<userId<<" and "<<otherUserId<<"! -----"<<endl;
      NotificationService::getInstance()->notifyuser(userId, "you matched with "+otherUserId+"!");
      NotificationService::getInstance()->notifyuser(otherUserId, "you matched with "+userId+"!");
    }

    return isMatch;
  }

  void broadcastNotification(string message) {
    NotificationService::getInstance()->notifyAllusers(message);
  }
};

Tinder* Tinder::instance = nullptr;

int main () {
  Tinder* tinder = Tinder::getInstance();

  tinder->registerUser("u1", "Utsav", 27, FEMALE, 12.9352, 77.6146, 22, 30, 10.0);
  tinder->registerUser("u2", "Ananya", 26, MALE, 12.9698, 77.7500, 22, 32, 15.0);
  tinder->registerUser("u3", "Rahul", 29, MALE, 19.0760, 72.8777, 25, 35, 10.0);

  tinder->addInterest("u1", "Hiking", "Weekend trails");
  tinder->addInterest("u1", "Coffee", "Trying new roasts");
  tinder->addInterest("u2", "Hiking", "Mountains over malls");
  tinder->addInterest("u2", "Reading", "Sci-fi novels");

  tinder->displayProfile("u1");
  tinder->displayProfile("u2");

  cout<<endl<<"----- profiles near u1 -----"<<endl;
  for (auto profile: tinder->getNearbyProfiles("u1")) {
    cout<<"  "<<profile->getName()<<endl;
  }

  cout<<endl<<"----- match score u1 <-> u2 -----"<<endl;
  double score = tinder->getMatchScore("u1", "u2");
  cout<<endl<<"total match score: "<<score<<endl;

  cout<<endl<<"----- swiping -----"<<endl;
  tinder->swipe("u1", "u2", RIGHT);
  bool matched = tinder->swipe("u2", "u1", RIGHT);
  cout<<endl<<"matched: "<<(matched ? "yes" : "no")<<endl;

  delete tinder;

  return 0;
}