#include<iostream>
#include"../models/song.hpp"

using namespace std;

class BluetoothDeviceAPI {
  public:
  void playAudio(Song* newSong) {
    cout<<endl<<"new SOng is playing via the bluetooth device"<<endl;
    return;
  }
};