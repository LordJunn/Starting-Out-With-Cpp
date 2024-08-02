/* Add a function to Programming Challenge 7 that allows the user to search the struc-
ture array for a particular customer’s account. It should accept part of the customer’s
name as an argument and then search for an account with a name that matches it. All
accounts that match should be displayed. If no account matches, a message saying so
should be displayed. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct cusdata {
    string name,   
           address, city, state;

    int zip,
        telephone,
        balance,
        date;
};

const int maxCus = 10,
          maxlen = 999;
int telemin = 1, 
    telemax = 9;

int checker(int&, int);
int checker(int&, int, int);
void displayMenu();
void choices(cusdata[], int, int&);
void newAcc(cusdata[], int&);
void updateAcc(cusdata[], int&);
void searchAcc(cusdata[], int&, string);
void displayAllData(const cusdata[], int);
void tableHeader();

int main() {

    cusdata customer[maxCus];
    int choice;
    int totalcus = 0;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        choice = checker(choice, 1, 5);
        choices(customer, choice, totalcus);
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
    cout << "1. Add New Account\n";
    cout << "2. Update Existing Account\n";
    cout << "3. Display All Account Data\n";
    cout << "4. Search For Account\n";    
    cout << "5. Exit\n";
}

void choices(cusdata customer[], int choice, int &totalcus) {

    int who;

    switch(choice) {
        case 1:
            cout << "Creating... \n";
            cin.ignore();
            newAcc(customer, totalcus);
            break;
        
        case 2:
            cout << "Updating... \n ";
            cin.ignore();
            updateAcc(customer, totalcus);
            break;

        case 3:
            cout << "Displaying... \n";
            displayAllData(customer, totalcus);
            break;

        case 4:
            cout << "Searching... \n";
            char query[maxlen];
            cin.ignore();
            cout << "Enter a name to search for: ";
            cin.getline(query, maxlen);
            searchAcc(customer, totalcus, query);
            break;

        case 5:
            cout << "Exit!" << endl;
            break;

        default:
            cout << "This is NOT a valid option.";

    }

}

void newAcc(cusdata customers[], int &totalcust) {

    if(totalcust >= maxCus) {
        cout << "Damn it's full. ";
        return;
    }

    cusdata newCus;

    cout << "Customer's name? ";
    getline(cin, newCus.name);

    cout << newCus.name << "'s address? ";
    getline(cin, newCus.address);
    cout << newCus.name << "'s city? ";
    getline(cin, newCus.city);
    cout << newCus.name << "'s state? ";
    getline(cin, newCus.state);

    cout << newCus.name << "'s ZIP? ";
    newCus.zip = checker(newCus.zip, 0);   
    cout << newCus.name << "'s telephone number? ";
    newCus.telephone = checker(newCus.telephone, telemin, telemax);
    cout << newCus.name << "'s account balance? ";
    newCus.balance = checker(newCus.balance, 0);        
    cout << newCus.name << "'s last payment date? ";
    newCus.date = checker(newCus.date, 0);  

    customers[totalcust++] = newCus;
    cout << newCus.name << "'s account added successfully. \n";

}

void updateAcc(cusdata customers[], int &totalcust) {
    if (totalcust == 0) {
        cout << "No customers to update.\n";
        return;
    }

    int accindex; // Index of the account to be updated
    cout << "Enter the index of the account to update (1-" << totalcust << "): ";
    accindex = checker(accindex, 1, totalcust);

    accindex--;

    // Input updated customer data
    cout << "Enter updated customer's name: ";
    cin.ignore();
    getline(cin, customers[accindex].name);
    cout << "Enter updated customer's address: ";
    getline(cin, customers[accindex].address);
    cout << "Enter updated customer's city: ";
    getline(cin, customers[accindex].city);
    cout << "Enter updated customer's state: ";
    getline(cin, customers[accindex].state);

    cout << "Enter updated customer's ZIP code: ";
    customers[accindex].zip = checker(customers[accindex].zip, 0);
    cout << "Enter updated customer's telephone number: ";
    customers[accindex].telephone = checker(customers[accindex].telephone, telemin, telemax);
    cout << "Enter updated customer's account balance: ";
    customers[accindex].balance = checker(customers[accindex].balance, 0);
    cout << "Enter updated customer's last payment date: ";
    customers[accindex].date = checker(customers[accindex].date, 0);

    cout << "Account updated successfully.\n";
}

void displayAllData(const cusdata customers[], int customerC) {
    if (customerC == 0) {
        cout << "No customers to display.\n";
        return;
    }

    // Display table header
    tableHeader();

    // Display customer data
    for (int i = 0; i < customerC; ++i) {
        cout << setw(20) << left << customers[i].name
             << setw(30) << left << customers[i].address
             << setw(15) << left << customers[i].city
             << setw(8) << left << customers[i].state
             << setw(10) << left << customers[i].zip
             << setw(15) << left << customers[i].telephone
             << setw(10) << left << customers[i].balance
             << setw(15) << left << customers[i].date << endl;
    }
}

void searchAcc(cusdata customer[], int &totalcus, string query) {
    bool found = false;
    int count = 0;

    cout << "Search results:\n";

    

    for (int i = 0; i < totalcus; ++i) {
        // Check if the search query is a substring of the customer's name


        if (customer[i].name.find(query) != string::npos) {
            // Display details of the matching account

            if(count == 0) {
                tableHeader();
            }

            cout << setw(20) << left << customer[i].name
                << setw(30) << left << customer[i].address
                << setw(15) << left << customer[i].city
                << setw(8) << left << customer[i].state
                << setw(10) << left << customer[i].zip
                << setw(15) << left << customer[i].telephone
                << setw(10) << left << customer[i].balance
                << setw(15) << left << customer[i].date << endl;
            found = true;

            count++;

        }
    }

    if (!found) {
        cout << "No matching account found.\n";
    }
}

void tableHeader() {

    cout << setw(20) << left << "Name"
         << setw(30) << left << "Address"
         << setw(15) << left << "City"
         << setw(8) << left << "State"
         << setw(10) << left << "ZIP"
         << setw(15) << left << "Telephone"
         << setw(10) << left << "Balance"
         << setw(15) << left << "Last Payment Date" << endl;

}
