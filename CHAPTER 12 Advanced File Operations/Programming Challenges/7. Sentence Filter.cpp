/* Write a program that asks the user for two file names. The first file will be opened for
input and the second file will be opened for output. (It will be assumed that the first file
contains sentences that end with a period.) The program will read the contents of the first
file and change all the letters to lowercase except the first letter of each sentence, which
should be made uppercase. The revised contents should be stored in the second file.

NOTE: Using an editor, you should create a simple text file that can be used to test
this program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from 12-12

int main() {
    string fileName;  // To hold the file name
    char ch;          // To hold a character
    ifstream inFile;  // Input file
    int counter = 0;

    // Open a file for output.
    ofstream outFile("PC7C12out.txt");

    // Get the input file name.
    cout << "Enter a file name: ";
    cin >> fileName;

    // Open the file for input.
    inFile.open(fileName);

    // If the input file opened successfully, continue.
    if (inFile) {
        // Read a char from file 1.
        inFile.get(ch);

        // While the last read operation was successful, continue.
        while (inFile) {

            if(counter == 0) { // force upper for 1st char
                outFile.put(toupper(ch));
                counter++;
            }

            if(ch == '.') {

                if (!inFile) {
                    break; // If this is the last character, break the loop
                }

                // Write uppercase char to file 2.
                for(int i = 0; i < 2; i++) {

                    if (!inFile) {
                        goto end_of_loops; // end it all
                    }

                    outFile.put(ch);
                    inFile.get(ch);

                }
                outFile.put(toupper(ch));
                inFile.get(ch);
            }
            else {

                if(counter > 1) {
                    if (!inFile) {
                        break; // If this is the last character, break the loop
                    }
                    // Write lowercase char to file 2.
                    outFile.put(tolower(ch));
                    // Read another char from file 1.
                    inFile.get(ch);
    
                }
                else {
                    inFile.get(ch); 
                    counter++;                   
                }

            }

        }

        // Close the two files.
        end_of_loops:
        inFile.close();
        outFile.close();
        cout << "File conversion done.\n";
    } else
        cout << "Cannot open " << fileName << endl;
    return 0;
}