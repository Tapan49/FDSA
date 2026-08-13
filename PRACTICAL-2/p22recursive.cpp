#include <iostream>
using namespace std;

int recursiveSearch(int books[], int low, int high, int target){
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    if(books[mid] == target){
        return mid;
    }

    if(target < books[mid]){
        return recursiveSearch(books, low, mid - 1, target); //right 
    }

    return recursiveSearch(books, mid + 1, high, target); //left
}

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

    int position = recursiveSearch(books, 0, n - 1, target);

    if(position == -1){
        cout << "Book code not found." << endl;
    }
    else{
        cout << "Book code found at position " << position + 1 << endl;
    }

    return 0;
}