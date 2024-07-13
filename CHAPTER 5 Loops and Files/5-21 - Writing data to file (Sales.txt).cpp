// This program reads data from a file.
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream outputFile;  // File stream object
    int numberOfDays;     // Number of days of sales
    double sales;         // Sales amount for a day

    // Get the number of days.
    cout << "For how many days do you have sales? ";
    cin >> numberOfDays;

    // Open a file named Sales.txt.
    outputFile.open("Sales.txt");

    // Get the sales for each day and write it
    // to the file.
    for (int count = 1; count <= numberOfDays; count++) {
        // Get the sales for a day.
        cout << "Enter the sales for day " << count << ": ";
        cin >> sales;

        // Write the sales to the file.
        outputFile << sales << endl;
    }

    // Close the file.
    outputFile.close();
    cout << "Data written to Sales.txt\n";
    return 0;
}// This program reads data from a file.
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