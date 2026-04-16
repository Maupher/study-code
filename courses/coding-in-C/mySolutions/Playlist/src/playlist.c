#include <stdlib.h>
#include "../inlude/Playlist.h"

//Function to create a PlayList
void Playlist_create(Playlist* p_self, char Playlist_name, char created_by, time_t timestamp)
{
    if (p_self == NULL) return;
    p_self = calloc(1, sizeof(Playlist));

    if (created_by == NULL) return;
    if (Playlist_name == NULL) return;
    if (timestamp == NULL) return;

    p_self->Playlist_name = Playlist_name;
    p_self->created_by = created_by;
    p_self->timestamp = timestamp;
    p_self->playlist_name = 0;
    p_self->total_playtime = 0;

    p_self->p_head = NULL;
    p_self->p_tail = NULL;

    return;
}

//Funktion for creating a Song
void Song_create(Song* p_self, const Playlist* p_playlist, char name, char artist, uint16_t playtime, time_t timestamp)
{
    if (p_self == NULL) return;
    p_self = calloc(1, sizeof(Song));

    if (p_playlist == NULL) return;
    if (artist == NULL) return;
    if (name == NULL) return;
    if (timestamp == NULL) return;
    if (playtime == 0) return;

    p_self->name = name;
    p_self->artist = artist;
    p_self->playtime = playtime;
    p_self->timestamp = timestamp;
    p_self->p_playlist->total_playtime += playtime;

    if (p_self->p_playlist->p_head == NULL)
    {
        p_self->p_playlist->p_head = p_self;
    }
    if (p_self->p_playlist->p_tail == NULL)
    {
        p_self->p_prev = p_self->p_playlist->p_head;
        p_self->p_playlist->p_head->p_next = p_self;
        p_self->p_playlist->p_tail = p_self;
    }
    else
    {
        p_self->p_playlist->p_tail->p_next = p_self;
        p_self->p_prev = p_self->p_playlist->p_tail;
        p_self->p_playlist->p_tail = p_self;
    }



};

//add Function for adding to Playlist
int Song_add(const Playlist* p_playlist, Song* p_song)
{

};

//get an Song by its ID
Song* Song_get_by_id(const Playlist* p_playlist, uint16_t id)
{

};

//get an Song by it's name
Song* Song_get_by_name(const Playlist* p_playlist, char name)
{

};

//get an Song by thr artist
Song* Song_get_by_artist(const Playlist* p_playlist, char Artist)
{

};

//Deleting and freeing Song
int Song_delete(const Playlist* p_playlist, Song* p_song)
{

};

//Free Playlist
int Playlist_delete(Playlist* playlist)
{

};
