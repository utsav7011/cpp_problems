#include<iostream>
#include"../devices/IAudioOutputDevice.hpp"
#include"../devices/bluetoothDeviceAdapter.hpp"
#include"../devices/audioJackAdapter.hpp"
#include"../devices/headphonesAdapter.hpp"
#include"../enums/deviceType.hpp"
using namespace std;


class DeviceFactory {
  public:
  static IAudioOutputDevice* createDevice (DeviceType deviceType) {
    if (deviceType == DeviceType::BLUETOOTH) return new BluetoothDeviceAdapter(new BluetoothDeviceAPI());
    else if (deviceType == DeviceType::HEADPHONES) return new HeadphonesAdapter(new HeadphonesPlayerAPI());
    else if (deviceType == DeviceType::WIRED) return new AudioJackAdapter(new AudioJackAPI());
  }
};