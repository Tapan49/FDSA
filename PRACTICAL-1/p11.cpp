#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of n : ";
    cin >> n;
    int item[n];
    for(int i = 0 ; i < n ; i++){
      cin >> item[i];
    }

    for(int i = 0 ; i < n ; i++){
      cout << item[i] << " ";
    }
    cout << endl;
    int h;
    cout << "Enter the number of hours : ";
    cin >> h;
    int k = h % n; 

    for(int i = k ; i < n ; i++){
      cout << item[i] << " ";
    }
    for(int i = 0 ; i < k ; i++){
        cout << item[i] << " ";
    }
}