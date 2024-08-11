#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to store division data
struct Division {
    string name;
    double sales[4]; // Quarterly sales
};

// Function to validate sales input (non-negative numbers)
double validateSalesInput() {
    double input;
    cin >> input;
    while (input < 0) {
        cout << "Please enter a non-negative number: ";
        cin.clear();
        cin >> input;
    }
    return input;
}

int main() {
    const int numDivisions = 4;
    Division divisions[numDivisions] = {{"East"}, {"West"}, {"North"}, {"South"}};

    // Open file for writing
    ofstream outFile("sales_data.txt");
    if (!outFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Get sales data for each division
    for (int i = 0; i < numDivisions; ++i) {
        cout << "Enter quarterly sales for " << divisions[i].name << " division:" << endl;
        for (int j = 0; j < 4; ++j) {
            cout << "Quarter " << j + 1 << ": $";
            divisions[i].sales[j] = validateSalesInput();
        }
    }

    // Write data to file
    for (int i = 0; i < numDivisions; ++i) {
        outFile << "Division: " << divisions[i].name << endl;
        for (int j = 0; j < 4; ++j) {
            outFile << "Quarter " << j + 1 << ": $" << divisions[i].sales[j] << endl;
        }
        outFile << endl;
    }

    cout << "Sales data has been written to sales_data.txt" << endl;

    // Close file
    outFile.close();

    return 0;
}