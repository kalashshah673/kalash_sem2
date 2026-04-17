#include <iostream>
#include <string>
using namespace std;

// Base Class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

// Intermediate Class
class Employee : public Person
{
protected:
    int empID;

public:
    Employee(string n, int a, int id) : Person(n, a)
    {
        empID = id;
    }

    void displayEmployee()
    {
        displayPerson();
        cout << "Employee ID : " << empID << endl;
    }

    int getID()
    {
        return empID;
    }
};

// Top Level Class
class Manager : public Employee
{
private:
    string department;

public:
    Manager(string n, int a, int id, string dept)
        : Employee(n, a, id)
    {
        department = dept;
    }

    void displayManager()
    {
        displayEmployee();
        cout << "Department  : " << department << endl;
        cout << "----------------------" << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of managers: ";
    cin >> n;
    cin.ignore();

    // Dynamic Method
    Manager* m = new Manager[n]
    {
        Manager("",0,0,"")
    };

    for (int i = 0; i < n; i++)
    {
        string name, dept;
        int age, id;

        cout << "\nEnter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Department: ";
        getline(cin, dept);

        m[i] = Manager(name, age, id, dept);
    }

    cout << "\n--- All Managers (Dynamic Storage) ---\n";
    for (int i = 0; i < n; i++)
    {
        m[i].displayManager();
    }

    // Search by Employee ID
    int searchID;
    cout << "\nEnter Employee ID to Search: ";
    cin >> searchID;

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (m[i].getID() == searchID)
        {
            cout << "\nManager Found:\n";
            m[i].displayManager();
            found = true;
        }
    }

    if (!found)
        cout << "Manager not found!\n";

    delete[] m;

    // Static Method
    Manager s[2] =
    {
        Manager("Rahul", 35, 101, "IT"),
        Manager("Neha", 40, 102, "HR")
    };

    cout << "\n--- Static Storage Managers ---\n";
    for (int i = 0; i < 2; i++)
    {
        s[i].displayManager();
    }

    return 0;
}
