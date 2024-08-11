/* Write a program that reads the data in the file created by the program in Programming
Challenge 11. The program should calculate and display the following figures:
• Total corporate sales for each quarter 
• Total yearly sales for each division 
• Total yearly corporate sales
• Average quarterly sales for the divisions 
• The highest and lowest quarters for the corporation */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

struct companyD {
    string division;
    double Q1S;
    double Q2S;
    double Q3S;
    double Q4S;
    double total;
    double avg;
};

const int divisions = 4;

int highest(double[]);
int lowest(double[]);

int main() {
    fstream company;  // File stream object

    string corporate[divisions] = {"East", "West", "North", "South"};
    companyD cd[divisions];
    double quarter[divisions] = { 0, 0, 0, 0 };
    int index = 0, total = 0, avg = 0;
    int top, bottom;

    // Open the file for input in binary mode.
    company.open("PC11C12.dat", ios::in | ios::binary);

    // Test for errors.
    if (!company) {
        cout << "Error opening file. Program aborting.\n";
        return 0;
    }

    cout << "Here are the company in the file:\n\n";
    // Read the first record from the file.
    company.read(reinterpret_cast<char *>(&cd), sizeof(cd));

    // While not at the end of the file, display
    // the records.
    while (!company.eof()) {
        // Display the record.

        for(index = 0; index < divisions; index++) {

            cout << "Sales figure for " << corporate[index] << " division: " << endl;

            cout << "Quarter 1: $";
            cout << cd[index].Q1S << endl;
            quarter[0] += cd[index].Q1S;
            cout << "Quarter 2: $";
            cout << cd[index].Q2S << endl;
            quarter[1] += cd[index].Q2S;
            cout << "Quarter 3: $";
            cout << cd[index].Q3S << endl;
            quarter[2] += cd[index].Q3S;
            cout << "Quarter 4: $";
            cout << cd[index].Q4S << endl;
            quarter[3] += cd[index].Q4S;

            cd[index].total = cd[index].Q1S + cd[index].Q2S + cd[index].Q3S + cd[index].Q4S;
            cd[index].avg = cd[index].total/4;
            total += cd[index].total;

            // Read the next record from the file.
            company.read(reinterpret_cast<char *>(&cd), sizeof(cd));
        }

    }

    cout << "That's all the data in the file!\n\n\n\n\n";
    company.close();

    for (index = 0; index < divisions; index++) {
        cout << "Total corporate sales for quarter " << (index + 1) << ": $";
        cout << quarter[index] << endl;
    }

    for (index = 0; index < divisions; index++) {
        cout << "These are the sales figure for " << corporate[index] << " division." << endl;
        
        cout << fixed << setprecision(2);
        cout << "Total yearly sales: $" << cd[index].total << endl;
        cout << "Average quarterly sales: $" << cd[index].avg << endl;

        cout << endl;
    }

    cout << "Total yearly corporate sales: $" << total << endl;
    top = highest(&quarter[index]);
    cout << "The highest quarters for the corporation: Quarter " << top << endl;
    bottom = lowest(&quarter[index]);    
    cout << "The lowest quarters for the corporation: Quarter " << bottom << endl;

    return 0;
}

int highest(double q[]) {

    int top = q[0];
    int owo = 0;

    for(int i = 1; i < divisions; i++) {

        if (q[i] > top) {
            top = q[i];
            owo = i;
        }

    }

    owo++;
    return owo;

}

int lowest(double q[]) {

    int top = q[0];
    int owo = 0;

    for(int i = 1; i < divisions; i++) {

        if (q[i] < top) {
            top = q[i];
            owo = i;
        }

    }

    owo++;
    return owo;

}


