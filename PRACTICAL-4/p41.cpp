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
    int size;

    LL() : head(nullptr), tail(nullptr), size(0) {}

    void insertFirst(int val) {
        Node* node = new Node(val);

        if (head == nullptr) {
          head = node;
          tail = node;
        } 
        else {
          node->next = head;
          head = node;
        }

        size++;
    }

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

        size++;
    }

    void insertAnyPosition(int val, int index) {
        if (index < 0 || index > size) {
          return;
        }

        if (index == 0) {
          insertFirst(val);
          return;
        }

        if (index == size) {
          insertLast(val);
          return;
        }

        Node* node = new Node(val);
        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
          temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;

        size++;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
          cout << temp->val << "->";
          temp = temp->next;
        }

        cout << "null" << endl;
    }
};

int main() {
    LL list;

    list.insertFirst(5);
    list.insertFirst(10);
    list.insertLast(15);
    list.insertAnyPosition(12, 1);

    list.display();

    return 0;
}