/* Write a program that has an array of at least 10 string objects that hold people’s
names and phone numbers. You may make up your own strings, or use the following:
"Alejandra Cruz, 555-1223"
"Joe Looney, 555-0097"
"Geri Palmer, 555-8787"
"Li Chen, 555-1212"
"Holly Gaddis, 555-8878"
"Sam Wiggins, 555-0998"
"Bob Kain, 555-8712"
"Tim Haynes, 555-7676"
"Warren Gaddis, 555-9037"
"Jean James, 555-4939"
"Ron Palmer, 555-2783"
The program should ask the user to enter a name or partial name to search for in the
array. Any entries in the array that match the string entered should be displayed. For
example, if the user enters “Palmer” the program should display the following names
from the list:
Geri Palmer, 555-8787
Ron Palmer, 555-2783 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

const char* contacts[] = {
    "Alejandra Cruz, 555-1223",
    "Joe Looney, 555-0097",
    "Geri Palmer, 555-8787",
    "Li Chen, 555-1212",
    "Holly Gaddis, 555-8878",
    "Sam Wiggins, 555-0998",
    "Bob Kain, 555-8712",
    "Tim Haynes, 555-7676",
    "Warren Gaddis, 555-9037",
    "Jean James, 555-4939",
    "Ron Palmer, 555-2783"
};

void searcher(const char*);

int main() {

    char whodis[100];

    cout << "Contacts:" << endl;
    for (string contact : contacts) {
        cout << contact << endl;
    }

    cout << "Enter a name/number you would like to find in the contacts list: ";
    cin.getline(whodis, sizeof(whodis));

    searcher(whodis);

    return 0;
}

void searcher(const char* line) {
    int length, count;
    length = strlen(line);

    for (const char* contact : contacts) {
        if (strstr(contact, line) != nullptr) {
            cout << contact << endl;
            count++;
        }

    }
    cout << "There are a total of " << count << " people matching said details. ";
    
}
