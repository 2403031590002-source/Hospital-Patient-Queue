#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    std::string name;
    bool emergency;
    int arrivalOrder;
};

struct EmergencyCompare {
    bool operator()(const Patient& a, const Patient& b) {
        return a.arrivalOrder > b.arrivalOrder; // earlier arrival has higher priority
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, EmergencyCompare> emergencyQueue;
    queue<Patient> regularQueue;
    int order = 0;
    const int avgWaitTime = 10; // minutes per patient

    while (true) {
        cout << "\nHospital Patient Queue\n";
        cout << "1. Add patient\n2. Serve next patient\n3. Display queue\n4. Exit\nChoose: ";
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Patient p;
            cout << "Enter patient name: ";
            getline(cin, p.name);
            cout << "Is this an emergency case? (y/n): ";
            char em;
            cin >> em;
            cin.ignore();
            p.emergency = (em == 'y' || em == 'Y');
            p.arrivalOrder = order++;
            if (p.emergency)
                emergencyQueue.push(p);
            else
                regularQueue.push(p);
            cout << "Patient added.\n";
        } else if (choice == 2) {
            if (!emergencyQueue.empty()) {
                Patient p = emergencyQueue.top();
                emergencyQueue.pop();
                cout << "Serving emergency patient: " << p.name << endl;
            } else if (!regularQueue.empty()) {
                Patient p = regularQueue.front();
                regularQueue.pop();
                cout << "Serving regular patient: " << p.name << endl;
            } else {
                cout << "No patients in queue.\n";
            }
        } else if (choice == 3) {
            cout << "\nEmergency Patients:\n";
            priority_queue<Patient, vector<Patient>, EmergencyCompare> tempE = emergencyQueue;
            int pos = 1;
            while (!tempE.empty()) {
                cout << pos << ". " << tempE.top().name << " (Estimated wait: " << (pos-1)*avgWaitTime << " min)\n";
                tempE.pop();
                pos++;
            }
            cout << "\nRegular Patients:\n";
            queue<Patient> tempR = regularQueue;
            while (!tempR.empty()) {
                cout << pos << ". " << tempR.front().name << " (Estimated wait: " << (pos-1)*avgWaitTime << " min)\n";
                tempR.pop();
                pos++;
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;