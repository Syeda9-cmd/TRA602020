#include<iostream>
using namespace std;
struct Patient {
    int patientID;
    char name[30];
    float temperature;
    int severity;
};
Patient* mostCritical(Patient arr[], int n) {
    Patient *critical = &arr[0];
    bool tie = false;
    for (int i = 1; i < n; i++) {
        if (arr[i].severity > critical->severity) {
            critical = &arr[i];
            tie = false;
        } else if (arr[i].severity == critical->severity) {
            tie = true;
        }
    }
    if (tie) {
        cout << " ??  ALERT: Multiple Critical Patients!" << endl;
        for (int i = 0; i < n; i++) {
            if (arr[i].severity == critical->severity) {
                cout << "ID : " << arr[i].patientID << endl;
                cout << "Name : " << arr[i].name << endl;
                cout << "Temp : " << arr[i].temperature << " C" << endl;
                cout << "Severity : " << arr[i].severity << "/10" << endl;
                cout << endl;
            }
        }
        return critical;
    }
    return critical;
}
Patient* findByID(Patient arr[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (arr[i].patientID == id) {
            return &arr[i];
        }
    }
    return NULL;
}
void displayPatient(Patient *p) {
    cout << "ID       : " << p->patientID << endl;
    cout << "Name     : " << p->name << endl;
    cout << "Temp     : " << p->temperature << " C" << endl;
    cout << "Severity : " << p->severity << "/10" << endl;
}
void inputPatient(Patient *p, int index) {
    cout << "Patient " << index << ":" << endl;
    cout << "ID: ";
    cin >> p->patientID;
    cout << "Name: ";
    cin >> p->name;
    cout << "Temp: ";
    cin >> p->temperature;
    cout << "Severity: ";
    cin >> p->severity;
}
int main() {
    int n;
    cout << "=== Lahore General Hospital - Emergency Triage ===" << endl;
    cout << "Enter number of patients: ";
    cin >> n;
    Patient patients[50];
    for (int i = 0; i < n; i++) {
        inputPatient(&patients[i], i + 1);
    }
    cout << "\n--- Most Critical Patient ---" << endl;
    Patient *critical = mostCritical(patients, n);
    bool tie = false;
    for (int i = 0; i < n; i++) {
        if (&patients[i] != critical && patients[i].severity == critical->severity) {
            tie = true;
            break;
        }
    }
    if (!tie) {
        cout << "??  ALERT: Immediate Attention Required!" << endl;
        displayPatient(critical);
    }
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        int updateID;
        cout << "\nEnter Patient ID to update (0 to stop): ";
        cin >> updateID;
        if (updateID == 0) break;
        Patient *ptr = findByID(patients, n, updateID);
        if (ptr != NULL) {
            cout << "Enter new temperature: ";
            cin >> ptr->temperature;
            cout << "Enter new severity   : ";
            cin >> ptr->severity;
            cout << "\n--- Updated Record ---" << endl;
            displayPatient(ptr);
            cout << "\n--- New Most Critical Patient ---" << endl;
            critical = mostCritical(patients, n);
            tie = false;
            for (int i = 0; i < n; i++) {
                if (&patients[i] != critical && patients[i].severity == critical->severity) {
                    tie = true;
                    break;
                }
            }
            if (!tie) {
                cout << "??  ALERT: Immediate Attention Required!" << endl;
                displayPatient(critical);
            }
        } else {
            cout << "? Error: Patient ID " << updateID << " not found!" << endl;
        }
        cout << "Update another patient? (y/n): ";
        cin >> cont;
    }
    cout << "\n=== Final Triage Summary ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "ID: " << patients[i].patientID
             << " | Name: " << patients[i].name
             << " | Temp: " << patients[i].temperature << " C"
             << " | Severity: " << patients[i].severity << endl;
    }
    return 0;
}
