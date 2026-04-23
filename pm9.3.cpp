#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n, value;

    cout << "Enter number of integers: ";
    cin >> n;

    set<int> s;
    vector<int> original;

    // Input values
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;

        original.push_back(value);
        s.insert(value);   // duplicates removed automatically
    }

    // Display original list
    cout << "\nOriginal List: ";
    for (int i = 0; i < original.size(); i++)
    {
        cout << original[i] << " ";
    }

    // Display set using iterators
    cout << "\nUnique Sorted Elements (Set): ";
    set<int>::iterator it;

    for (it = s.begin(); it != s.end(); ++it)
    {
        cout << *it << " ";
    }

    // Convert set to vector
    vector<int> uniqueValues;

    for (it = s.begin(); it != s.end(); ++it)
    {
        uniqueValues.push_back(*it);
    }

    // Display vector
    cout << "\nConverted Back to Vector: ";
    for (int i = 0; i < uniqueValues.size(); i++)
    {
        cout << uniqueValues[i] << " ";
    }

    return 0;
}
