#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accNumber;
    string name;
    double balance;

    static int totalAccounts;  // static member

public:
    // Constructor
    BankAccount(int accNo, string n, double bal) {
        accNumber = accNo;
        name = n;
        balance = bal;
        totalAccounts++;
    }

    // Display account details
    void display() {
        cout << "Account Number: " << accNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "------------------------" << endl;
    }

    // Deposit
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    // Withdraw
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Transfer function
    bool transfer(BankAccount &receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            return true;
        }
        return false;
    }

    // Getter for account number
    int getAccNumber() {
        return accNumber;
    }

    // Static function to show total accounts
    static void showTotalAccounts() {
        cout << "Total Accounts Created: " << totalAccounts << endl;
    }
};

// Initialize static member
int BankAccount::totalAccounts = 0;

int main() {
    int n;
    cout << "Enter number of accounts: ";
    cin >> n;

    // Dynamic allocation
    BankAccount** accounts = new BankAccount*[n];

    for (int i = 0; i < n; i++) {
        int accNo;
        string name;
        double balance;

        cout << "\nEnter details for account " << i + 1 << endl;
        cout << "Account Number: ";
        cin >> accNo;
        cout << "Name: ";
        cin >> name;
        cout << "Balance: ";
        cin >> balance;

        accounts[i] = new BankAccount(accNo, name, balance);
    }

    // Transfer operation
    int fromAcc, toAcc;
    double amount;

    cout << "\nEnter sender account number: ";
    cin >> fromAcc;
    cout << "Enter receiver account number: ";
    cin >> toAcc;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    BankAccount *sender = nullptr, *receiver = nullptr;

    // Find accounts
    for (int i = 0; i < n; i++) {
        if (accounts[i]->getAccNumber() == fromAcc)
            sender = accounts[i];
        if (accounts[i]->getAccNumber() == toAcc)
            receiver = accounts[i];
    }

    // Validation
    if (sender && receiver) {
        if (sender->transfer(*receiver, amount))
            cout << "Transfer Successful!\n";
        else
            cout << "Transfer Failed (Insufficient Balance)\n";
    } else {
        cout << "Invalid Account Number!\n";
    }

    // Display all accounts
    cout << "\nAll Account Details:\n";
    for (int i = 0; i < n; i++) {
        accounts[i]->display();
    }

    // Show total accounts
    BankAccount::showTotalAccounts();

    // Free memory
    for (int i = 0; i < n; i++) {
        delete accounts[i];
    }
    delete[] accounts;

    return 0;
}
