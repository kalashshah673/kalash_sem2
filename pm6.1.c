#include <iostream>
using namespace std;

// Base Class
class Shape
{
protected:
    float radius;

public:
    void setRadius(float r)
    {
        radius = r;
    }

    float getRadius()
    {
        return radius;
    }
};

// Derived Class
class Circle : public Shape
{
public:
    float area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int n;

    cout << "Enter number of circles: ";
    cin >> n;

    // Dynamic Method
    Circle* c = new Circle[n];

    cout << "\nEnter radius of circles:\n";
    for (int i = 0; i < n; i++)
    {
        float r;
        cout << "Circle " << i + 1 << " Radius: ";
        cin >> r;
        c[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Dynamic Array):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << i + 1 << " Area = "
             << c[i].area() << endl;
    }

    delete[] c;

    // Static Method
    Circle s[5];

    cout << "\nEnter radius for 5 circles (Static Array):\n";
    for (int i = 0; i < 5; i++)
    {
        float r;
        cout << "Circle " << i + 1 << " Radius: ";
        cin >> r;
        s[i].setRadius(r);
    }

    cout << "\nAreas of Circles (Static Array):\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "Circle " << i + 1 << " Area = "
             << s[i].area() << endl;
    }

    return 0;
}
