/* If you have downloaded this book’s source code from the companion Web site, you
will find a file named text.txt in the Chapter 10 folder. (The companion Web site is
at www.pearsonhighered.com/gaddis.) Write a program that reads the file’s contents
and determines the following:
• The number of uppercase letters in the file
• The number of lowercase letters in the file
• The number of digits in the file */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

int itsUpper(string); // criterias
int itsLower(string);
int itsDigit(string);

int main() {

    const int AMOUNT = 9999;
    string alnum; // from PC11 C8
    int count = 0;
    ifstream inputFile; 

    int upper, lower, digit, length;

    // Open the file.
    inputFile.open("text.txt");

    // Read the numbers from the file into the line.
    string line;
    while (getline(inputFile, line)) { 
        alnum += line;
    }

    // Close the file.
    inputFile.close();

    cout << alnum << endl;

    upper = itsUpper(alnum);
    lower = itsLower(alnum);
    digit = itsDigit(alnum);

    cout << "The number of uppercase letters in the file: " << upper << endl;
    cout << "The number of lowercase letters in the file: " << lower << endl;
    cout << "The number of digits in the file: " << digit << endl;


    return 0;
}

int itsUpper(string str) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if(isupper(str[i])) {
                total++;
            }
        }
    }

    return total;
}

int itsLower(string str) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if(islower(str[i])) {
                total++;
            }
        }
    }

    return total;
}

int itsDigit(string str) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            if(isdigit(str[i])) {
                total++;
            }
        }
    }

    return total;
}


