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
        return;
      }
      Node* temp = head;
      cout << "START ";
      while(temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
      }
      cout << "END\n";
    }

    void insertFirst(string val) {
      Node* node = new Node(val);
      if(head == nullptr){
        head = node;
        tail = node;
      }
      else {
        node->next = head;
        head->prev = node;
        head = node;
      }
      count++;
      displayList();
    }

    void insertLast(string val) {
      Node* node = new Node(val);
      if(tail == nullptr) {
        head = tail = node;
      }
      else {
        tail->next = node;
        node->prev = tail;
        tail = node;
      }
      count++;
      displayList();
    }

    void insert(string target, string val) {
      Node* curr = head;
      while(curr != nullptr && curr->data != target) {
        curr = curr->next;
      }

      if(curr == nullptr) {
        cout << "Target Title " << target << " not found.\n";
        return;
      }

      Node* node = new Node(val);
      
      node->next = curr->next;
      if(curr->next != nullptr) {
        curr->next->prev = node;
      } else {
        tail = node;
      }
      
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
      Node* temp = tail;
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
  DLL playlist;
  playlist.insertFirst("Song A");
  playlist.insertLast("Song B");
  playlist.insertLast("Song C");
  playlist.insertLast("Song D");
  playlist.insertLast("Song E");
  playlist.insert("Song C", "Song F");

  playlist.deleteFirst();
  return 0;
}
