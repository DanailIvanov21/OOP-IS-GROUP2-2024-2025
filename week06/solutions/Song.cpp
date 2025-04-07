#include <iostream>
#include <cstring>
using  std::cout, std::cin;

const int MAX_SONGS = 100;
const int MAX_LENGTH = 100;

struct Song {
private:
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int year;
    int lengthInSeconds;
    Song* original; //  aggregation - not our responsibility to delete

public:
    Song(const char* _title = "", const char* _artist = "", int _year = 0, int _length = 0)
        : year(_year), lengthInSeconds(_length), original(nullptr) 
    {
        strncpy(title, _title, MAX_LENGTH);
        strncpy(artist, _artist, MAX_LENGTH);
    }

    Song(const char* _title, const char* _artist, int _year, int _length, Song* _original)
        : year(_year), lengthInSeconds(_length), original(_original) 
    {
        strncpy(title, _title, MAX_LENGTH);
        strncpy(artist, _artist, MAX_LENGTH);
    }

    const char* getTitle() const 
    {
        return title; 
    }
    const char* getArtist() const 
    { 
        return artist; 
    }
    int getYear() const 
    { 
        return year; 
    }
    int getLength() const 
    { 
        return lengthInSeconds; 
    }
    const Song* getOriginal() const 
    { 
        return original; 
    }
    void setTitle(const char* _title) 
    { 
        strncpy(title, _title, MAX_LENGTH); 
    }
    void setArtist(const char* _artist) 
    { 
        strncpy(artist, _artist, MAX_LENGTH); 
    }
    void setYear(int _year) 
    { 
        year = _year; 
    }
    void setLength(int _length) 
    { 
        lengthInSeconds = _length; 
    }
    void setOriginal(Song* _original) 
    { 
        original = _original; 
    }
    void print() const 
    {
        cout << "Title: " << title << "\n"
            << "Artist: " << artist << "\n"
            << "Year: " << year << "\n"
            << "Length: " << lengthInSeconds << " seconds\n";

        if (original) 
        {
            cout << "Cover of: " << original->getTitle() << " by " << original->getArtist() << "\n";
        }
        cout << "------------------------" << std::endl;
    }
};

struct Album {
private:
    Song songs[MAX_SONGS];
    int songCount;
    char albumName[MAX_LENGTH];

public:
    Album(const char* _name = "") : songCount(0) 
    {
        strncpy(albumName, _name, MAX_LENGTH);
    }

    const char* getName() const 
    { 
        return albumName; 
    }
    int getSongCount() const 
    { 
        return songCount; 
    }

    void setName(const char* _name) 
    { 
        if (!_name)
            return;

        strncpy(albumName, _name, MAX_LENGTH); 
    }

    void addSong(const Song& s) 
    {
        if (songCount < MAX_SONGS) 
        {
            songs[songCount++] = s;
        }

        return;
    }

    void print() const 
    {
        cout << "Album: " << albumName << "\n";

        for (int i = 0; i < songCount; i++) 
        {
            songs[i].print();
        }
    }

    int getLength() const 
    {
        int total = 0;

        for (int i = 0; i < songCount; i++) 
        {
            total += songs[i].getLength();
        }

        return total;
    }

    const char* getArtist() const 
    {
        if (songCount == 0) return "No Artist";
        const char* firstArtist = songs[0].getArtist();
        
        for (int i = 1; i < songCount; i++) 
        {
            if (strcmp(songs[i].getArtist(), firstArtist) != 0) 
            {
                return "Various Artists";
            }
        }
        
        return firstArtist;
    }

    Song* findSong(const char* title) 
    {
        for (int i = 0; i < songCount; i++) 
        {
            if (strcmp(songs[i].getTitle(), title) == 0) {
                return &songs[i];
            }
        }

        return nullptr;
    }
};

int main() {
    Song original("Imagine", "John Lennon", 1971, 183);
    Song cover("Imagine", "A Perfect Circle", 2004, 189, &original);

    Album album("Covers Vol. 1");
    album.addSong(cover);

    album.print();

    cout << "Album length: " << album.getLength() << " seconds\n";
    cout << "Album artist: " << album.getArtist() << "\n";

    Song* found = album.findSong("Imagine");
    
    if (found) 
    {
        cout << "Found song:\n";
        found->print();
    }
    else 
    {
        cout << "Song not found.\n";
    }

    return 0;
}
