/* Write a program that asks the user for the name of a file. The program should display the
contents of the file on the screen. If the file’s contents won’t fit on a single screen, the pro-
gram should display 24 lines of output at a time, and then pause. Each time the program
pauses, it should wait for the user to strike a key before the next 24 lines are displayed.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // nah id steal from PC1 C12

int main() {
    string input;      // To hold file input
    string filename;
    fstream nameFile;  // File stream object
    int counter = 0,
        pausechamp = 0;

    cout << "Name of a file? ";
    getline(cin, filename);

    nameFile.open(filename, ios::in);

    // If the file was successfully opened, continue.
    if (nameFile) {
        // Read an item from the file.
        getline(nameFile, input);

        // While the last read operation
        // was successful, continue.
        while (nameFile) {
            // Display the last item read.
            cout << input << endl;

            // Read the next item.
            getline(nameFile, input);
            counter++;

            if((counter % 24) == 0) {
                cout << "We have reached " << counter << " lines of output now. " << endl;
                cout << "Press any key in order to continue. " << endl;
                pausechamp++;
                cin.get();
            }
        }

        if(counter < 24) {
            cout << "The file has less than 24 lines, so the pause did not happen. ";
        }
        else {
            cout << "The file has a total of " << counter << " lines, so the pause happened " << pausechamp << "x";
        }

        // Close the file.
        nameFile.close();
    } else {
        cout << "ERROR: Cannot open file.\n";
    }


    return 0;
}