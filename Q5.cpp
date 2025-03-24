#include <iostream>
#include <vector>
using namespace std;

class Media
{
protected:
    string title, publicationDate, uniqueID, publisher;

public:
    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual ~Media() {}

    virtual void displayInfo() const
    {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }

    void checkOut()
    {
        cout << title << " has been checked out." << endl;
    }

    void returnItem()
    {
        cout << title << " has been returned." << endl;
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
};

class Book : public Media
{
private:
    string author, ISBN;
    int numberOfPages;

public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() const override
    {
        cout << "--- Book Info ---\n";
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }

    string getAuthor() const { return author; }
};

class DVD : public Media
{
private:
    string director;
    int duration;
    double rating;

public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, double rat)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rat) {}

    void displayInfo() const override
    {
        cout << "--- DVD Info ---\n";
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " mins\nRating: " << rating << endl;
    }
};

class CD : public Media
{
private:
    string artist, genre;
    int numberOfTracks;

public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string gen)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override
    {
        cout << "--- CD Info ---\n";
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

void searchMedia(const vector<Media *> &library, string title)
{
    for (const auto &item : library)
    {
        if (item->getTitle() == title)
        {
            item->displayInfo();
        }
    }
}

void searchMedia(const vector<Media *> &library, string author, bool isBook)
{
    if (!isBook)
        return;
    for (const auto &item : library)
    {
        Book *book = dynamic_cast<Book *>(item);
        if (book && book->getAuthor() == author)
        {
            book->displayInfo();
        }
    }
}

void searchMedia(const vector<Media *> &library, int year)
{
    for (const auto &item : library)
    {
        if (stoi(item->getPublicationDate()) == year)
        {
            item->displayInfo();
        }
    }
}

int main()
{
    vector<Media *> library;

    Book b1("The Great Gatsby", "1925", "B101", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD d1("Inception", "2010", "D202", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c1("Thriller", "1982", "C303", "Epic Records", "Michael Jackson", 9, "Pop");

    library.push_back(&b1);
    library.push_back(&d1);
    library.push_back(&c1);

    cout << "\n--- Display Information ---\n";
    for (const auto &item : library)
    {
        item->displayInfo();
        cout << endl;
    }

    return 0;
}
