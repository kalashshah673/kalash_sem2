#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Grading
{
protected:
    int marks;

public:
    Grading(int m)
    {
        marks = m;
    }

    virtual void computeGrade() = 0;   // Pure Virtual Function
};

// Undergraduate Class
class Undergraduate : public Grading
{
private:
    string name;

public:
    Undergraduate(string n, int m) : Grading(m)
    {
        name = n;
    }

    void computeGrade()
    {
        cout << "\nUndergraduate Student: " << name << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 85)
            cout << "Grade: A\n";
        else if (marks >= 70)
            cout << "Grade: B\n";
        else if (marks >= 55)
            cout << "Grade: C\n";
        else if (marks >= 40)
            cout << "Grade: D\n";
        else
            cout << "Grade: Fail\n";
    }
};

// Postgraduate Class
class Postgraduate : public Grading
{
private:
    string name;

public:
    Postgraduate(string n, int m) : Grading(m)
    {
        name = n;
    }

    void computeGrade()
    {
        cout << "\nPostgraduate Student: " << name << endl;
        cout << "Marks: " << marks << endl;

        if (marks >= 90)
            cout << "Grade: A+\n";
        else if (marks >= 80)
            cout << "Grade: A\n";
        else if (marks >= 70)
            cout << "Grade: B\n";
        else if (marks >= 60)
            cout << "Grade: C\n";
        else
            cout << "Grade: Fail\n";
    }
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();

    Grading* students[20];

    for (int i = 0; i < n; i++)
    {
        int type, marks;
        string name;

        cout << "\nStudent " << i + 1 << endl;
        cout << "1. Undergraduate\n2. Postgraduate\n";
        cout << "Enter Type: ";
        cin >> type;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
        cin.ignore();

        if (type == 1)
            students[i] = new Undergraduate(name, marks);
        else
            students[i] = new Postgraduate(name, marks);
    }

    cout << "\n--- Student Grades ---\n";

    for (int i = 0; i < n; i++)
    {
        students[i]->computeGrade();   // Runtime Polymorphism
    }

    // Free Memory
    for (int i = 0; i < n; i++)
    {
        delete students[i];
    }

    return 0;
}
