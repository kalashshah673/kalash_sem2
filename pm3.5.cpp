#include <iostream>
using namespace std;

// Display array
template <typename T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Find maximum element
template <typename T>
T findMax(T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Reverse array
template <typename T>
void reverseArray(T arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Leader elements
template <typename T>
void findLeaders(T arr[], int n) {
    cout << "Leader Elements: ";

    T maxFromRight = arr[n - 1];
    cout << maxFromRight << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > maxFromRight) {
            cout << arr[i] << " ";
            maxFromRight = arr[i];
        }
    }
    cout << endl;
}

int main() {
    int intArr[] = {16, 17, 4, 3, 5, 2};
    float floatArr[] = {1.5, 2.3, 0.9, 5.1, 3.3};
    char charArr[] = {'a', 'x', 'b', 'z', 'c'};

    int n1 = 6, n2 = 5, n3 = 5;

    cout << "---- Integer Array ----\n";
    display(intArr, n1);
    cout << "Max: " << findMax(intArr, n1) << endl;
    reverseArray(intArr, n1);
    cout << "Reversed: ";
    display(intArr, n1);
    findLeaders(intArr, n1);

    cout << "\n---- Float Array ----\n";
    display(floatArr, n2);
    cout << "Max: " << findMax(floatArr, n2) << endl;
    reverseArray(floatArr, n2);
    cout << "Reversed: ";
    display(floatArr, n2);
    findLeaders(floatArr, n2);

    cout << "\n---- Character Array ----\n";
    display(charArr, n3);
    cout << "Max: " << findMax(charArr, n3) << endl;
    reverseArray(charArr, n3);
    cout << "Reversed: ";
    display(charArr, n3);
    findLeaders(charArr, n3);

    return 0;
}
