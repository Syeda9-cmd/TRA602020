#include <iostream>
#include <string>
using namespace std;
struct Account {
    string accountNumber;
    string holderName;
    double balance;
};
Account createAccount() {
    Account acc;
    cout << " Create New Account"<<endl;
    cout << "Enter account number: "; cin >> acc.accountNumber;
    cout << "Enter account holder name : "; cin >> acc.holderName;
    cout << "Enter initial balance      : "; cin >> acc.balance;
    return acc;  
}
void deposit(Account &acc, double amount) {
    acc.balance += amount;
    cout << "===Deposit Receipt==="<<endl;
    cout << "Account  : " << acc.accountNumber << endl;
    cout << "Holder   : " << acc.holderName    << endl;
    cout << "Deposited: Rs. " << amount   << endl;
    cout << "Balance  : Rs. " << acc.balance      << endl;
}
bool withdraw(Account &acc, double amount) {
    if (amount > acc.balance) {
        cout << "---Insufficient funds---"<<endl;
        cout << "Required : Rs. " << amount      << endl;
        cout << "Available: Rs. " << acc.balance  << endl;
        return false;
    }
    acc.balance -= amount;
    cout << "-----Withdrawal successful-----"<<endl;
    cout << "Balance after withdrawal: Rs. " << acc.balance <<endl;
    return true;
}
int main() {
    Account myAcc = createAccount();
    deposit(myAcc, 5000);
    withdraw(myAcc, 2000);  
    withdraw(myAcc, 10000);  
    cout << "======Final Balance: Rs." << myAcc.balance <<endl;
    return 0;
}
