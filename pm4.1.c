#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;

public:
    // Constructor
    DynamicArray() {
        arr = nullptr;
        size = 0;
    }

    // Insert at end
    void insert(int value) {
        int* newArr = new int[size + 1];

        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        newArr[size] = value;

        delete[] arr;
        arr = newArr;
        size++;

        cout << "Inserted successfully!\n";
    }

    // Delete from position
    void remove(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position!\n";
            return;
        }

        int* newArr = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++) {
            if (i != pos) {
                newArr[j++] = arr[i];
            }
        }

        delete[] arr;
        arr = newArr;
        size--;

        cout << "Deleted successfully!\n";
    }

    // Display array
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }

        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray da;
    int choice, value, pos;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            da.insert(value);
            break;

        case 2:
            cout << "Enter position (0-based index): ";
            cin >> pos;
            da.remove(pos);
            break;

        case 3:
            da.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
