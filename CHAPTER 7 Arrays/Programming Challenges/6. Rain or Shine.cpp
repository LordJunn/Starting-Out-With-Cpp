/* An amateur meteorologist wants to keep track of weather conditions during the
past year’s three-month summer season and has designated each day as either rainy
(‘R’), cloudy (‘C’), or sunny (‘S’). Write a program that stores this information in a
3 × 30 array of characters, where the row indicates the month (0 = June, 1 = July,
2 = August) and the column indicates the day of the month. Note that data are not
being collected for the 31st of any month. The program should begin by reading the
weather data in from a file. Then it should create a report that displays, for each
month and for the whole three-month period, how many days were rainy, how many
were cloudy, and how many were sunny. It should also report which of the three
months had the largest number of rainy days. Data for the program can be found in
the RainOrShine.txt file. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

const int ROWS = 3, // months
          COLUMNS = 30; // days

string weatherFull[ROWS] = { "Rainy", "Cloudy", "Sunny"};
string months[ROWS] = { "June", "July", "August"};
char weatherShort[ROWS] = { 'R', 'C', 'S'};

void getInfoFromFile(char[][COLUMNS], string);
void displayMonths(const char[][COLUMNS], int);
void displayDays(const char[][COLUMNS], int);
void displayHighest(const char[][COLUMNS], char);

int main() {

    char weatherConditions[ROWS][COLUMNS];

    getInfoFromFile(weatherConditions, "RainOrShine.txt");

    for (int letter = 0; letter < ROWS; letter++) {
        displayDays(weatherConditions, letter);
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        displayMonths(weatherConditions, i);
    }
    cout << endl;

    displayHighest(weatherConditions, 'R');
    displayHighest(weatherConditions, 'C');
    displayHighest(weatherConditions, 'S');

    return 0;
}

void getInfoFromFile(char array[][COLUMNS], string file_name)
{
    ifstream inputFile;
    inputFile.open(file_name);

    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            inputFile >> array[row][col];
            cout << array[row][col];
        }
        cout << endl;
    }
    inputFile.close();
}

void displayDays(const char array[][COLUMNS], int i) {

    int total;
    for(int row = 0; row < ROWS; row++) {

        total = 0;

        for(int col = 0; col < COLUMNS; col++) {
            if (array[row][col] == weatherShort[i]) {
                total++;
            }   
        }
        cout << "Total " << weatherFull[i] << " days for " << months[row] << " = " << total << endl;
    }
}

void displayMonths(const char array[][COLUMNS], int i) {

    int total = 0;
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLUMNS; col++) {
            if (array[row][col] == weatherShort[i]) {
                total++;
            }   
        }
    }
    cout << "Total " << weatherFull[i] << " days for all months = " << total << endl;
}

void displayHighest(const char array[][COLUMNS], char w) {
    int sum;
    int totalDays[ROWS];
    string type;

    if(w == 'R') {
        type = weatherFull[0];
    }
    else if(w == 'C') {
        type = weatherFull[1];        
    }
    else if(w == 'S') {
        type = weatherFull[2];         
    }
    else {
        cout << w << " isn't a type of character I'm willing to allow." << endl;
        return;
    }

    for(int row = 0; row < ROWS; row++) {

        sum = 0;

        for(int col = 0; col < COLUMNS; col++) {
            if (array[row][col] == w) {
                sum++;
            }   
        }
        totalDays[row] = sum;
    }    

    int highest = totalDays[0];
    string highestName = months[0];

    for (int i = 1; i < ROWS; i++) {

        if(totalDays[i] > highest) {
            highest = totalDays[i];
            highestName = months[i];
        }

    }
    cout << highestName << " had the highest " << type << " days, with " << highest << " days." << endl;

}