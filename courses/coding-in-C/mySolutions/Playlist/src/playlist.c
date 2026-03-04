#include <stdlib.h>
#include "../inlude/Playlist.h"

void Playlist_create(char Playlist_name, char created_by, time_t timestamp){
    
};

//Funktion for creating a Song
void Song_create(Playlist* p_playlist, char c_name, char c_artist, uint16_t playtime, time_t timestamp){


};

//add Function for adding to Playlist 
int Song_add(Playlist* p_playlist, Song* p_song){

};

//get an Song by its ID 
Song* Song_get_by_id(Playlist* p_playlist, uint16_t id){

};

//get an Song by it's name
Song* Song_get_by_name(Playlist* p_playlist, char name){

};

//get an Song by thr artist
Song* Song_get_by_artist(Playlist* p_playlist, char Artist){

};

//Deleting and freeing Song
int Song_delete(Playlist* p_playlist, Song* p_song){

};

//Free Playlist 
int Playlist_delete(Playlist* playlist){

};
