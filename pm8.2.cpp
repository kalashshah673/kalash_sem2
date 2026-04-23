#include <iostream>
#include <cmath>
using namespace std;

// Custom Exception Class
class NegativeNumberException
{
public:
    void message()
    {
        cout << "Error: Negative number entered. Square root cannot be calculated." << endl;
    }
};

int main()
{
    float num;

    try
    {
        cout << "Enter a number: ";
        cin >> num;

        // Check negative number immediately
        if (num < 0)
        {
            throw NegativeNumberException();
        }

        cout << "Square Root = " << sqrt(num) << endl;
    }
    catch (NegativeNumberException e)
    {
        e.message();
    }

    return 0;
}
