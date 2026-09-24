#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node(string val) {
        name = val;
        next = nullptr;
    }
};

class CLL {
public:
    Node* head;
    int count;

    CLL() {
        head = nullptr;
        count = 0;
    }

    void display() {
        if (head == nullptr) {
            cout << "Circle is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "[Circle: " << count << "] ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->name << ")\n";
    }

    void join(string target, string newStudent) {
        Node* node = new Node(newStudent);
        if (head == nullptr) {
            head = node;
            node->next = head;
            count++;
            display();
            return;
        }
        Node* curr = head;
        while (curr->name != target && curr->next != head) {
            curr = curr->next;
        }
        node->next = curr->next;
        curr->next = node;
        count++;
        display();
    }

    void leave(string studentName) {
        if (head == nullptr) return;
        Node* curr = head;
        Node* prev = nullptr;
        
        if (head->name == studentName) {
            if (head->next == head) {
                delete head;
                head = nullptr;
                count--;
                display();
                return;
            }
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            count--;
            display();
            return;
        }

        do {
            prev = curr;
            curr = curr->next;
        } while (curr != head && curr->name != studentName);

        if (curr != head) {
            prev->next = curr->next;
            delete curr;
            count--;
            display();
        } else {
            cout << studentName << " not found.\n";
        }
    }
};

int main() {
    CLL gameCircle;
    gameCircle.join("", "Alice");
    gameCircle.join("Alice", "Bob");
    gameCircle.join("Bob", "Charlie");
    gameCircle.join("Alice", "David");
    gameCircle.leave("Alice");
    gameCircle.leave("Charlie");

    return 0;
}
