#include <iostream>
#include <string>
using namespace std;

// Base Class
class Account
{
protected:
    int accNo;
    float balance;

    string history[100];
    int top;

public:
    Account(int no, float bal)
    {
        accNo = no;
        balance = bal;
        top = -1;
        cout << "Account Constructor Called\n";
    }

    ~Account()
    {
        cout << "Account Destructor Called\n";
    }

    void deposit(float amt)
    {
        balance += amt;
        top++;
        history[top] = "Deposit " + to_string((int)amt);
    }

    void withdraw(float amt)
    {
        if (amt <= balance)
        {
            balance -= amt;
            top++;
            history[top] = "Withdraw " + to_string((int)amt);
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    void showHistory()
    {
        cout << "\nTransaction History:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << history[i] << endl;
        }
    }

    void undoLast()
    {
        if (top == -1)
        {
            cout << "No transaction to undo!\n";
            return;
        }

        string last = history[top];

        if (last[0] == 'D')   // Deposit
        {
            int amt = stoi(last.substr(8));
            balance -= amt;
        }
        else if (last[0] == 'W') // Withdraw
        {
            int amt = stoi(last.substr(9));
            balance += amt;
        }

        top--;
        cout << "Last transaction undone!\n";
    }

    void display()
    {
        cout << "Account No : " << accNo << endl;
        cout << "Balance    : " << balance << endl;
    }
};

// Derived Class : Savings
class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(int no, float bal, float rate)
        : Account(no, bal)
    {
        interestRate = rate;
        cout << "Savings Constructor Called\n";
    }

    ~SavingsAccount()
    {
        cout << "Savings Destructor Called\n";
    }

    void display()
    {
        Account::display();
        cout << "Interest Rate : " << interestRate << "%\n";
    }
};

// Derived Class : Current
class CurrentAccount : public Account
{
private:
    float overdraft;

public:
    CurrentAccount(int no, float bal, float od)
        : Account(no, bal)
    {
        overdraft = od;
        cout << "Current Constructor Called\n";
    }

    ~CurrentAccount()
    {
        cout << "Current Destructor Called\n";
    }

    void withdraw(float amt)
    {
        if (amt <= balance + overdraft)
        {
            balance -= amt;
            top++;
            history[top] = "Withdraw " + to_string((int)amt);
        }
        else
        {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }

    void display()
    {
        Account::display();
        cout << "Overdraft Limit : " << overdraft << endl;
    }
};

int main()
{
    SavingsAccount s(101, 5000, 5);
    CurrentAccount c(202, 3000, 2000);

    cout << "\n--- Savings Account ---\n";
    s.deposit(1000);
    s.withdraw(500);
    s.display();
    s.showHistory();
    s.undoLast();
    s.display();

    cout << "\n--- Current Account ---\n";
    c.deposit(2000);
    c.withdraw(4000);
    c.display();
    c.showHistory();
    c.undoLast();
    c.display();

    return 0;
}
