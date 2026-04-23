#include <iostream>
#include <string>
using namespace std;

string logs[100];
int indexLog = 0;

// Function to store logs
void addLog(string msg)
{
    logs[indexLog] = msg;
    indexLog++;
}

// BankAccount Class
class BankAccount
{
private:
    float balance;

public:
    BankAccount(float b)
    {
        balance = b;
        addLog("BankAccount created");
    }

    void deposit(float amt)
    {
        addLog("Entered deposit()");

        if (amt <= 0)
            throw "Invalid deposit amount";

        balance += amt;
        addLog("Deposit successful");

        addLog("Exit deposit()");
    }

    void withdraw(float amt)
    {
        addLog("Entered withdraw()");

        if (amt <= 0)
            throw "Invalid withdrawal amount";

        if (amt > balance)
            throw "Insufficient balance";

        balance -= amt;
        addLog("Withdrawal successful");

        addLog("Exit withdraw()");
    }

    void displayBalance()
    {
        cout << "Current Balance = " << balance << endl;
    }
};

// Nested Function Calls for Stack Unwinding
void processWithdraw(BankAccount &acc, float amt)
{
    addLog("Entered processWithdraw()");
    acc.withdraw(amt);
    addLog("Exit processWithdraw()");
}

void transaction(BankAccount &acc, float amt)
{
    addLog("Entered transaction()");
    processWithdraw(acc, amt);
    addLog("Exit transaction()");
}

int main()
{
    BankAccount acc(5000);

    try
    {
        addLog("Entered main try block");

        acc.deposit(1000);
        transaction(acc, 7000);   // Causes exception

        addLog("Exit main try block");
    }
    catch (const char* msg)
    {
        addLog("Exception caught in main()");
        cout << "Error: " << msg << endl;
    }

    cout << "\n--- Transaction Logs ---\n";
    for (int i = 0; i < indexLog; i++)
    {
        cout << logs[i] << endl;
    }

    cout << endl;
    acc.displayBalance();

    return 0;
}
