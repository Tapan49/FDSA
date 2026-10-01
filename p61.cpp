#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }


    bool isFull() {
        return topIndex == capacity - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void place(int trayId) {
        if (isFull()) {
            cout << "Error: Stack is full. Cannot place tray " << trayId << ".\n";
            return;
        }
        topIndex++;
        arr[topIndex] = trayId;
        cout << "Placed tray " << trayId << ". Current top: " << arr[topIndex] << "\n";
    }

    void take() {
        if (isEmpty()) {
            cout << "Error: Stack is empty. No tray to take.\n";
            return;
        }
        int removedTray = arr[topIndex];
        topIndex--;
        cout << "Took tray " << removedTray << ". ";
        if (isEmpty()) {
            cout << "Counter is now empty.\n";
        } else {
            cout << "Current top: " << arr[topIndex] << "\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter counter capacity: ";
    cin >> n;

    Stack stack(n);

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string op;
        cin >> op;

        if (op == "place") {
            int trayId;
            cin >> trayId;
            stack.place(trayId);
        } else if (op == "take") {
            stack.take();
        } else {
            cout << "Invalid operation.\n";
        }
    }

    return 0;
}