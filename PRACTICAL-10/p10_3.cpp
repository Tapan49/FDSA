#include <iostream>
#include <vector>

using namespace std;

int hashFunction1(int studentID, int tableSize) {
    return studentID % tableSize;
}

int hashFunction2(int studentID) {
    return 7 - (studentID % 7);
}

void allocateSlot(vector<int>& storageTable, int tableSize, int studentID) {
    int index = hashFunction1(studentID, tableSize);
    int stepSize = hashFunction2(studentID);

    for (int i = 0; i < tableSize; i++) {
        int probeIndex = (index + i * stepSize) % tableSize;

        if (storageTable[probeIndex] == -1) {
            storageTable[probeIndex] = studentID;
            return;
        }
    }

    cout << "Storage Full! Cannot allocate slot for Student ID: " << studentID << "\n";
}

int main() {
    int totalSlots = 10;
    vector<int> lockerSlots(totalSlots, -1);

    int studentIDs[] = {25013, 18023, 31053, 44023, 19045, 52010, 63018};
    int totalStudents = sizeof(studentIDs) / sizeof(studentIDs[0]);

    cout << "========================================\n";
    cout << "     UNIVERSITY STORAGE ALLOCATION      \n";
    cout << "========================================\n\n";

    cout << "Student ID Queue for Allocation:\n";
    for (int i = 0; i < totalStudents; i++) {
        cout << studentIDs[i] << " ";
        allocateSlot(lockerSlots, totalSlots, studentIDs[i]);
    }
    cout << "\n\n";

    cout << "Final Locker Slot Allocation:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < totalSlots; i++) {
        cout << "Slot [" << i << "] : ";
        if (lockerSlots[i] == -1) {
            cout << "AVAILABLE\n";
        } else {
            cout << "Student ID #" << lockerSlots[i] << "\n";
        }
    }
    cout << "========================================\n";

    return 0;
}