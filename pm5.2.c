#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("data.txt");   // File name

    // Check if file opens or not
    if (!file)
    {
        cout << "Error: File does not exist or cannot be opened.\n";
        return 1;
    }

    string line;
    int totalChars = 0;
    int totalWords = 0;
    int totalLines = 0;

    // Read file line by line
    while (getline(file, line))
    {
        totalLines++;

        bool inWord = false;

        // Scan each character manually
        for (int i = 0; i < line.length(); i++)
        {
            totalChars++;

            if (line[i] != ' ' && line[i] != '\t')
            {
                if (!inWord)
                {
                    totalWords++;
                    inWord = true;
                }
            }
            else
            {
                inWord = false;
            }
        }
    }

    file.close();

    // Display results
    cout << "Total Lines      : " << totalLines << endl;
    cout << "Total Words      : " << totalWords << endl;
    cout << "Total Characters : " << totalChars << endl;

    return 0;
}
