#include<iostream>
#include"../models/playlist.hpp"
#include "./PlayStrategies.hpp"

class SequentialPlayStrategy: public PlayStrategy {
  private:
  Playlist* currentPlaylist;
  int currentIndex;
  public:
  SequentialPlayStrategy () {
    currentPlaylist = nullptr;
    currentIndex = -1;
  }

  void setPlaylist(Playlist* playlist) {
    currentPlaylist = playlist;
    currentIndex = -1;
  }
  bool hasNext() override {
    return ((currentIndex+1) < currentPlaylist->getSizeOfPlaylist());
  }

  Song* next() override{
    if (hasNext) {
      currentIndex +=1;
      return currentPlaylist->getPlaylist()[currentIndex];
    }
    else {
      cout<<endl<<"No songs in the playlist"<<endl;
    }
  }

  bool hasPrevious() override {
    return currentIndex -1 >= 0;
  }

  Song* previous() {
    if (hasPrevious) {
      currentIndex -=1;
      return currentPlaylist->getPlaylist()[currentIndex];
    } else {
      cout<<endl<<"No previous song in playlist."<<endl;
    }
  }
};