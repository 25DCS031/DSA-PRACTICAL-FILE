#include <iostream>
#include <string>
using namespace std;

struct Node {
    string page;
    Node* next;

    Node(string p) {
        page = p;
        next = NULL;
    }
};

class BrowserHistory {
private:
    Node* top;

public:
    BrowserHistory(string firstPage) {
        top = new Node(firstPage);
    }

    void visit(string page) {
        Node* newNode = new Node(page);

        newNode->next = top;
        top = newNode;

        cout << "Visited: " << page << endl;
        displayCurrent();
    }

    void back() {

        if (top->next == NULL) {
            cout << "Cannot go back. No history left." << endl;
            displayCurrent();
            return;
        }

        Node* temp = top;

        top = top->next;

        delete temp;

        cout << "Back pressed." << endl;
        displayCurrent();
    }

    void displayCurrent() {
        cout << "Current Page: " << top->page << endl;
        cout << "----------------------" << endl;
    }

    ~BrowserHistory() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {

    BrowserHistory browser("Home");

    browser.displayCurrent();

    browser.visit("Google");
    browser.visit("YouTube");
    browser.visit("Wikipedia");

    browser.back();
    browser.back();
    browser.back();

    browser.back();

    return 0;
}

