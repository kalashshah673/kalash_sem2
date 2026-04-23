#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string sentence, word;
    map<string, int> freq;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    stringstream ss(sentence);

    // Read words one by one
    while (ss >> word)
    {
        // Convert uppercase to lowercase
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                word[i] = word[i] + 32;
            }
        }

        freq[word]++;
    }

    // Display word frequencies
    cout << "\nWord Frequencies:\n";

    map<string, int>::iterator it;

    for (it = freq.begin(); it != freq.end(); ++it)
    {
        cout << it->first << " = " << it->second << endl;
    }

    return 0;
}
