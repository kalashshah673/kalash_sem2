#include <iostream>
using namespace std;

class Fahrenheit;   // Forward Declaration

// Celsius Class
class Celsius
{
private:
    float temp;

public:
    Celsius(float t = 0)
    {
        temp = t;
    }

    float getTemp()
    {
        return temp;
    }

    // Conversion Celsius -> Fahrenheit
    operator Fahrenheit();

    // Equality Operator
    bool operator == (Celsius c)
    {
        return temp == c.temp;
    }
};

// Fahrenheit Class
class Fahrenheit
{
private:
    float temp;

public:
    Fahrenheit(float t = 0)
    {
        temp = t;
    }

    float getTemp()
    {
        return temp;
    }

    // Conversion Fahrenheit -> Celsius
    operator Celsius()
    {
        return Celsius((temp - 32) * 5 / 9);
    }

    // Equality Operator
    bool operator == (Fahrenheit f)
    {
        return temp == f.temp;
    }
};

// Define Celsius -> Fahrenheit
Celsius::operator Fahrenheit()
{
    return Fahrenheit((temp * 9 / 5) + 32);
}

int main()
{
    // Single Object Conversion
    Celsius c1(25);
    Fahrenheit f1;

    f1 = c1;   // Celsius to Fahrenheit

    cout << "25 Celsius = "
         << f1.getTemp() << " Fahrenheit\n";

    Fahrenheit f2(98.6);
    Celsius c2;

    c2 = f2;   // Fahrenheit to Celsius

    cout << "98.6 Fahrenheit = "
         << c2.getTemp() << " Celsius\n";

    // Equality Check
    Celsius c3(25);

    if (c1 == c3)
        cout << "Both Celsius temperatures are equal\n";
    else
        cout << "Not equal\n";

    // Dynamic Queue (FIFO)
    int n;
    cout << "\nEnter number of Celsius values: ";
    cin >> n;

    Celsius* queue = new Celsius[n];

    for (int i = 0; i < n; i++)
    {
        float x;
        cout << "Enter Celsius " << i + 1 << ": ";
        cin >> x;
        queue[i] = Celsius(x);
    }

    cout << "\nQueue Conversion (FIFO):\n";
    for (int i = 0; i < n; i++)
    {
        Fahrenheit f = queue[i];
        cout << queue[i].getTemp()
             << " C = "
             << f.getTemp()
             << " F\n";
    }

    delete[] queue;

    // Static Array
    Fahrenheit arr[3] = {32, 68, 104};

    cout << "\nStatic Fahrenheit Array Conversion:\n";
    for (int i = 0; i < 3; i++)
    {
        Celsius c = arr[i];
        cout << arr[i].getTemp()
             << " F = "
             << c.getTemp()
             << " C\n";
    }

    return 0;
}
