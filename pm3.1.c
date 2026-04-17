#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    // Constructor with default bonus
    Employee(string n, double bSalary) {
        name = n;
        basicSalary = bSalary;
        bonus = 1000;  // default bonus
    }

    // Constructor with custom bonus
    Employee(string n, double bSalary, double b) {
        name = n;
        basicSalary = bSalary;
        bonus = b;
    }

    // Inline function to calculate total salary
    inline double calculateTotalSalary() {
        return basicSalary + bonus;
    }

    // Function to display details
    void display() {
        cout << "Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "-------------------------" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    // Dynamic allocation of employee array
    Employee* emp = new Employee[n];

    for (int i = 0; i < n; i++) {
        string name;
        double salary, bonus;
        int choice;

        cout << "\nEnter details for employee " << i + 1 << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Basic Salary: ";
        cin >> salary;

        cout << "1. Default Bonus\n2. Custom Bonus\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            emp[i] = Employee(name, salary);
        } else {
            cout << "Enter bonus: ";
            cin >> bonus;
            emp[i] = Employee(name, salary, bonus);
        }
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < n; i++) {
        emp[i].display();
    }

    // Free memory
    delete[] emp;

    return 0;
}
