#include <iostream>
using namespace std;

int main() {
    int n, choice = 0;

    cout << "Enter number of books in library: ";
    cin >> n;

    int arr1[n], arr2[n];

    cout << "Enter Book IDs in ascending order:\n";
    for(int i = 0; i < n; i++){
        cin >> arr1[i];
        arr2[i] = 0;
    }

    while(choice != 2){
        cout << "\n===== Library Menu =====\n";
        cout << "1. Issue Book\n";
        cout << "2. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                int id;
                cout << "Enter Book ID: ";
                cin >> id;

                int low = 0;
                int high = n - 1;
                bool found = false;

                while(low <= high){
                    int mid = (low + high) / 2;

                    if(arr1[mid] == id){
                        arr2[mid]++;
                        cout << "Book Issued Successfully.\n";
                        found = true;
                        break;
                    }
                    else if(id < arr1[mid]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }

                if(!found){
                    cout << "Book ID not found.\n";
                }

                break;
            }

            case 2: {
                cout << "\n===== End of Month Report =====\n";
                cout << "Books borrowed more than once:\n";

                bool repeated = false;

                for(int i = 0; i < n; i++){
                    if(arr2[i] > 1){
                        cout << "Book ID " << arr1[i]
                             << " -> Borrowed "
                             << arr2[i]
                             << " times\n";
                        repeated = true;
                    }
                }

                if(!repeated){
                    cout << "No book was borrowed more than once.\n";
                }

                cout << "\nThank You!\n";
                break;
            }

            default: {
                cout << "Invalid Choice!\n";
            }
        }
    }

    return 0;
}