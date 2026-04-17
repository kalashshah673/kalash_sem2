#include <iostream>
using namespace std;

// Recursive function to find super digit
int superDigit(long long n) {
    if (n < 10)
        return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return superDigit(sum);
}

// Main function using optimization
int main() {
    string n;
    int k;

    cout << "Enter number (as string): ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    // Step 1: sum digits of n
    long long initialSum = 0;
    for (char c : n) {
        initialSum += (c - '0');
    }

    // Step 2: multiply by k
    long long total = initialSum * k;

    // Step 3: recursive super digit
    int result = superDigit(total);

    cout << "Super Digit: " << result << endl;

    return 0;
}
