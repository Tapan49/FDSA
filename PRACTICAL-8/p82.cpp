#include <iostream>

using namespace std;

struct BookNode {
    int bookCode;
    BookNode* left;
    BookNode* right;

    BookNode(int code) {
        bookCode = code;
        left = nullptr;
        right = nullptr;
    }
};

BookNode* insertBook(BookNode* root, int code) {
    if (root == nullptr) {
        return new BookNode(code);
    }

    if (code < root->bookCode) {
        root->left = insertBook(root->left, code);
    } else if (code > root->bookCode) {
        root->right = insertBook(root->right, code);
    }

    return root;
}

void printShelfOrder(BookNode* root) {
    if (root == nullptr) return;
    printShelfOrder(root->left);
    cout << root->bookCode << " -> ";
    printShelfOrder(root->right);
}

int main() {
    BookNode* libraryShelf = nullptr;

    int arrivingBooks[] = {50, 30, 70, 20, 40, 60, 80};
    int totalBooks = sizeof(arrivingBooks) / sizeof(arrivingBooks[0]);

    cout << "========================================\n";
    cout << "      LIBRARY BOOK INTAKE SYSTEM        \n";
    cout << "========================================\n\n";

    cout << "Arriving Book Codes (Sequence of Arrival):\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << arrivingBooks[i] << " ";
        libraryShelf = insertBook(libraryShelf, arrivingBooks[i]);
    }
    cout << "\n\n";

    cout << "Organized Shelf Arrangement (In-order Traversal):\n";
    printShelfOrder(libraryShelf);
    cout << "END\n\n";

    cout << "========================================\n";

    return 0;
}