/* Write a program that simulates inventory bins in a warehouse. Each bin holds a
number of the same type of parts. The program should use a structure that keeps the
following data:
Description of the part kept in the bin
Number of parts in the bin
The program should have an array of 10 bins, initialized with the following data:

Part Description    Number of Parts in the Bin
Valve                           10
Bearing                         5
Bushing                         15
Coupling                        21
Flange                          7
Gear                            5
Gear Housing                    5
Vacuum Gripper                  25
Cable                           18
Rod                             12

The program should have the following functions:
AddParts: a function that increases a specific bin’s part count by a specified number.
RemoveParts: a function that decreases a specific bin’s part count by a specified number.
When the program runs, it should repeat a loop that performs the following steps: The
user should see a list of what each bin holds and how many parts are in each bin.
The user can choose to either quit the program or select a bin. When a bin is selected, the
user can either add parts to it or remove parts from it. The loop then repeats, showing
the updated bin data on the screen.

Input Validation: No bin can hold more than 30 parts, so don’t let the user add more
than a bin can hold. Also, don’t accept negative values for the number of parts being
added or removed. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct bins{
    string name;
    int number;
};

const int binAmount = 10,
          binMax = 30;

bins part[binAmount] = {
    {"Valve", 10},           // Part Description: Valve, Number of Parts in the Bin: 10
    {"Bearing", 5},          // Part Description: Bearing, Number of Parts in the Bin: 5
    {"Bushing", 15},         // Part Description: Bushing, Number of Parts in the Bin: 15
    {"Coupling", 21},        // Part Description: Coupling, Number of Parts in the Bin: 21
    {"Flange", 7},           // Part Description: Flange, Number of Parts in the Bin: 7
    {"Gear", 5},             // Part Description: Gear, Number of Parts in the Bin: 5
    {"Gear Housing", 5},     // Part Description: Gear Housing, Number of Parts in the Bin: 5
    {"Vacuum Gripper", 25},  // Part Description: Vacuum Gripper, Number of Parts in the Bin: 25
    {"Cable", 18},           // Part Description: Cable, Number of Parts in the Bin: 18
    {"Rod", 12}              // Part Description: Rod, Number of Parts in the Bin: 12
};

void displayMenu();
void choices(bins[], int);
void tableHeader();
void displayBins(bins part[]);
void AddParts(bins*);
void RemoveParts(bins*);
int checker(int&, int, int);


int main() {

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = checker(choice, 1, 4);
        choices(part, choice);        
    }while(choice != 4);


    return 0;
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Display bin details \n";
    cout << "2. Add a bins parts \n";
    cout << "3. Remove a bins parts \n";  
    cout << "4. Exit \n";    
}

void choices(bins part[], int choice) {

    int thonk;

    switch(choice) {
        case 1:
            cout << "Displaying... \n";
            displayBins(part);
            break;

        case 2:
            cout << "Which part would you like to add (index)? ";
            cin.ignore();
            thonk = checker(thonk, 1, 10);
            AddParts(&part[thonk - 1]);
            break;

        case 3:
            cout << "Which part would you like to reduce (index)? ";
            cin.ignore();
            thonk = checker(thonk, 1, 10);
            RemoveParts(&part[thonk - 1]);
            break;

        case 4:
            cout << "Exiting!";
            break;

        default:
            cout << "???";
        
    }

}

void tableHeader() {
    cout << setw(20) << left << "Part Description";
    cout << setw(15) << left << "Number of Parts" << endl;
}

void displayBins(bins part[]) {
    for (int i = 0; i < binAmount; i++) {

        if(i == 0) {
            tableHeader();
        }

        cout << setw(20) << left << part[i].name;
        cout << setw(10) << left << part[i].number << endl;
    }
}

void AddParts(bins* part) {

    int tambah;

    if(part->number >= binMax) {
        cout << "Full!" << endl;
    }
    else {
        cout << "How many more " << part->name << " would you like to add? ";
        cin.ignore();
        tambah = checker(tambah, 1, (binMax - part->number));
        part->number = part->number + tambah;
        cout << part->name << " successfully increased by " << tambah << "!" << endl;
    }

    tableHeader();
    cout << setw(20) << left << part->name;
    cout << setw(10) << left << part->number << endl;


}

void RemoveParts(bins* part) {

    int kurang;

    if(part->number <= 0) {
        cout << "Empty!" << endl;
    }
    else {
        cout << "How many " << part->name << " would you like to remove? ";
        cin.ignore();
        kurang = checker(kurang, 1, (part->number));
        part->number = part->number - kurang;
        cout << part->name << " successfully reduced by " << kurang << "!" << endl;
    }

    tableHeader();
    cout << setw(20) << left << part->name;
    cout << setw(10) << left << part->number << endl;


}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

