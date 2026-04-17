#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums;

    // Input elements
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        nums.push_back(value);
    }

    // Display original vector
    cout << "\nOriginal Vector: ";
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << " ";
    }

    // Method 1: Using std::reverse()
    vector<int> v1 = nums;
    reverse(v1.begin(), v1.end());

    cout << "\nReversed using std::reverse(): ";
    for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }

    // Method 2: Manual reversal using iterators
    vector<int> v2 = nums;

    vector<int>::iterator start = v2.begin();
    vector<int>::iterator end = v2.end() - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        ++start;
        --end;
    }

    cout << "\nReversed manually using iterators: ";
    for (vector<int>::iterator it = v2.begin(); it != v2.end(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}
