#include<iostream>
using namespace std;

class Animal {
  private:
  int age;
  int weight;
  string name;
  string breed;

  public:
  Animal(int age, int weight, string name, string breed ) {
    this->age = age;
    this->weight = weight;
    this->name = name;
    this->breed = breed;
  }

  void printAnimal() {
    cout<<endl<<"Animal Details: "<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Weight: "<<weight<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Breed: "<<breed<<endl;
  }
};

int main() {

  Animal a(2, 20, "Coco", "Labrador");
  a.printAnimal();

}