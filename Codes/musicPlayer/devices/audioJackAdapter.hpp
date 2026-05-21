#include<iostream>
#include "../models/song.hpp"
#include "../external/audioJackAPI.hpp"
#include"./IAudioOutputDevice.hpp"

class AudioJackAdapter: public  IAudioOutputDevice{
  private:
  AudioJackAPI* audioJackAPI;
  public:
  AudioJackAdapter(AudioJackAPI *api) {
    audioJackAPI = api;
  }

  void playAudio (Song* song) override {
    audioJackAPI->playAudio(song);
    cout<<endl<<"The song is p[layed via the audio jack"<<endl;
    return;
  }

};