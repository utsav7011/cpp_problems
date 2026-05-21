#include<iostream>
#include "./IAudioOutputDevice.hpp"
#include "../models/song.hpp"
#include "../external/headphonesPlayerAPI.hpp"

using namespace std;

class HeadphonesAdapter: public IAudioOutputDevice  {
  private:
  HeadphonesPlayerAPI* headphonesPlayerAPI;
  public:
  HeadphonesAdapter (HeadphonesPlayerAPI* api) {
    headphonesPlayerAPI = api;
  }
  void playAudio (Song* song) override {
    headphonesPlayerAPI->playAudio(song);
    cout<<"The song is played via the headphones API"<<endl;
    return;
  }

};