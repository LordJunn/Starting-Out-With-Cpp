/* Write a program that asks the user for the name of a file. The program should display
the last 10 lines of the file on the screen (the “tail” of the file). If the file has fewer than
10 lines, the entire file should be displayed, with a message indicating the entire file
has been displayed.

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
        while (nameFile) {
         // Read the next item.
            counter++;
            //cout << counter << input << endl;
            getline(nameFile, input);
        }

        cout << "Alright I got all the lines now. " << endl;

        nameFile.clear(); // Clear the end-of-file flag
        nameFile.seekg(0, ios::beg);

        if (counter < 10) {
            cout << "The file has fewer than 10 lines." << endl;
        }
        else {
            cout << "Displaying the final 10 lines." << endl;
        }    

        // Move to the line where the tail starts
        for (int i = 0; i < counter - 10; i++) { 
            getline(nameFile, input);
        }
        
        // Display the remaining lines
        while (getline(nameFile, input)) {
            cout << input << endl;
        }

        nameFile.close();
        cout << "File closed. ";

    }else {
        cout << "ERROR: Cannot open file.\n";
    }
    
    return 0;
}