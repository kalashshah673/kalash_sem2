#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Operator + Overloading
    Complex operator + (Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Operator - Overloading
    Complex operator - (Complex c)
    {
        Complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }

    // Display Function
    void display()
    {
        cout << real;

        if (imag >= 0)
            cout << " + " << imag << "i";
        else
            cout << " - " << -imag << "i";

        cout << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of complex numbers: ";
    cin >> n;

    Complex arr[20];

    // Input Complex Numbers
    for (int i = 0; i < n; i++)
    {
        float r, im;
        cout << "\nEnter Real part of Complex " << i + 1 << ": ";
        cin >> r;
        cout << "Enter Imaginary part: ";
        cin >> im;

        arr[i] = Complex(r, im);
    }

    cout << "\nEntered Complex Numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Complex " << i + 1 << " = ";
        arr[i].display();
    }

    // Example Operations
    if (n >= 2)
    {
        Complex sum, diff;

        sum = arr[0] + arr[1];
        diff = arr[0] - arr[1];

        cout << "\nAddition of First Two Numbers:\n";
        sum.display();

        cout << "Subtraction of First Two Numbers:\n";
        diff.display();
    }
    else
    {
        cout << "\nNeed at least 2 complex numbers for operations.\n";
    }

    return 0;
}
