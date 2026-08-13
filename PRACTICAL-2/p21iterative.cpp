#include <iostream>
#include <string>
using namespace std;

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

    int position = -1;

    for(int i = 0; i < n; i++){
        if(plates[i] == target)
        {
            position = i;
            break;
        }
    }

    if(position == -1){
        cout << "License plate not found." << endl;
    }
    else{
        cout << "License plate found at position " << position + 1 << endl;
    }

    return 0;
}