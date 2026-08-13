#include <iostream>
#include <string>

using namespace std;

int main() {
    string word;
    string longestWord = "";

    cout << "Enter words (type 'END' to stop):" << endl;

    while (cin >> word) {
        if (word == "END") {
            break;
        }

        if (word.length() > longestWord.length()) {
            longestWord = word;
        }
    }

    cout << "Word: " << longestWord << endl;
    cout << "Length: " << longestWord.length() << endl;

    return 0;
}