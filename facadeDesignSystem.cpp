#include <iostream>
using namespace std;

class PowerSupply
{
public:
  void provodePowerSupply()
  {
    cout << endl
         << "Power Supply Providedd";
  }
};

class CoolingSystem
{
public:
  void porvideCollingSystem()
  {
    cout << endl
         << "Cooliung System is initialized...." << endl;
  }
};

class CPU
{
public:
  void initialize()
  {
    cout << endl
         << "CPU Initializatio  started...." << endl;
  }
};

class Memory
{
public:
  void memoryInitialize()
  {
    cout << endl
         << "Memory initial;ized" << endl;
  }
};

class HardDrive
{
public:
  void spinHardDrive()
  {
    cout << endl
         << "HDD Spinning Started...." << endl;
  }
};

class BIOS
{
  CPU *cpu;
  Memory *mem;

public:
  BIOS(CPU *cpu, Memory *mem)
  {
    cout << endl
         << "BIOS Is running...." << endl;
    this->mem = mem;
    this->cpu = cpu;
  }

  void biosEnable()
  {
    cpu->initialize();
    mem->memoryInitialize();
    cout << endl
         << "Everything in place, runnning....." << endl;
  }
};

class OperatingSystem
{
public:
  OperatingSystem()
  {
    cout << endl
         << "INitializing the Operating SYstem....";
  }
  void loadOS()
  {
    cout << endl
         << "Operating Suystem loading...." << endl;
  }
};

class ComputerFacade
{

  CPU cpu;
  OperatingSystem os;
  BIOS bios;
  Memory mem;
  HardDrive hdd;
  CoolingSystem coolingSystem;
  PowerSupply powerSupply;

public:

  void startComputer()
  {
    powerSupply.provodePowerSupply();
    coolingSystem.porvideCollingSystem();
    mem.memoryInitialize();
    cpu.initialize();
    bios.biosEnable();
    os.loadOS();
    cout << endl
         << "Computer is loaded successfullly" << endl;
  }
};

int main()
{
  ComputerFacade* facadeObj;
  facadeObj->startComputer();
}