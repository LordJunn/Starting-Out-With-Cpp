#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store division data
struct Division {
    string name;
    double sales[4]; // Quarterly sales
};

int main() {
    const int numDivisions = 4;
    Division divisions[numDivisions] = {{"East"}, {"West"}, {"North"}, {"South"}};

    // Open file for reading
    ifstream inFile("sales_data.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // Read data from file
    for (int i = 0; i < numDivisions; ++i) {
        cout << "Reading data for " << divisions[i].name << " division:" << endl;
        for (int j = 0; j < 4; ++j) {
            string label;
            inFile >> label >> divisions[i].sales[j];
            cout << label << " " << divisions[i].sales[j] << endl;
            cout << "wait whats a label " << divisions[i].sales[j] << endl;
        }
        cout << endl;
    }

    // Close file
    inFile.close();

    // Calculate and display figures
    double totalQuarterlySales[4] = {0};
    double totalYearlySales[numDivisions] = {0};
    double totalCorporateSales = 0;

    // Calculate total corporate sales for each quarter
    for (int i = 0; i < numDivisions; ++i) {
        for (int j = 0; j < 4; ++j) {
            totalQuarterlySales[j] += divisions[i].sales[j];
            totalYearlySales[i] += divisions[i].sales[j];
            totalCorporateSales += divisions[i].sales[j];
        }
    }

    // Calculate average quarterly sales for the divisions
    double averageQuarterlySales[numDivisions];
    for (int i = 0; i < numDivisions; ++i) {
        averageQuarterlySales[i] = totalYearlySales[i] / 4.0;
    }

    // Find the highest and lowest quarters for the corporation
    double highestQuarterlySales = totalQuarterlySales[0];
    double lowestQuarterlySales = totalQuarterlySales[0];
    int highestQuarter = 1;
    int lowestQuarter = 1;
    for (int i = 1; i < 4; ++i) {
        if (totalQuarterlySales[i] > highestQuarterlySales) {
            highestQuarterlySales = totalQuarterlySales[i];
            highestQuarter = i + 1;
        }
        if (totalQuarterlySales[i] < lowestQuarterlySales) {
            lowestQuarterlySales = totalQuarterlySales[i];
            lowestQuarter = i + 1;
        }
    }

    // Display results
    cout << "Total corporate sales for each quarter:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Quarter " << i + 1 << ": $" << totalQuarterlySales[i] << endl;
    }
    cout << endl;

    cout << "Total yearly sales for each division:" << endl;
    for (int i = 0; i < numDivisions; ++i) {
        cout << divisions[i].name << ": $" << totalYearlySales[i] << endl;
    }
    cout << endl;

    cout << "Total yearly corporate sales: $" << totalCorporateSales << endl << endl;

    cout << "Average quarterly sales for the divisions:" << endl;
    for (int i = 0; i < numDivisions; ++i) {
        cout << divisions[i].name << ": $" << averageQuarterlySales[i] << endl;
    }
    cout << endl;

    cout << "Highest quarter for the corporation: Quarter " << highestQuarter << " ($" << highestQuarterlySales << ")" << endl;
    cout << "Lowest quarter for the corporation: Quarter " << lowestQuarter << " ($" << lowestQuarterlySales << ")" << endl;

    return 0;
}
