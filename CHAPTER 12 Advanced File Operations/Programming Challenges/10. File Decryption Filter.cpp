/* Write a program that decrypts the file produced by the program in Programming
Challenge 9. The decryption program should read the contents of the coded file, restore
the data to its original state, and write it to another file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int decryption(int, int);

int main() {
    string input;
    string fileName;  // To hold the file name
    char ch;          // To hold a character
    ifstream inFile;  // Input file
    int sus = 0;

    // Open a file for output.
    ofstream outFile("PC9C13out.txt");

    // Get the input file name.
    cout << "Name of the input file? ";
    getline(cin, fileName); // PC9C12out.txt

    // Open the file for input.
    inFile.open(fileName);
    int decrypt = 10;

    // If the file was successfully opened, continue.
    if (inFile) {
        // Read an item from the file.

        while (inFile.get(ch)) {

            sus = decryption(ch, decrypt);
            outFile.put(sus);

        }
        
        // Close the file
        inFile.close();
        cout << "File has been closed.\n";
    } else {
        cout << "ERROR: Cannot open file.\n";
    }

    return 0;
}

int decryption(int one, int two) {

    int outcome = one - two;

    cout << "Original: " << one;

    cout << " Changed: " << outcome << endl;
    return outcome;
}