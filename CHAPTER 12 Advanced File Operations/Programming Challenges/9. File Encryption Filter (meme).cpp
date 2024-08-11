/* File encryption is the science of writing the contents of a file in a secret code. Your
encryption program should work like a filter, reading the contents of one file, modify-
ing the data into a code, and then writing the coded contents out to a second file. The
second file will be a version of the first file, but written in a secret code.
Although there are complex encryption techniques, you should come up with a
simple one of your own. For example, you could read the first file one character at
a time, and add 10 to the ASCII code of each character before it is written to the
second file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int encryption(int, int);

int main() {
    string input;
    string fileName;  // To hold the file name
    char ch;          // To hold a character
    ifstream inFile;  // Input file
    int sus = 0;

    // Open a file for output.
    ofstream outFile("PC9C12out.txt");

    // Get the input file name.
    cout << "Name of the input file? ";
    getline(cin, fileName);

    // Open the file for input.
    inFile.open(fileName);
    int encrypt = 0;

    cout << "How many ASCII would you like to add per character? ";
    cin >> encrypt;

    // If the file was successfully opened, continue.
    if (inFile) {
        // Read an item from the file.

        while (inFile.get(ch)) {

            if(ispunct(ch) || isspace(ch)) {
                outFile.put(ch);
            }
            else {
                sus = encryption(ch, encrypt);
                outFile.put(sus);
            }

        }
        
        // Close the file
        inFile.close();
        cout << "File has been closed.\n";
    } else {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}

int encryption(int one, int two) {

    int outcome = one + two;
    outcome = outcome % 127;

    cout << "Original: " << outcome;

    if(outcome > 90 && outcome < 97) {
        cout << " + ";
        outcome += 100;
    }

    while(outcome < 65 || outcome > 122) { 
    
        if(outcome < 65) {
            cout << " + ";
            outcome += 10;
        }
        else if (outcome > 122) {
            cout << " - ";
            outcome -= 10;
        }

    }

    cout << " Changed: " << outcome << endl;
    return outcome;
}