#include <iostream>
#include <string>

using namespace std;

struct PatientNode {
    string name;
    PatientNode* next;

    PatientNode(string n) {
        name = n;
        next = nullptr;
    }
};

class EmergencyWard {
private:
    PatientNode* front;
    PatientNode* rear;

public:
    EmergencyWard() {
        front = nullptr;
        rear = nullptr;
    }

    ~EmergencyWard() {
        while (front != nullptr) {
            PatientNode* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void arrive(string patientName) {
        PatientNode* newPatient = new PatientNode(patientName);
        if (isEmpty()) {
            front = rear = newPatient;
        } else {
            rear->next = newPatient;
            rear = newPatient;
        }
        cout << "Patient arrived: " << patientName << "\n";
    }

    void attend() {
        if (isEmpty()) {
            cout << "Error: No patients waiting in the emergency ward!\n";
            return;
        }

        PatientNode* temp = front;
        cout << "Doctor attending to patient: " << temp->name << "\n";
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    void displayFront() {
        if (isEmpty()) {
            cout << "Current Front Patient: [None - Ward is Empty]\n";
        } else {
            cout << "Current Front Patient: " << front->name << "\n";
        }
    }
};

int main() {
    EmergencyWard ward;

    cout << "========================================\n";
    cout << "   HOSPITAL EMERGENCY WARD SYSTEM       \n";
    cout << "========================================\n\n";

    cout << "--- 1. Initial State Check ---\n";
    ward.displayFront();
    ward.attend();
    cout << "\n";

    cout << "--- 2. Patient Arrivals (Enqueue Operations) ---\n";
    ward.arrive("Rahul Sharma");
    ward.displayFront();
    cout << "\n";

    ward.arrive("Priya Patel");
    ward.displayFront();
    cout << "\n";

    ward.arrive("Amit Verma");
    ward.displayFront();
    cout << "\n";

    ward.arrive("Sneha Joshi");
    cout << "\n";

    cout << "--- 3. Doctor Attending Patients (Dequeue Operations) ---\n";
    ward.attend();
    ward.displayFront();
    cout << "\n";

    ward.attend();
    ward.displayFront();
    cout << "\n";

    cout << "--- 4. New Emergency Arrival ---\n";
    ward.arrive("Karan Dave");
    ward.displayFront();
    cout << "\n";

    cout << "--- 5. Clearing Remaining Patients ---\n";
    ward.attend();
    ward.attend();
    ward.attend();
    ward.displayFront();
    cout << "\n";

    cout << "--- 6. Underflow Test (Ward Empty) ---\n";
    ward.attend();
    cout << "\n";

    cout << "========================================\n";
    cout << "         SIMULATION COMPLETE            \n";
    cout << "========================================\n";

    return 0;
}