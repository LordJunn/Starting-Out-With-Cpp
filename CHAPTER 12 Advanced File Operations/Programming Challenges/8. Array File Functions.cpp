/* Write a function named arrayToFile. The function should accept three arguments:
the name of a file, a pointer to an int array, and the size of the array. The function
should open the specified file in binary mode, write the contents of the array to the file,
and then close the file.
Write another function named fileToArray. This function should accept three argu-
ments: the name of a file, a pointer to an int array, and the size of the array. The
function should open the specified file in binary mode, read its contents into the array,
and then close the file.
Write a complete program that demonstrates these functions by using the arrayToFile
function to write an array to a file, and then using the fileToArray function to read
the data from the same file. After the data are read from the file into the array, display
the array’s contents on the screen. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stolen from 12-14

void arrayToFile(string fileName, int* arr, int size);
void fileToArray(string fileName, int* arr, int size);

fstream ioFile;
ifstream inFile;  // Input file


int main() {
    string fileName;  // To hold the file name
    char ch;          // To hold a character

    const int SIZE = 10;
    int numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Get the input file name.
    cout << "Enter a file name: ";
    cin >> fileName;

    if(inFile) {
        arrayToFile(fileName, numbers, SIZE);
        cout << "Enter any key to continue, in case you'd like to see how the file contents look like before being wiped. " << endl;
        cin.ignore();
        cin.get();
        fileToArray(fileName, numbers, SIZE);
    } 
    else {
        cout << "Error!" << endl;
    }


    return 0;
}  

void arrayToFile(string fileName, int* arr, int size) {

    // Open the file for output in binary mode.
    cout << "Opening the specified file in binary mode" << endl;
    ioFile.open(fileName, ios::out | ios::binary);

    // Write the contents of the array to the file.
    cout << "Writing the contents of the array to the file\n";
    ioFile.write(reinterpret_cast<char *>(arr), sizeof(arr));

    // Close the file.
    cout << "Closing the file\n";
    ioFile.close();

}

void fileToArray(string fileName, int* arr, int size) {

    // Open the file for output in binary mode.
    cout << "Opening the specified file in binary mode" << endl;
    inFile.open(fileName, ios::in | ios::binary);

    // Read the contents of the file into the array.
    cout << "Reading its contents into the array\n";
    inFile.read(reinterpret_cast<char *>(arr), sizeof(arr));

    // Display the contents of the array.
    for (int count = 0; count < size; count++) {
        cout << arr[count] << " ";
    }
    cout << endl;

    // Close the file.
    cout << "Closing the file\n";
    inFile.close();

}

