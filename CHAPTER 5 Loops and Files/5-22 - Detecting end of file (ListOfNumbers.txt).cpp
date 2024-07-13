// This program reads data from a file.
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream inputFile;
    int number;

    // Open the file.
    inputFile.open("ListOfNumbers.txt");

    // Read the numbers from the file and
    // display them.
    while (inputFile >> number) {
        cout << number << endl;
    }

    // Close the file.
    inputFile.close();
    return 0;
}