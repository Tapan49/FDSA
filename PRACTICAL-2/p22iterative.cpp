#include <iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int books[n];

    cout << "Enter sorted book codes:" << endl;

    for(int i = 0; i < n; i++){
        cin >> books[i];
    }

    int target;

    cout << "Enter book code to search: ";
    cin >> target;

    int low = 0;
    int high = n - 1;
    int position = -1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(books[mid] == target)
        {
            position = mid;
            break;
        }
        else if(target < books[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(position == -1){
        cout << "Book code not found." << endl;
    }
    else{
        cout << "Book code found at position " << position + 1 << endl;
    }

    return 0;
}