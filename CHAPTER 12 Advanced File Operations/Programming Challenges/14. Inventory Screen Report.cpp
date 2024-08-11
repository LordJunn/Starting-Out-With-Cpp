/* Write a program that reads the data in the file created by the program in Programming
Challenge 13. The program should calculate and display the following data:
• The total wholesale value of the inventory
• The total retail value of the inventory
• The total quantity of all items in the inventory */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

struct inventory {
    string desc;
    int quantity;
    double wholesale, retail;
    int date;
};

void tableHeader();
void display(inventory&);

double totalw, totalr, totalq;

int main() {

    inventory record;

    display(record);

    cout << "The total wholesale value of the inventory: $" << totalw << endl;
    cout << "The total retail value of the inventory: $" << totalr << endl;
    cout << "The total quantity of all items in the inventory: " << totalq << endl;

    return 0;
}

void tableHeader() {
    cout << setw(20) << left << "Item Description";
    cout << setw(20) << left << "Quantity on Hand";
    cout << setw(20) << left << "Wholesale Cost";
    cout << setw(20) << left << "Retail Cost";
    cout << setw(20) << left << "Date" << endl;    

}

void display(inventory &record) { // wait its fine for PC13C12, why not here

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
        totalq += record.quantity;
        
        cout << setw(20) << left << record.wholesale;
        totalw += (record.wholesale * record.quantity);

        cout << setw(20) << left << record.retail;
        totalr += (record.retail * record.quantity);

        cout << setw(20) << left << record.date << endl;
        inventory.read(reinterpret_cast<char *>(&record), sizeof(record));
    }

    // Close the file.
    inventory.close();

}