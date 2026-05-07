#include <stdint.h>
#include <time.h>

typedef struct Playlist Playlist;
typedef struct Song Song;


static const uint8_t stdCharLength = 30;
static const uint8_t maxSongs = 500;

struct Playlist {    
    Song* p_head;
    Song* p_tail;
    uint16_t anz_Songs;
    uint64_t total_playtime; //define in seconds
    char Playlist_name[stdCharLength];
    char created_by[stdCharLength];
    time_t created_time;
};

struct Song{
    const Playlist* p_playlist;
    Song* p_prev;
    Song* p_next;

    uint16_t id;
    char name[stdCharLength];
    char artist[stdCharLength];
    uint16_t playtime; //defined in seconds
    time_t timestamp;
};

//Function to create a PlayList
void Playlist_create(Playlist* p_self, char Playlist_name, char created_by, time_t timestamp);

//Funktion for creating a Song
void Song_create(Song* p_self, const Playlist* p_playlist, char c_name, char c_artist, uint16_t playtime, time_t timestamp);

//add Function for adding to Playlist 
int Song_add(const Playlist* p_playlist, Song* p_song);

//get an Song by its ID 
Song* Song_get_by_id(const Playlist* p_playlist, uint16_t id);

//get an Song by it's name
Song* Song_get_by_name(const Playlist* p_playlist, char name);

//get an Song by thr artist
Song* Song_get_by_artist(const Playlist* p_playlist, char Artist);

//Deleting and freeing Song
int Song_delete(const Playlist* p_playlist, Song* p_song);

//Free Playlist 
int Playlist_delete(Playlist* playlist);