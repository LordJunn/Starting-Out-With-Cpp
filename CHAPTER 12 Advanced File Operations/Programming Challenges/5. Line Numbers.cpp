/* (This assignment could be done as a modification of the program in Programming
Challenge 2.) Write a program that asks the user for the name of a file. The program
should display the contents of the file on the screen. Each line of screen output should
be preceded with a line number, followed by a colon. The line numbering should start
at 1. Here is an example:
1:George Rolland
2:127 Academy Street
3:Brasstown, NC 28706
If the file’s contents won’t fit on a single screen, the program should display 24 lines of
output at a time, and then pause. Each time the program pauses, it should wait for the
user to strike a key before the next 24 lines are displayed. 

NOTE: Using an editor, you should create a simple text file that can be used to test
this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from PC2 C12

int main() {
    string input;      // To hold file input
    string filename;
    fstream nameFile;  // File stream object
    int counter = 0,
        pausechamp = 0;

    cout << "Name of a file? ";
    getline(cin, filename);

    nameFile.open(filename, ios::out);

    // If the file was successfully opened, continue.
    if (nameFile) {
        // Read an item from the file.
        getline(nameFile, input);

        // While the last read operation
        // was successful, continue.
        while (nameFile) {
            // Display the last item read.
            cout << (counter + 1) << ":";
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