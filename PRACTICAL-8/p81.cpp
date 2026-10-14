#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
    string name;
    Node* left;
    Node* right;

    Node(string val) {
        name = val;
        left = nullptr;
        right = nullptr;
    }
};

void printInOrder(Node* root) {
    if (root == nullptr) return;
    printInOrder(root->left);
    cout << root->name << " -> ";
    printInOrder(root->right);
}

void printPreOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->name << " -> ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(Node* root) {
    if (root == nullptr) return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->name << " -> ";
}

void printLevelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->name << " | ";

        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main() {
    Node* ceo = new Node("Rajesh (CEO)");
    
    Node* techLead = new Node("Amit (Tech Lead)");
    Node* salesLead = new Node("Pooja (Sales Lead)");

    Node* dev1 = new Node("Rohan (Dev)");
    Node* dev2 = new Node("Sneha (Dev)");
    Node* rep1 = new Node("Vikas (Sales)");
    Node* rep2 = new Node("Anjali (Sales)");

    ceo->left = techLead;
    ceo->right = salesLead;

    techLead->left = dev1;
    techLead->right = dev2;

    salesLead->left = rep1;
    salesLead->right = rep2;

    cout << "========================================\n";
    cout << "       COMPANY HIERARCHY REPORTS        \n";
    cout << "========================================\n\n";

    cout << "1. Archive Department (Pre-order):\n";
    printPreOrder(ceo);
    cout << "END\n\n";

    cout << "2. HR Department (In-order):\n";
    printInOrder(ceo);
    cout << "END\n\n";

    cout << "3. Payroll Department (Post-order):\n";
    printPostOrder(ceo);
    cout << "END\n\n";

    cout << "4. Floor Manager (Level-order):\n";
    printLevelOrder(ceo);
    cout << "END\n\n";

    cout << "========================================\n";

    return 0;
}