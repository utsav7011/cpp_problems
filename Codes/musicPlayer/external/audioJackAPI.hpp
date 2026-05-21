#include<iostream>
#include"../models/song.hpp"
#include<string>

class AudioJackAPI {
  public:
  void playAudio (Song* song) {
    cout<<endl<<"Playing song via the audio jack"<<endl;
    cout<<song->getArtist();
    cout<<endl<<song->getTitle();
    return;
  }
};