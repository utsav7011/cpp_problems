#include<iostream>
#include "Codes/musicPlayer/devices/IAudioOutputDevice.hpp"
#include "../external/bluetoothDeviceAPI.hpp"

using namespace std;



class BluetoothDeviceAdapter: public IAudioOutputDevice {
  private:
  BluetoothDeviceAPI* bluetoothAPI;
  public:
  BluetoothDeviceAdapter (BluetoothDeviceAPI* api) {
    bluetoothAPI = api;
  }

  void playAudio(Song* song) override {
    bluetoothAPI->playAudio(song);
    cout<<"Song sent to bluetooth API to play the audio from the Bluetooth Adapter which inherits the IAudioOutputDevice";
    return;
  }
};