#include <iostream>
using namespace std;

// Base Class
class Shape
{
public:
    virtual float Area()
    {
        return 0;
    }

    virtual ~Shape() {}
};

// Derived Class : Rectangle
class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    float Area()
    {
        return length * width;
    }
};

// Derived Class : Circle
class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    float Area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int n;

    cout << "Enter number of shapes: ";
    cin >> n;

    // Dynamic Storage
    Shape* shapes[20];

    for (int i = 0; i < n; i++)
    {
        int choice;

        cout << "\n1. Rectangle\n2. Circle\n";
        cout << "Choose shape " << i + 1 << ": ";
        cin >> choice;

        if (choice == 1)
        {
            float l, w;
            cout << "Enter Length: ";
            cin >> l;
            cout << "Enter Width: ";
            cin >> w;

            shapes[i] = new Rectangle(l, w);
        }
        else if (choice == 2)
        {
            float r;
            cout << "Enter Radius: ";
            cin >> r;

            shapes[i] = new Circle(r);
        }
    }

    cout << "\n--- Areas using Polymorphism ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Shape " << i + 1
             << " Area = "
             << shapes[i]->Area() << endl;
    }

    // Delete Dynamic Objects
    for (int i = 0; i < n; i++)
    {
        delete shapes[i];
    }

    // Static Storage
    Shape* fixed[2];

    fixed[0] = new Rectangle(10, 5);
    fixed[1] = new Circle(7);

    cout << "\n--- Static Array Areas ---\n";
    for (int i = 0; i < 2; i++)
    {
        cout << "Shape " << i + 1
             << " Area = "
             << fixed[i]->Area() << endl;
    }

    delete fixed[0];
    delete fixed[1];

    return 0;
}
