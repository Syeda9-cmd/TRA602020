#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Account {
    string name;
    int accountNumber;
    float* deposits;   
    float balance;
};
int main() {
    const int NUM_ACCOUNTS = 5;
    const int DEPOSIT_DAYS = 30;
    Account accounts[NUM_ACCOUNTS];
    accounts[0] = {"Usman ",  10001, new float[DEPOSIT_DAYS], 75000.0};
    accounts[1] = {"Fatima ", 10002, new float[DEPOSIT_DAYS], 42000.0};
    accounts[2] = {"Bilal ",   10003, new float[DEPOSIT_DAYS], 99000.0};
    accounts[3] = {"Ayesha ",  10004, new float[DEPOSIT_DAYS], 15000.0};
    accounts[4] = {"Zara ",  10005, new float[DEPOSIT_DAYS], 63000.0};
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        for (int d = 0; d < DEPOSIT_DAYS; d++) {
            accounts[i].deposits[d] = 1000.0 + (i * 200) + (d * 10);
        }
    }
    ofstream outFile("details.txt");
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        outFile << accounts[i].name          << "\n";
        outFile << accounts[i].accountNumber << "\n";
        for (int d = 0; d < DEPOSIT_DAYS; d++) {
            outFile << accounts[i].deposits[d];
            if (d < DEPOSIT_DAYS - 1) outFile << " ";
        }
        outFile << endl;
        outFile << accounts[i].balance << endl;
        outFile << endl;
    }
    outFile.close();
    cout << "Bank records written to details.txt\n\n";
    ifstream inFile("details.txt");
    cout << "   ACCOUNTS WITH BALANCE > 50,000 PKR    \n";
    cout << "==========================================\n";
    string name, separator;
    int accNum;
    float dep[DEPOSIT_DAYS];
    float balance;
    while (getline(inFile, name)) {
        if (name.empty()) continue;
        inFile >> accNum;
        for (int d = 0; d < DEPOSIT_DAYS; d++) {
            inFile >> dep[d];
        }
        inFile >> balance;
        inFile.ignore();
        getline(inFile, separator); 

        if (balance > 50000) {
            cout << "Name    : " << name    << "\n";
            cout << "Acc No  : " << accNum  << "\n";
            cout << "Balance : PKR " << balance << "\n";
            cout << "------------------------------------------\n";
        }
    }
    inFile.close();
    for (int i = 0; i < NUM_ACCOUNTS; i++) {
        delete[] accounts[i].deposits;
    }
    cout << "Memory freed successfully."<<endl;
    return 0;
}
