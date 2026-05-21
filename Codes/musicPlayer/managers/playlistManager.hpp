#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "../models/playlist.hpp"
#include "../models/song.hpp"

using namespace std;

class PlaylistManager {
  private:
  static PlaylistManager* instance;
  map<string, Playlist*> playlists;
  PlaylistManager() {}
  public:
  static PlaylistManager* getInstance() {
    if (!instance) {
      instance = new PlaylistManager();
      return instance;
    }
    return instance;
  }
  void createPlaylist(string name) {
    if (playlists[name]) {
      cout<<endl<<"Playlist with the given name already exisits"<<endl;
    }
    playlists[name] = new Playlist(name);
  }

  void addSongsToPlaylist(string name, Song* song) {
    if (!playlists.count(name)) {
      cout<<endl<<"No playlist with the given name found..."<<endl;
      return;
    }
    playlists[name]->addSongToPlaylist(song);
  }

  Playlist* getPlaylist(string name) {
    if (!playlists.count(name)) {
      cout<<endl<<"Error finding the playlist"<<endl;
      return;
    }

    return playlists[name];

  }
};

PlaylistManager* PlaylistManager::instance = nullptr;