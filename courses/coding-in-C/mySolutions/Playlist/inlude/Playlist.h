#include <stdint.h>
#include <time.h>

typedef struct Playlist Playlist;
typedef struct Song Song;


static const uint8_t stdCharLength = 30;

struct Playlist {    
    Song* p_head;
    Song* p_tail;
    uint16_t anz_Songs;
    uint64_t total_playtime; //define in seconds
    char Playlist_name[stdCharlength];
    char created_by[stdCharlength];
    time_t created_time;
};

struct Song{
    Playlist* p_playlist;
    Song* p_prev;
    Song* p_next;

    uint16_t id;
    char c_Song[30];
    char c_artist[30];
    uint16_t playtime; //defined in seconds
};


Playlist* Playlist_create();

//Funktion for creating a Song
Song* Song_create(Playlist* p_playlist, char c_name, char c_artist, uint16_t playtime);
