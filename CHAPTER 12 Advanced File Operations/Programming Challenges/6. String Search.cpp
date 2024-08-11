/* Write a program that asks the user for a file name and a string to search for. The
program should search the file for every occurrence of a specified string. When the
string is found, the line that contains it should be displayed. After all the occurrences
have been located, the program should report the number of times the string appeared
in the file.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int main() {
    string input, // To hold file input
           search;      
    string filename;
    fstream nameFile;  // File stream object
    int counter = 0;

    cout << "Name of a file? ";
    getline(cin, filename);

    cout << "String to search for in " << filename << "? ";
    getline(cin, search);

    nameFile.open(filename, ios::in);

    if(nameFile) {
        cout << "Currently inside " << filename << ", searching for " << search << endl;

        while(getline(nameFile, input)) {

            // Find occurrences of the search string in the line
            int pos = input.find(search);  // size_t is replaced with int
            while (pos != -1) { // who needs string::npos
                cout << input << endl;
                counter++; // Increment the counter for each occurrence
                pos = input.find(search, pos + 1); // Find next occurrence
                // mystring.find('z', x); Returns the first position at or beyond position x where ‘z’ is found in mystring. (pg 589)
            } 

        }
        nameFile.close();

    } else {
        cout << "ERROR: Cannot open file.\n";
    }

    cout << "There is a total of " << counter << " occurences of " << search << endl;

    return 0;
}