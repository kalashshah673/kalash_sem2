#include <iostream>
using namespace std;

int main()
{
    int a, b;

    try
    {
        cout << "Enter numerator and denominator: ";

        // Input extraction check
        if (!(cin >> a >> b))
        {
            throw "Invalid input! Please enter integers only.";
        }

        // Division by zero check
        if (b == 0)
        {
            throw b;
        }

        cout << "Result = " << a / b << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }
    catch (int)
    {
        cout << "Error: Division by zero is not allowed." << endl;
    }

    return 0;
}
