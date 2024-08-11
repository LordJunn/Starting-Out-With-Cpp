/* Write a program that reads and prints a joke and its punch line from two different files.
The first file contains a joke, but not its punch line. The second file has the punch line as
its last line, preceded by “garbage.” The main function of your program should open the
two files and then call two functions, passing each one the file it needs. The first function
should read and display each line in the file it is passed (the joke file). The second function
should display only the last line of the file it is passed (the punch line file). It should find
this line by seeking to the end of the file and then backing up to the beginning of the last
line. Data to test your program can be found in the joke.txt and punchline.txt files. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

void joker(string&);
void puncher(string&);

int main() {
    string input;      // To hold file input
    string jokefile, punchfile;
    fstream nameFile;  // File stream object
    int counter = 0,
        pausechamp = 0;

    cout << "Name of a joke file? ";
    getline(cin, jokefile);

    cout << "Name of a punch file? ";
    getline(cin, punchfile);

    cout << "This is the joke + punchline: \n";
    joker(jokefile);
    puncher(punchfile);

    return 0;
}

void joker(string& filename) {
    fstream nameFile;

    nameFile.open(filename, ios::in);
    if (nameFile) {
        // Read an item from the file.
        getline(nameFile, filename);

        // While the last read operation
        // was successful, continue.
        while (nameFile) {
            // Display the last item read.
            cout << filename << endl;

            // Read the next item.
            getline(nameFile, filename);
        }    
        nameFile.close(); // Close the file.
    } 
    else {
        cout << "ERROR: Cannot open joke file.\n";
    }
}

void puncher(string& filename) {
    fstream nameFile;

    nameFile.open(filename, ios::in);
    if (nameFile) {
        // Read an item from the file.
        nameFile.seekg(8L, ios::beg); // garbage is 7 chars, 8th char is space
        getline(nameFile, filename);

        // While the last read operation
        // was successful, continue.
        while (nameFile) {
            // Display the last item read.
            cout << filename << endl;

            // Read the next item.
            getline(nameFile, filename);
        }    
        nameFile.close(); // Close the file.
    } 
    else {
        cout << "ERROR: Cannot open joke file.\n";
    }    
}

