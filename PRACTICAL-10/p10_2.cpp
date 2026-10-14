#include <iostream>
#include <vector>

using namespace std;

struct BookNode {
    int bookCode;
    BookNode* next;

    BookNode(int code) {
        bookCode = code;
        next = nullptr;
    }
};

void placeBook(vector<BookNode*>& shelves, int code) {
    int shelfIndex = code % 10;
    BookNode* newBook = new BookNode(code);

    if (shelves[shelfIndex] == nullptr) {
        shelves[shelfIndex] = newBook;
    } else {
        BookNode* temp = shelves[shelfIndex];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

int main() {
    int totalShelves = 10;
    vector<BookNode*> libraryShelves(totalShelves, nullptr);

    int arrivingBooks[] = {105, 234, 452, 1052, 314, 789, 50, 990, 615, 87};
    int totalBooks = sizeof(arrivingBooks) / sizeof(arrivingBooks[0]);

    cout << "========================================\n";
    cout << "    LIBRARY BOOK SHELVING SYSTEM       \n";
    cout << "========================================\n\n";

    cout << "Incoming Book Codes:\n";
    for (int i = 0; i < totalBooks; i++) {
        cout << arrivingBooks[i] << " ";
        placeBook(libraryShelves, arrivingBooks[i]);
    }
    cout << "\n\n";

    cout << "Final Books Arrangement by Shelf:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < totalShelves; i++) {
        cout << "Shelf [" << i << "] : ";
        if (libraryShelves[i] == nullptr) {
            cout << "EMPTY\n";
        } else {
            BookNode* temp = libraryShelves[i];
            while (temp != nullptr) {
                cout << temp->bookCode;
                if (temp->next != nullptr) {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << "\n";
        }
    }
    cout << "========================================\n";

    return 0;
}