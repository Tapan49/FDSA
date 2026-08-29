#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

class LL {
public:
    Node* head;
    Node* tail;

    LL() : head(nullptr), tail(nullptr) {}

    void insertLast(int val) {
        Node* node = new Node(val);

        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

    void deleteValue(int val) {
        if (head == nullptr)
            return;

        if (head->val == val) {
            Node* temp = head;
            head = head->next;

            if (head == nullptr)
                tail = nullptr;

            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            if (temp->next->val == val) {
                Node* del = temp->next;
                temp->next = del->next;

                if (del == tail)
                    tail = temp;

                delete del;
                return;
            }

            temp = temp->next;
        }
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }

        cout << "null" << endl;
    }

    void reverseDisplay(Node* temp) {
        if (temp == nullptr)
            return;

        reverseDisplay(temp->next);
        cout << temp->val << "->";
    }

    void reversePrint() {
        reverseDisplay(head);
        cout << "null" << endl;
    }
};

int main() {
    LL list;

    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);
    list.insertLast(50);

    cout << "Forward Queue: ";
    list.display();

    list.deleteValue(30);

    cout << "After Deletion: ";
    list.display();

    cout << "Reverse Queue: ";
    list.reversePrint();

    return 0;
}