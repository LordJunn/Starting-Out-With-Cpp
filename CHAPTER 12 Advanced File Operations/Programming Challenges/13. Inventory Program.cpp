/* Write a program that uses a structure to store the following inventory data in a file:
Item Description
Quantity on Hand
Wholesale Cost
Retail Cost
Date Added to Inventory
The program should have a menu that allows the user to perform the following tasks:
• Add new records to the file.
• Display any record in the file.
• Change any record in the file.
Input Validation: The program should not accept quantities, or wholesale or retail
costs, less than 0. The program should not accept dates that the programmer deter-
mines are unreasonable. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from PC14 C11

struct inventory {
    string desc;
    int quantity;
    double wholesale, retail;
    int date;
};

void displayMenu();
void tableHeader();
int checker(int&, int, int);
double checker(double&, double, double);
void choices(inventory, int);
void addNew(inventory&);
void display(inventory&);
void change(inventory&);
void wipeFile(string);

int totalItems = 0;
int currentItems = 0;
const int maxRecords = 3;

int main() {

    inventory record;
    int choice;
    char saver;

    cout << "It is recomended to start with a clean save file so Q14 will work smoothly. \n";
    cout << "Would you like to wipe the current save file (Press N) ? ";
    cin >> saver;
    saver = toupper(saver);
    if(saver == 'N') {
        wipeFile("PC13C12.dat");
        cout << "File wiped successfully, creating a new save. \n";
    }
    else {
        cout << "Previous file preserved. \n";
    }

    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = checker(choice, 1, 4);
        choices(record, choice);        
    }while(choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\n~ Inventory Program ~\n";
    cout << "1. Add new record\n";
    cout << "2. Display record\n";
    cout << "3. Change record\n";
    cout << "4. Exit\n";
}

void tableHeader() {
    cout << setw(20) << left << "Item Description";
    cout << setw(20) << left << "Quantity on Hand";
    cout << setw(20) << left << "Wholesale Cost";
    cout << setw(20) << left << "Retail Cost";
    cout << setw(20) << left << "Date" << endl;    

}

void choices(inventory record, int choice) {

    int thonk;

    switch(choice) {
        case 1:
            cout << "Adding... \n";
            addNew(record);
            break;

        case 2:
            cout << "Displaying... \n";
            cin.ignore();
            display(record);
            break;

        case 3:
            cout << "Changing...\n ";
            cin.ignore();
            change(record);
            break;

        case 4:
            cout << "Exiting!";
            break;

        default:
            cout << "???";
        
    }

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

double checker(double &x, double i, double j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

void addNew(inventory &record) { // stolen from 12-20

    // Open the file for binary output.
    fstream inventory("PC13C12.dat", ios::out | ios::app | ios::binary);

    if(totalItems >= maxRecords) {
        cout << "Full! " << endl;
        inventory.close();
        return;
    }
    else {
    cout << "Adding new records... \n";

    // Create an empty InventoryItem structure.
    record = {"", 0, 0.0};

    // Write the blank records
    for (int count = currentItems; count < maxRecords; count++) {
        
        inventory.write(reinterpret_cast<char *>(&record), sizeof(record));
        totalItems++;
        currentItems++;
    }
    cout << "Added " << currentItems << " items into the list. \n ";
    inventory.close();
    }

}

void display(inventory &record) { // stolen from 12-21

    // Open the file for binary input.
    fstream inventory("PC13C12.dat", ios::in | ios::binary);

    int count = 0;

    if(count == 0) {
        tableHeader();
        count++;
    }

    // Now read and display the records
    inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
    while (!inventory.eof()) {
        cout << setw(20) << left << record.desc;
        cout << setw(20) << left << record.quantity;
        cout << setw(20) << left << record.wholesale;
        cout << setw(20) << left << record.retail;
        cout << setw(20) << left << record.date << endl;
        inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
    }

    // Close the file.
    inventory.close();

}

void change(inventory &record) { // stolen from 12-22

    int recNum;

    // Open the file in binary mode for input and output
    fstream inventory("PC13C12.dat", ios::in | ios::out | ios::binary);

    // Get the record number of the desired record.
    cout << "Which record do you want to edit? ";
    recNum = checker(recNum, 1, 999);
    recNum--;

    // Move to the record and read it.
    inventory.seekg(recNum * sizeof(record), ios::beg);
    inventory.read(reinterpret_cast<char *>(&record), sizeof(record));

    // Display the record contents.
    cout << "Description: ";
    cout << record.desc << endl;
    cout << "Quantity: ";
    cout << record.quantity << endl;
    cout << "Price: ";
    cout << record.wholesale << endl;
    cout << "Price: ";
    cout << record.retail << endl;
    cout << "Date: ";
    cout << record.date << endl;    

    // Get the new record data.
    cout << "Enter the new data for "<< record.desc << ":\n";
    cin.ignore();
    cout << "Description: ";
    getline(cin, record.desc);
    cout << "Quantity: ";
    record.quantity = checker(record.quantity, 0, 999);
    cout << "Wholesale Price: $";
    record.wholesale = checker(record.wholesale, 0, 999);
    cout << "Retail Price: $";
    record.retail = checker(record.retail, 0, 999);
    cout << "Date: ";
    record.date = checker(record.date, 1, 9); // Example validation for date range

    // Move back to the beginning of this record's position.
    inventory.seekp(recNum * sizeof(record), ios::beg);

    // Write the new record over the current record.
    inventory.write(reinterpret_cast<char *>(&record), sizeof(record));

    // Close the file.
    inventory.close();

}

void wipeFile(string filename) { // stolen from gpt
    ofstream file(filename, ios::trunc); // Open file in trunc mode, which truncates the file if it exists, or creates a new empty file
    file.close(); // Close the file
}
