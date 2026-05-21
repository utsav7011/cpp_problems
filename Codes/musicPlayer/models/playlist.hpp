#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"song.hpp"

using namespace std;

class Playlist {
  private:
  string playlistName;
  vector<Song*> songsList;

  public:
  Playlist(string nameP) {
    playlistName = nameP;
  }

  string getPlaylistName () {
    return playlistName;
  }

  void addSongToPlaylist(Song* newSong) {
    if (newSong == nullptr) {
      cout<<endl<<"Error Adding New Song, Song referrence is not passed !!!"<<endl;
      return;
    }
    songsList.push_back(newSong);
    cout<<endl<<"Song aded to the playlist";
    return;
  }

  vector<Song*> getPlaylist() {
    return songsList;
  }

  int getSizeOfPlaylist() {
    return songsList.size();
  }

};
