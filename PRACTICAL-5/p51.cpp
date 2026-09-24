#include<iostream>
using namespace std;

class Node {
public:
    string data;
    Node* prev;
    Node* next;

    Node(string val) {
      data = val;
      prev = nullptr;
      next = nullptr;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;
    int count;

    DLL() {
      head = nullptr;
      tail = nullptr;
      count = 0;
    }

    int getCount() {
      return count;
    }

    void displayList() {
      if(head == nullptr){
        cout << "List is empty.\n";
      }
      Node* temp = head;
      cout << "START ";
      while(temp != nullptr) {
        cout << temp << "->";
        temp = temp->next;
      }
      cout << " END";
    }

    void insertFirst(string val) {
      Node* node = head;
      if(head == nullptr){
        head = node;
        tail = node;
        return;
      }
      else {
        node->next = head;
        head = node;
        node->prev = nullptr;
      }
      count++;
      displayList();
    }

    void insertLast(string val) {
      Node* node = tail;
      if(tail == nullptr) {
        node = tail;
        node = head;
        return;
      }
      else {
        tail->next = node;
        node->prev = tail;
        tail = node;
      }
      count++;
      displayList();
    }

    void insert(string target,string val) {
      Node* curr = head;
      while(curr != nullptr && curr->data != target) {
        curr = curr->next;
      }

      if(curr == nullptr) {
        cout << "Target Title " << target << " not found.\n";
      }

      Node* node = new Node(val);
      curr->next = node;
      node->prev = curr;

      count++;
      displayList();
    }

    void deleteFirst() {
      if(head == nullptr) {
        cout << "The list is empty\n";
        return;
      }
      Node* temp = head;
      head = head->next;
      if(head != nullptr) {
        head->prev = nullptr;
      }
      else {
        tail = nullptr;
      }
      delete temp;
      count--;
      displayList();
    }

    void deleteEnd() {
      if(tail == nullptr) {
        cout << "The list is empty\n";
        return;
      }
      Node*temp = tail;
      tail = tail->prev;
      if(tail != nullptr) {
        tail->next = nullptr;
      }
      else {
        head = nullptr;
      }
      delete temp;
      count--;
      displayList();
    }

};

int main() {

  return 0;
}