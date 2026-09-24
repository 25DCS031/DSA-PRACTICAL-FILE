#include <iostream>
#include <string>
using namespace std;

struct SNode {
    string name;
    SNode* next;

    SNode(string n) {
        name = n;
        next = NULL;
    }
};

class SinglyCircular {
private:
    SNode* head;

public:
    SinglyCircular() {
        head = NULL;
    }

    void join(string name) {
        SNode* newNode = new SNode(name);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        SNode* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }


    void joinAfter(string student, string name) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }

        SNode* temp = head;

        do {
            if (temp->name == student) {
                SNode* newNode = new SNode(name);

                newNode->next = temp->next;
                temp->next = newNode;

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << student << " not found." << endl;
    }

    void leave(string name) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }

        SNode* current = head;
        SNode* previous = NULL;

    
        if (head->next == head) {
            if (head->name == name) {
                delete head;
                head = NULL;
            }
            return;
        }


        if (head->name == name) {
            SNode* last = head;

            while (last->next != head) {
                last = last->next;
            }

            SNode* temp = head;
            head = head->next;

            last->next = head;

            delete temp;
            return;
        }

    
        previous = head;
        current = head->next;

        while (current != head) {
            if (current->name == name) {
                previous->next = current->next;
                delete current;
                return;
            }

            previous = current;
            current = current->next;
        }

        cout << name << " not found." << endl;
    }

    void display() {
        cout << "Singly Circular: ";

        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        SNode* temp = head;

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")" << endl;
    }
};


struct DNode {
    string name;
    DNode* prev;
    DNode* next;

    DNode(string n) {
        name = n;
        prev = NULL;
        next = NULL;
    }
};

class DoublyCircular {
private:
    DNode* head;

public:
    DoublyCircular() {
        head = NULL;
    }

    void join(string name) {
        DNode* newNode = new DNode(name);

        if (head == NULL) {
            head = newNode;

            newNode->next = head;
            newNode->prev = head;

            return;
        }

        DNode* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }


    void joinAfter(string student, string name) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }

        DNode* current = head;

        do {
            if (current->name == student) {
                DNode* newNode = new DNode(name);

                newNode->next = current->next;
                newNode->prev = current;

                current->next->prev = newNode;
                current->next = newNode;

                return;
            }

            current = current->next;

        } while (current != head);

        cout << student << " not found." << endl;
    }


    void leave(string name) {
        if (head == NULL) {
            cout << "Circle is empty." << endl;
            return;
        }

        DNode* current = head;


        do {
            if (current->name == name) {
                break;
            }

            current = current->next;

        } while (current != head);

    
        if (current->name != name) {
            cout << name << " not found." << endl;
            return;
        }

    
        if (current->next == current) {
            delete current;
            head = NULL;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head) {
            head = current->next;
        }

        delete current;
    }

    void display() {
        cout << "Doubly Circular: ";

        if (head == NULL) {
            cout << "Empty" << endl;
            return;
        }

        DNode* temp = head;

        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to " << head->name << ")" << endl;
    }
};


int main() {

    SinglyCircular s;
    DoublyCircular d;

    cout << "===== SINGLY CIRCULAR LINKED LIST =====" << endl;

    s.join("Alice");
    s.display();

    s.join("Bob");
    s.display();

    s.join("Charlie");
    s.display();

    s.joinAfter("Bob", "David");
    s.display();

    s.leave("Alice");
    s.display();

    s.leave("Charlie");
    s.display();


    cout << endl;
    cout << "===== DOUBLY CIRCULAR LINKED LIST =====" << endl;

    d.join("Alice");
    d.display();

    d.join("Bob");
    d.display();

    d.join("Charlie");
    d.display();

    d.joinAfter("Bob", "David");
    d.display();

    d.leave("Alice");
    d.display();

    d.leave("Charlie");
    d.display();

    return 0;
}

