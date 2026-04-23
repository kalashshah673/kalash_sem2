#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    map<string, vector<string> > directory;
    int choice;

    do
    {
        cout << "\n----- Directory Management System -----\n";
        cout << "1. Add Folder\n";
        cout << "2. Add File to Folder\n";
        cout << "3. Display All Folders and Files\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string folder;

            cout << "Enter Folder Name: ";
            getline(cin, folder);

            directory[folder];   // create empty folder
            cout << "Folder Added Successfully.\n";
        }
        else if (choice == 2)
        {
            string folder, file;

            cout << "Enter Folder Name: ";
            getline(cin, folder);

            if (directory.find(folder) != directory.end())
            {
                cout << "Enter File Name: ";
                getline(cin, file);

                directory[folder].push_back(file);
                cout << "File Added Successfully.\n";
            }
            else
            {
                cout << "Folder Not Found!\n";
            }
        }
        else if (choice == 3)
        {
            cout << "\n----- Directory Contents -----\n";

            map<string, vector<string> >::iterator it;

            for (it = directory.begin(); it != directory.end(); ++it)
            {
                cout << "Folder: " << it->first << endl;

                if (it->second.size() == 0)
                {
                    cout << "  No Files\n";
                }
                else
                {
                    for (int i = 0; i < it->second.size(); i++)
                    {
                        cout << "  - " << it->second[i] << endl;
                    }
                }

                cout << endl;
            }
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
