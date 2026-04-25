#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

/***
 * 
 * Observer design pattern:
 * 2objects,
 * objects need to know when it changed and /. or what changed in the object.
 * whenever the object changes, it tells other objects about the change,
 * 
 */

class ISubscribers;  // forward declaration

class IChannel {
  public:
  virtual void subscribe(ISubscribers* subscriber) = 0;
  virtual void unSubscribe(ISubscribers* subscriber) = 0;
  virtual void notify () = 0;
  virtual ~IChannel () {}
};

class ISubscribers{
  public:
  virtual void update() = 0;
  virtual ~ISubscribers() {}
};


class Channel: public IChannel {
  vector<ISubscribers*> subscribersList;
  string name;
  string latestVideo;
  public:
  Channel(const string& name) {
    this->name = name;
  }

  void subscribe(ISubscribers* newSubscriber)  override {
    if (find(subscribersList.begin(), subscribersList.end(), newSubscriber) == subscribersList.end()) {
      subscribersList.push_back(newSubscriber);
    } else {
      cout<<endl<<"Subscriber already presnet"<<endl;
      return;
    }
  }

  void unSubscribe(ISubscribers* subscriber) override{
    if (find(subscribersList.begin(), subscribersList.end(), subscriber) == subscribersList.end()) {
      cout<<endl<<"Subscriber details not presnet."<<endl;
    } else {
      auto it = find(subscribersList.begin(), subscribersList.end(), subscriber);
      if (it != subscribersList.end()) {
        subscribersList.erase(it);
      }
    }
  }

  void notify() override {
    for (auto it: subscribersList) {
      it->update();
    }
  }

  void uploadVideo(const string& title ) {
    latestVideo = title;
    cout<<endl<<"Vidoe uploaded |||| Notifiy subscribers"<<endl;
    notify(); 
  }

  string getVideo() {
    return "\n checkout new video " + latestVideo + "\n";
  }
};

class Subscriber: public ISubscribers {
  string name;
  Channel* channel;
  public:
  Subscriber (const string& name,  Channel* channel) {
    this->name = name;
    this->channel = channel;
  } 

  void update() override {
    cout<<endl<<channel->getVideo();
  }
};

int main () {
  Channel* newChannel = new Channel("newChannel");
  Subscriber* subs1 = new Subscriber("name1",  newChannel);
  Subscriber* subs2 = new Subscriber("newName", newChannel);

  newChannel->subscribe(subs1);
  newChannel->subscribe(subs2);

  newChannel->uploadVideo("newVideo");

  newChannel->uploadVideo("newVideo2");

}