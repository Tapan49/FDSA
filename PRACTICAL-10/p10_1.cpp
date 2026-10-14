#include <iostream>
#include <vector>

using namespace std;

void parkVehicle(vector<int>& parkingLot, int tableSize, int vehicleNo) {
    int initialSlot = vehicleNo % 10;
    int currentSlot = initialSlot;

    for (int i = 0; i < tableSize; i++) {
        int checkIndex = (currentSlot + i) % tableSize;

        if (parkingLot[checkIndex] == -1) {
            parkingLot[checkIndex] = vehicleNo;
            return;
        }
    }

    cout << "Parking Full! Cannot park vehicle: " << vehicleNo << "\n";
}

int main() {
    int totalSlots = 10;
    vector<int> parkingLot(totalSlots, -1);

    int arrivingVehicles[] = {1243, 4523, 7890, 5634, 9123, 3345, 8760};
    int totalVehicles = sizeof(arrivingVehicles) / sizeof(arrivingVehicles[0]);

    cout << "========================================\n";
    cout << "     SMART PARKING LOT ALLOCATION       \n";
    cout << "========================================\n\n";

    cout << "Incoming Vehicles Queue:\n";
    for (int i = 0; i < totalVehicles; i++) {
        cout << arrivingVehicles[i] << " ";
        parkVehicle(parkingLot, totalSlots, arrivingVehicles[i]);
    }
    cout << "\n\n";

    cout << "Final Parking Slot Allocation Status:\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < totalSlots; i++) {
        cout << "Slot [" << i << "] : ";
        if (parkingLot[i] == -1) {
            cout << "EMPTY\n";
        } else {
            cout << "Vehicle #" << parkingLot[i] << "\n";
        }
    }
    cout << "========================================\n";

    return 0;
}