#include <iostream>
using namespace std;

// Calculator Class
class Calculator
{
private:
    float results[20];
    int count;

public:
    Calculator()
    {
        count = 0;
    }

    // Function Overloading

    int add(int a, int b)
    {
        int sum = a + b;
        results[count] = sum;
        count++;
        return sum;
    }

    float add(float a, float b)
    {
        float sum = a + b;
        results[count] = sum;
        count++;
        return sum;
    }

    float add(int a, float b)
    {
        float sum = a + b;
        results[count] = sum;
        count++;
        return sum;
    }

    float add(float a, int b)
    {
        float sum = a + b;
        results[count] = sum;
        count++;
        return sum;
    }

    // Display all stored results
    void showResults()
    {
        cout << "\nStored Results:\n";
        for (int i = 0; i < count; i++)
        {
            cout << "Result " << i + 1 << " = "
                 << results[i] << endl;
        }
    }
};

int main()
{
    Calculator c;

    cout << "Integer + Integer = "
         << c.add(10, 20) << endl;

    cout << "Float + Float = "
         << c.add(5.5f, 2.3f) << endl;

    cout << "Integer + Float = "
         << c.add(15, 4.7f) << endl;

    cout << "Float + Integer = "
         << c.add(8.2f, 6) << endl;

    c.showResults();

    return 0;
}
