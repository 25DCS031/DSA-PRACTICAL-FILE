#include <iostream>
#include <string>
using namespace std;

class TrayStack {
private:
    string* stack;
    int capacity;
    int top;

public:
    
    TrayStack(int n) {
        capacity = n;
        stack = new string[capacity];
        top = -1;
    }

    void place(string tray) {

        // Check if stack is full
        if (top == capacity - 1) {
            cout << "Error: Stack is FULL. Cannot place "
                 << tray << endl;
            return;
        }

        top++;
        stack[top] = tray;

        cout << "Placed: " << tray << endl;
        displayTop();
    }

    void take() {

        if (top == -1) {
            cout << "Error: Stack is EMPTY. Cannot take tray."
                 << endl;
            return;
        }

        cout << "Taken: " << stack[top] << endl;

        top--;

        displayTop();
    }
    void displayTop() {

        if (top == -1) {
            cout << "Current Top: No trays" << endl;
        } else {
            cout << "Current Top: "
                 << stack[top] << endl;
        }

        cout << "----------------------" << endl;
    }

    ~TrayStack() {
        delete[] stack;
    }
};

int main() {


    TrayStack trays(3);
    trays.place("Tray A");
    trays.place("Tray B");
    trays.place("Tray C");

    trays.place("Tray D");

    trays.take();
    trays.take();
    trays.take();

    trays.take();

    return 0;
}

