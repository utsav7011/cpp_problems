#include<iostream>
using namespace std;

class IImageDisplay{
  public:
  virtual void displayImage() = 0;
};

class ImageDisplay: public IImageDisplay {
  public:
  ImageDisplay() {};
  void displayImage() override {
    cout<<endl<<"in concrete displayImage class function"<<endl;
    cout<<endl<<"This is an expensive calcualtion...."<<endl;
  }
};

class ImageDisplayProxy: public IImageDisplay{
  ImageDisplay* dis;
  public:
  ImageDisplayProxy() {
    this->dis = nullptr;
  }
  public:
  void displayImage() override{
    if (dis == nullptr) {
      dis = new ImageDisplay();
    }
    cout<<endl<<"Calling the displayImage methid in the proxy class"<<endl;
    dis->displayImage();
  }
};

class Client{
  IImageDisplay* dis;
  public:
  Client(ImageDisplayProxy* dis) {
    this->dis = dis;
  };
  void displayIamge () {
    cout<<endl<<"diplay iamge is callled"<<endl;
    dis->displayImage();
  }
};

int main () {
  ImageDisplayProxy* proxy = new ImageDisplayProxy();
  Client* c1 = new Client(proxy);
  c1->displayIamge();
}