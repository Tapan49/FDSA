#include <iostream>
#include <string>

using namespace std;

const int MAX_CAPACITY = 5;

class TokenCounter {
private:
    string arr[MAX_CAPACITY];
    int front;
    int rear;
    int count;

public:
    TokenCounter() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isFull() {
        return count == MAX_CAPACITY;
    }

    bool isEmpty() {
        return count == 0;
    }

    void join(string tokenID) {
        if(isFull())
        {
            cout << "Error: Counter is FULL! Cannot issue token '" << tokenID << "'.\n";
            return;
        }

        if(isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_CAPACITY;
        }

        arr[rear] = tokenID;
        count++;
        cout << "Visitor joined with token: " << tokenID << "\n";
    }

    void serve() {
        if(isEmpty())
        {
            cout << "Error: Counter is EMPTY! No visitor to serve.\n";
            return;
        }

        cout << "Served visitor with token: " << arr[front] << "\n";

        if(count == 1)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX_CAPACITY;
        }
        count--;
    }

    void displayFront() {
        if(isEmpty())
        {
            cout << "Current Front Token: [None - Counter Empty]\n";
        }
        else
        {
            cout << "Current Front Token: " << arr[front] << "\n";
        }
    }
};

int main() {
    TokenCounter counter;

    cout << "========================================\n";
    cout << "   TOKEN COUNTER SIMULATION SYSTEM      \n";
    cout << "========================================\n\n";

    cout << "--- 1. Enqueue Operations (Visitors Arriving) ---\n";
    counter.join("A-101");
    counter.displayFront();
    cout << "\n";

    counter.join("B-102");
    counter.displayFront();
    cout << "\n";

    counter.join("C-103");
    counter.displayFront();
    cout << "\n";

    counter.join("D-104");
    counter.join("E-105");
    cout << "\n";

    cout << "--- 2. Overflow Test (Full Capacity) ---\n";
    counter.join("F-106");
    cout << "\n";

    cout << "--- 3. Dequeue Operations (Serving Visitors) ---\n";
    counter.serve();
    counter.displayFront();
    cout << "\n";

    counter.serve();
    counter.displayFront();
    cout << "\n";

    cout << "--- 4. Circular Wrap-around Test ---\n";
    counter.join("G-107");
    counter.displayFront();
    cout << "\n";

    cout << "========================================\n";
    cout << "         SIMULATION COMPLETE            \n";
    cout << "========================================\n";

    return 0;
}