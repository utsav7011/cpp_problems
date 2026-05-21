#include<vector>
#include<string>
#include"../models/song.hpp"
#include"../devices/IAudioOutputDevice.hpp"
#include<iostream>
using namespace std;

class AudioEngine {
  Song* currentSong;
  bool isAudioPaused;
  public:
  AudioEngine() {
    currentSong = nullptr;
    isAudioPaused = false;
  }

  string getCurrentSongTitle() {
    if (currentSong) {
      return currentSong->getTitle();
    }
    return "";
  }
  bool isPaused() {
    return isAudioPaused;
  }

  void play(IAudioOutputDevice* audioOutputDevice, Song* song) {
    if (song == nullptr) {
      cout<<endl<<"No song to play!!!!"<<endl;
      return;
    }
    if (isAudioPaused && currentSong != song) {
      isAudioPaused = false;
      cout<<endl<<currentSong->getTitle()<<" is resuming....";
      audioOutputDevice->playAudio(song);
      return;
    }
    currentSong = song;
    isAudioPaused = false;
  }


  void pause () {
    if (currentSong  == nullptr) {
      cout<<endl<<"No audio to pause"<<endl;
      return;
    }
    if (isAudioPaused) {
      throw runtime_error("Song is already paused...");
    }
    isAudioPaused = true;
    cout<<endl<<"Pausing the song"<<currentSong->getTitle();
  }
};