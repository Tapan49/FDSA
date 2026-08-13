#include <iostream>
#include <string>
using namespace std;

int recursiveSearch(string plates[], int n, string target, int index){
    if(index >= n){
        return -1;
    }

    if(plates[index] == target){
        return index;
    }

    return recursiveSearch(plates, n, target, index + 1);
}

int main(){
    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    string plates[n];

    cout << "Enter license plates:" << endl;

    for(int i = 0; i < n; i++){
        cin >> plates[i];
    }

    string target;

    cout << "Enter license plate to search: ";
    cin >> target;

    int position = recursiveSearch(plates, n, target, 0);

    if(position == -1){
        cout << "License plate not found." << endl;
    }
    else{
        cout << "License plate found at position " << position + 1 << endl;
    }

    return 0;
}