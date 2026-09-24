#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;

    Node(string s) {
        song = s;
        prev = NULL;
        next = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;

public:
    Playlist() {
        head = NULL;
        tail = NULL;
    }

    void addBeginning(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        display();
    }

    void addEnd(string song) {
        Node* newNode = new Node(song);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }

        display();
    }

    void insertAfter(string givenSong, string newSong) {
        Node* current = head;

        while (current != NULL && current->song != givenSong) {
            current = current->next;
        }

        // Given song not found
        if (current == NULL) {
            cout << "Song \"" << givenSong << "\" not found." << endl;
            display();
            return;
        }

        Node* newNode = new Node(newSong);

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
    
            tail = newNode;
        }

        current->next = newNode;

        display();
    }

    void removeFirst() {
        if (head == NULL) {
            cout << "Playlist is empty." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }

        delete temp;

        display();
    }

    int countSongs() {
        int count = 0;
        Node* current = head;

        while (current != NULL) {
            count++;
            current = current->next;
        }

        return count;
    }

    void display() {
        Node* current = head;

        cout << "Playlist: ";

        if (current == NULL) {
            cout << "Empty";
        }

        while (current != NULL) {
            cout << current->song;

            if (current->next != NULL)
                cout << " -> ";

            current = current->next;
        }

        cout << endl;
        cout << "Number of songs: " << countSongs() << endl;
        cout << "------------------------" << endl;
    }
};

int main() {
    Playlist p;

    p.addEnd("Song A");
    p.addEnd("Song B");
    p.addBeginning("Song C");

    p.insertAfter("Song A", "Song D");

    p.removeFirst();

    p.insertAfter("Song B", "Song E");

    p.insertAfter("Song X", "Song F");

    return 0;
}
