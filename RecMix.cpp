
#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Media {
protected:
    string title;
    string creator;
    int duration;

public:
    Media(string t, string c, int d)
        : title(t), creator(c), duration(d) {}

    virtual ~Media() {}

    string getTitle() const {
        return title;
    }

    virtual void displayInfo() const = 0;
    virtual void play() const = 0;
};

// Derived Class: Song
class Song : public Media {
private:
    string genre;

public:
    Song(string t, string c, int d, string g)
        : Media(t, c, d), genre(g) {}

    void displayInfo() const override {
        cout << "\n[SONG]\n";
        cout << "Title: " << title << endl;
        cout << "Artist: " << creator << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Now playing: " << title << endl;
    }
};

// Derived Class: Podcast
class Podcast : public Media {
private:
    int episodeNumber;

public:
    Podcast(string t, string c, int d, int e)
        : Media(t, c, d), episodeNumber(e) {}

    void displayInfo() const override {
        cout << "\n[PODCAST]\n";
        cout << "Title: " << title << endl;
        cout << "Host: " << creator << endl;
        cout << "Episode: " << episodeNumber << endl;
        cout << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Playing podcast: " << title << endl;
    }
};

// Derived Class: Audiobook
class Audiobook : public Media {
private:
    string narrator;

public:
    Audiobook(string t, string c, int d, string n)
        : Media(t, c, d), narrator(n) {}

    void displayInfo() const override {
        cout << "\n[AUDIOBOOK]\n";
        cout << "Title: " << title << endl;
        cout << "Author: " << creator << endl;
        cout << "Narrator: " << narrator << endl;
        cout << "Duration: " << duration << " seconds\n";
    }

    void play() const override {
        cout << "Playing audiobook: " << title << endl;
    }
};

// Search Function
int searchMedia(
    Media* library[],
    int size,
    const string& target
) {
    for (int i = 0; i < size; i++) {
        if (library[i]->getTitle() == target) {
            return i;
        }
    }

    return -1;
}

int main() {

    const int SIZE = 5;
    Media* library[SIZE] = {};

    // Dynamically create 5 objects
    // Two Songs
    library[0] = new Song(
        "Blinding Lights",
        "The Weeknd",
        200,
        "Synth-pop"
    );

    library[1] = new Song(
        "Levitating",
        "Dua Lipa",
        203,
        "Pop"
    );

    // Two Podcasts
    library[2] = new Podcast(
        "Tech Talk",
        "Alex Morgan",
        1800,
        12
    );

    library[3] = new Podcast(
        "Science Weekly",
        "Jordan Lee",
        2400,
        8
    );

    // One Audiobook
    library[4] = new Audiobook(
        "The Time Machine",
        "H. G. Wells",
        14400,
        "Taylor Brooks"
    );

    cout << "=== RECMIX MEDIA LIBRARY ===\n";

    // Display and play all media items
    for (int i = 0; i < SIZE; i++) {
        library[i]->displayInfo();
        library[i]->play();
    }

    // Search Results
    cout << "\n=== SEARCH RESULTS ===\n";

    // Successful search
    int result = searchMedia(
        library,
        SIZE,
        "Tech Talk"
    );

    if (result != -1) {
        cout << "Found: " << library[result]->getTitle()
             << " at index " << result << endl;
    }
    else {
        cout << "Media not found.\n";
    }

    // Unsuccessful search
    result = searchMedia(
        library,
        SIZE,
        "Unknown Song"
    );

    if (result != -1) {
        cout << "Found: " << library[result]->getTitle()
             << " at index " << result << endl;
    }
    else {
        cout << "Unknown Song was not found.\n";
    }

    // Delete dynamically allocated objects
    for (int i = 0; i < SIZE; i++) {
        delete library[i];
        library[i] = nullptr;
    }

    cout << "\nAll media objects deleted successfully.\n";

    return 0;
}