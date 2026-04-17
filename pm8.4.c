#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string filename;
    ifstream file;

    // Retry mechanism for file opening
    while (true)
    {
        cout << "Enter file path (or type exit): ";
        getline(cin, filename);

        if (filename == "exit")
        {
            cout << "Program Closed.\n";
            return 0;
        }

        file.open(filename);

        if (file)
        {
            cout << "File opened successfully.\n";
            break;
        }
        else
        {
            cout << "Error: File not found or cannot be opened.\n";
            file.clear();
        }
    }

    string line;
    int lineNo = 0;

    // Process file line by line
    while (getline(file, line))
    {
        lineNo++;

        stringstream ss(line);
        float num, sum = 0;
        int count = 0;
        bool valid = true;

        // Read numbers from line
        while (ss >> num)
        {
            sum += num;
            count++;
        }

        // Check corrupted data
        if (!ss.eof())
        {
            valid = false;
        }

        if (valid && count > 0)
        {
            cout << "\nLine " << lineNo << ": ";
            cout << "Sum = " << sum;
            cout << ", Average = " << sum / count << endl;
        }
        else
        {
            cout << "\nLine " << lineNo
                 << ": Invalid / Corrupted Data (Skipped)\n";
        }
    }

    file.close();

    cout << "\nFile Processing Completed.\n";

    return 0;
}
