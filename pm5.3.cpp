#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int choice;
    string name, searchName;
    int quantity;
    float price;

    do
    {
        cout << "\n----- Inventory Management System -----\n";
        cout << "1. Add Item\n";
        cout << "2. View All Items\n";
        cout << "3. Search Item by Name\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            ofstream file("inventory.txt", ios::app);

            cout << "Enter Item Name: ";
            getline(cin, name);

            cout << "Enter Quantity: ";
            cin >> quantity;

            cout << "Enter Price: ";
            cin >> price;
            cin.ignore();

            file << name << endl;
            file << quantity << endl;
            file << price << endl;

            file.close();

            cout << "Item Added Successfully!\n";
        }
        else if (choice == 2)
        {
            ifstream file("inventory.txt");

            if (!file)
            {
                cout << "File not found!\n";
                continue;
            }

            cout << "\n--- All Items ---\n";

            while (getline(file, name))
            {
                file >> quantity;
                file >> price;
                file.ignore();

                cout << "Name     : " << name << endl;
                cout << "Quantity : " << quantity << endl;
                cout << "Price    : " << price << endl;
                cout << "----------------------\n";
            }

            file.close();
        }
        else if (choice == 3)
        {
            ifstream file("inventory.txt");

            if (!file)
            {
                cout << "File not found!\n";
                continue;
            }

            cout << "Enter Item Name to Search: ";
            getline(cin, searchName);

            bool found = false;

            while (getline(file, name))
            {
                file >> quantity;
                file >> price;
                file.ignore();

                if (name == searchName)
                {
                    cout << "\nItem Found!\n";
                    cout << "Name     : " << name << endl;
                    cout << "Quantity : " << quantity << endl;
                    cout << "Price    : " << price << endl;
                    found = true;
                }
            }

            if (!found)
            {
                cout << "Item not found!\n";
            }

            file.close();
        }
        else if (choice == 4)
        {
            cout << "Exiting Program...\n";
        }
        else
        {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
