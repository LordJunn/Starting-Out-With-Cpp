/* Write a program that asks the user for a file name. Assume the file contains a series of
numbers, each written on a separate line. The program should read the contents of the
file into an array and then display the following data:
• The lowest number in the array
• The highest number in the array
• The total of the numbers in the array
• The average of the numbers in the array
If you have downloaded this book’s source code from the companion Web site, you
will find a file named numbers.txt in the Chapter 07 folder. You can use the file to
test the program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int ArraySize = 12;
int numbers[ArraySize];

void getInfoFromFile(int[], string);
void getLowest(int[]);
void getHighest(int[]);
int getTotal(int[]);
void getAvg(double);

int main() {

    string fileName;

    cout << "File name to open? ";
    cin >> fileName;
    cout << endl;

    getInfoFromFile(numbers, fileName);
    getLowest(numbers);
    getHighest(numbers);
    int whole = getTotal(numbers);
    getAvg(whole);

    return 0;
}

void getInfoFromFile(int array[], string fileName) {

    ifstream inputFile;
    inputFile.open(fileName);

    if(inputFile) {
        cout << "File opened successfully." << endl;
        for(int count = 0; count < ArraySize; count++) {
            inputFile >> numbers[count];
        }
    }
    else {
        cout << "Nope, can't find or open that file." << endl;
        cout << "The program will now kill itself.";
        exit(0);
    }

    inputFile.close();
}

void getLowest(int array[]) {

    int scount = 0;
    int smallest = array[0];
    for (int i = 1; i < ArraySize; i++)
    {
        if (array[i] <= smallest) {
            smallest = array[i];
            scount++;
        }
    }
    cout << "The lowest number in the array = " << smallest << endl;
    
}

void getHighest(int array[]) {

    int hcount = 0;
    int highest = array[0];
    for (int i = 1; i < ArraySize; i++)
    {
        if (array[i] >= highest) {
            highest = array[i];
            hcount++;
        }
    }
    cout << "The highest number in the array = " << highest << endl;
    
}

int getTotal(int array[]) {

    int total = 0;

    for(int count = 0; count < ArraySize; count++) {
        total += numbers[count];
    }    
    cout << "The total of the numbers in the array = " << total << endl;

    return total;
}

void getAvg(double i) {

    double avg;
    avg = i/ArraySize;
    cout << "The average of the numbers in the array = " << avg << endl;

}

