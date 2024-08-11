/* Write a program that asks the user for the name of a file. The program should display
the first 10 lines of the file on the screen (the “head” of the file). If the file has fewer
than 10 lines, the entire file should be displayed, with a message indicating the entire
file has been displayed.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from 12-8

int main() {
    string input;      // To hold file input
    string filename;
    fstream nameFile;  // File stream object
    int counter = 0;

    cout << "Name of a file? ";
    getline(cin, filename);

    nameFile.open(filename, ios::in);

    // If the file was successfully opened, continue.
    if (nameFile) {
        // Read an item from the file.
        getline(nameFile, input);

        // While the last read operation
        // was successful, continue.
        while (nameFile && counter < 10) {
            // Display the last item read.
            cout << input << endl;

            // Read the next item.
            getline(nameFile, input);
            counter++;
        }

        if(counter < 10) {
            cout << "The entire file has been displayed! ";
        }
        else {
            cout << "The first 10 lines of the file has been displayed!";
        }

        // Close the file.
        nameFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }


    return 0;
}