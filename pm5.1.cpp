#include <iostream>
#include <string>
using namespace std;

int main()
{
    string paragraph;

    // Read complete paragraph using getline
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    string words[100];      // store unique words
    int freq[100] = {0};   // store frequency
    int count = 0;

    string temp = "";

    // Traverse paragraph character by character
    for (int i = 0; i <= paragraph.length(); i++)
    {
        if (paragraph[i] != ' ' && paragraph[i] != '\0')
        {
            char ch = paragraph[i];

            // Convert uppercase to lowercase manually
            if (ch >= 'A' && ch <= 'Z')
                ch = ch + 32;

            temp += ch;
        }
        else
        {
            if (temp != "")
            {
                int found = -1;

                // Check if word already exists
                for (int j = 0; j < count; j++)
                {
                    if (words[j] == temp)
                    {
                        found = j;
                        break;
                    }
                }

                if (found == -1)
                {
                    words[count] = temp;
                    freq[count] = 1;
                    count++;
                }
                else
                {
                    freq[found]++;
                }

                temp = "";
            }
        }
    }

    // Display result
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < count; i++)
    {
        cout << words[i] << " = " << freq[i] << endl;
    }

    return 0;
}
