/* Write a program that keeps track of a speakers’ bureau. The program should use a
structure to store the following data about a speaker:

    Name
    Telephone Number
    Speaking Topic
    Fee Required

The program should use an array of at least 10 structures. It should let the user enter
data into the array, change the contents of any element, and display all the data stored
in the array. The program should have a menu-driven user interface.
Input Validation: When the data for a new speaker is entered, be sure the user enters
data for all the fields. No negative amounts should be entered for a speaker’s fee. */

// im stealing the entirety of PC8 C11 no one can stop me
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct bureau {
    string name, topic;
    int telephone, fee;
};

const int maxStruct = 10,
          maxlen = 999;
int telemin = 1, 
    telemax = 9;

int checker(int&, int);
int checker(int&, int, int);
void displayMenu();
void choices(bureau[], int, int&);
void newAcc(bureau[], int&);
void updateAcc(bureau[], int&);
void displayAllData(const bureau[], int);
void tableHeader();

int main() {

    bureau speaker[maxStruct];
    int choice;
    int totalsp = 0;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = checker(choice, 1, 4);
        choices(speaker, choice, totalsp);
    } while(choice != 5);

    cout << "Program exiting!";

    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << ", but smaller than " << j << " .";
        cin.clear();
        cin >> x;
    }

    return x;

}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add New Speaker\n";
    cout << "2. Update Existing Speaker\n";
    cout << "3. Display All Speakers\n";
    cout << "4. Exit\n";
}

void choices(bureau speaker[], int choice, int &totalsp) {

    int who;

    switch(choice) {
        case 1:
            cout << "Creating... \n";
            cin.ignore();
            newAcc(speaker, totalsp);
            break;
        
        case 2:
            cout << "Updating... \n ";
            cin.ignore();
            updateAcc(speaker, totalsp);
            break;

        case 3:
            cout << "Displaying... \n";
            displayAllData(speaker, totalsp);
            break;

        case 4:
            cout << "Exit!" << endl;
            break;

        default:
            cout << "This is NOT a valid option.";

    }

}

void newAcc(bureau speakers[], int &totalsp) {

    if(totalsp >= maxStruct) {
        cout << "Damn it's full. ";
        return;
    }

    bureau newSpeaker;

    cout << "New speaker's name? ";
    getline(cin, newSpeaker.name);

    cout << newSpeaker.name << "'s telephone number? ";
    newSpeaker.telephone = checker(newSpeaker.telephone, telemin, telemax);
    cin.ignore();

    cout << newSpeaker.name << "'s speaking topic? ";
    getline(cin, newSpeaker.topic);

    cout << newSpeaker.name << "'s required fee? ";
    newSpeaker.fee = checker(newSpeaker.fee, 0);  
    cin.ignore();

    speakers[totalsp++] = newSpeaker;
    cout << newSpeaker.name << "'s data added successfully. \n";

}

void updateAcc(bureau speakers[], int &totalsp) {
    if (totalsp == 0) {
        cout << "No speakers to update.\n";
        return;
    }

    int accindex; // Index of the account to be updated
    cout << "Enter the index of the speaker to update (1-" << totalsp << "): ";
    accindex = checker(accindex, 1, totalsp);

    accindex--;

    // Input updated speaker data
    cout << "Enter updated speaker's name: ";
    cin.ignore();
    getline(cin, speakers[accindex].name);

    cout << "Enter updated speaker's speaking topic: ";
    getline(cin, speakers[accindex].topic);

    cout << "Enter updated speaker's telephone number: ";
    speakers[accindex].telephone = checker(speakers[accindex].telephone, telemin, telemax);

    cout << "Enter updated speaker's required fee: ";
    speakers[accindex].fee = checker(speakers[accindex].fee, 0);

    cout << "Account updated successfully.\n";
}

void displayAllData(const bureau speakers[], int customerC) {
    if (customerC == 0) {
        cout << "No speakers to display.\n";
        return;
    }

    // Display table header
    tableHeader();

    // Display speaker data
    for (int i = 0; i < customerC; ++i) {
        cout << setw(20) << left << speakers[i].name
             << setw(30) << left << speakers[i].telephone
             << setw(30) << left << speakers[i].topic
             << setw(15) << left << speakers[i].fee << endl;
    }
}

void tableHeader() {

    cout << setw(20) << left << "Name"
         << setw(30) << left << "Telephone Number"
         << setw(30) << left << "Speaking Topic"
         << setw(15) << left << "Required Fee" << endl;

}
