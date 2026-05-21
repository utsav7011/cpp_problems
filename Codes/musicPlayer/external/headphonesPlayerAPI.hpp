#include<iostream>
#include "../models/song.hpp"
using namespace std;

class HeadphonesPlayerAPI {
  public:
  void playAudio (Song* song) {
    cout<<endl<<"Playing song via the headphones"<<endl;
    cout<<endl<<song->getTitle();
    cout<<endl<<song->getArtist();
  }
};