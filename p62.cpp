#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }


    bool isEmpty() {
        return top == NULL;
    }

    void visit(string url) {
        Node* newNode = new Node();
        newNode->url = url;
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << top->url << ". Current page: " << top->url << "\n";
    }

    void back() {
        if (isEmpty()) {
            cout << "Error: No history to go back to.\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;

        if (isEmpty()) {
            cout << "Went back. History is now empty.\n";
        } else {
            cout << "Went back. Current page: " << top->url << "\n";
        }
    }
};

int main() {
    Stack history;

    int operations;
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        string op;
        cin >> op;

        if (op == "visit") {
            string url;
            cin >> url;
            history.visit(url);
        } else if (op == "back") {
            history.back();
        } else {
            cout << "Invalid operation.\n";
        }
    }

    return 0;
}