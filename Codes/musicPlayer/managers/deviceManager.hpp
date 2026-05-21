#include<iostream>
#include"../devices/IAudioOutputDevice.hpp"
#include"../enums/deviceType.hpp"
#include"../factories/DeviceFactory.hpp"
using namespace std;

class DeviceManager {
  private:
  static DeviceManager* instance;
  IAudioOutputDevice* currentOutputDevice;
  DeviceManager() {
    instance = nullptr;
  } 
  public:
    static DeviceManager* getinstance () {
      if (instance != nullptr) return instance;
      return new DeviceManager();
    } 
    void connect(DeviceType deviceType) {
      if (currentOutputDevice) {
        delete currentOutputDevice;
      }
      currentOutputDevice = DeviceFactory::createDevice(deviceType);
      switch (deviceType) {
        case DeviceType::BLUETOOTH:
          cout<<endl<<"Bluetooth device connected"<<endl;
          break;
        case DeviceType::HEADPHONES:
          cout<<endl<<"Headphones connected"<<endl;
          break;
        case DeviceType::WIRED:
          cout<<endl<<"Wired earphones connected"<<endl;
          break;
      }
    }

    IAudioOutputDevice* getOutputDevice() {
      if (!currentOutputDevice) {
        cout<<endl<<"No output device connected"<<endl;
        return;
      }
      return currentOutputDevice;
    }

    bool hgasOutputDevice() {
      return currentOutputDevice == nullptr;
    }
};

DeviceManager* DeviceManager:: instance = nullptr;