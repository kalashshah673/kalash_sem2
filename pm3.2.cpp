#include <iostream>
#include <chrono>  // for time measurement
using namespace std;
using namespace std::chrono;

// Recursive function
int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}

// Iterative function
int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    // Dynamic array allocation
    int* arr = new int[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Measure recursive time
    auto start1 = high_resolution_clock::now();
    int recSum = recursiveSum(arr, n);
    auto end1 = high_resolution_clock::now();

    // Measure iterative time
    auto start2 = high_resolution_clock::now();
    int itrSum = iterativeSum(arr, n);
    auto end2 = high_resolution_clock::now();

    // Time calculation
    auto recTime = duration_cast<nanoseconds>(end1 - start1);
    auto itrTime = duration_cast<nanoseconds>(end2 - start2);

    // Output
    cout << "\nRecursive Sum = " << recSum;
    cout << "\nIterative Sum = " << itrSum;

    cout << "\nRecursive Time (ns) = " << recTime.count();
    cout << "\nIterative Time (ns) = " << itrTime.count();

    delete[] arr;
    return 0;
}
