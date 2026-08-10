#include<iostream>
using namespace std;
struct Bill {
    int accountNo;
    char ownerName[30];
    int unitsConsumed;
    float ratePerUnit;
    float totalBill;
};
void inputBill(Bill *b) {
    cout << "Enter Account No : ";
    cin >> b->accountNo;
    cout << "Enter Owner Name : ";
    cin >> b->ownerName;
    cout << "Units Consumed   : ";
    cin >> b->unitsConsumed;
    cout << "Rate Per Unit (Rs): ";
    cin >> b->ratePerUnit;
}
void calculateBill(Bill *b) {
    b->totalBill = b->unitsConsumed * b->ratePerUnit;
    if (b->unitsConsumed > 300) {
        b->totalBill += b->totalBill * 0.15;
    }
}
void displayBill(Bill *b) {
    float baseAmount = b->unitsConsumed * b->ratePerUnit;
    cout << "\n========== LESCO Bill ==========" << endl;
    cout << "Account No   : " << b->accountNo << endl;
    cout << "Owner Name   : " << b->ownerName << endl;
    cout << "Units Used   : " << b->unitsConsumed << endl;
    cout << "Rate/Unit    : Rs. " << b->ratePerUnit << endl;
    cout << "Base Amount  : Rs. " << baseAmount << endl;
    if (b->unitsConsumed > 300) {
        float surcharge = baseAmount * 0.15;
        cout << "Surcharge 15%: Rs. " << surcharge << endl;
    }
    cout << "Total Bill   : Rs. " << b->totalBill << endl;
}
int main() {
    Bill b;
    cout << "=== LESCO Billing System ===" << endl;
    inputBill(&b);
    calculateBill(&b);
    displayBill(&b);
    return 0;
}
