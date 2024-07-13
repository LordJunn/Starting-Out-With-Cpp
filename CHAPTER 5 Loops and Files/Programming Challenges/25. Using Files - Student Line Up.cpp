/* Modify the Student Line Up program described in Programming Challenge 14 so that
it gets the names from a file. Names should be read in until there is no more data to
read. If you have downloaded this book’s source code from the companion Web site,
you will find a file named LineUp.txt in the Chapter 05 folder. You can use this file to
test the program. (The companion Web site is at www.pearsonhighered.com/gaddis .) */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {

    int number;
    string student, first, last;

    ifstream input_file;

    input_file.open("LineUp.txt");

    if (input_file.fail())
    {
        cout << "Error opening the file." << endl;
    }

    if (input_file) {

        input_file >> student;
        
        first = last = student;

        while (input_file >> student) {
            cout << student << endl;


            if (student < first) {
                first = student;
            }  

            if (student > last) {
                last = student;
            }

    }
        input_file.close(); 
    }
    cout << endl;

    cout << "First in line: " << first << endl;
    cout << "Last in line: " << last << endl;

    return 0;
}