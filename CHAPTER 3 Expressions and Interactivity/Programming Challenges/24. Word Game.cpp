/* Write a program that plays a word game with the user. The program should ask the
user to enter the following:
• His or her name
• His or her age
• The name of a city
• The name of a college
• A profession
• A type of animal
• A pet’s name
After the user has entered these items, the program should display the following story,
inserting the user’s input into the appropriate locations:
There once was a person named NAME who lived in CITY. At the age of
AGE, NAME went to college at COLLEGE. NAME graduated and went to work
as a PROFESSION. Then, NAME adopted a(n) ANIMAL named PETNAME. They
both lived happily ever after! */

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main() {
    
    string name, age, city, college, profession, animal, pet;

// Prompt for and receive input
    cout << "Enter your name: ";
    getline(cin, name); // Use getline for spaces in names

    cout << "Enter your age: ";
    getline(cin, age);

    cout << "Enter the name of a city: ";
    getline(cin, city);

    cout << "Enter the name of a college: ";
    getline(cin, college);

    cout << "Enter your profession: ";
    getline(cin, profession);

    cout << "Enter a type of animal: ";
    getline(cin, animal);

    cout << "Enter your pet's name: ";
    getline(cin, pet);

    cout << "There once was a person named " << name << " who lived in " << city << "." << endl;
    cout << "At the age of " << age << ", " << name << " went to college at " << college << "." << endl; 
    cout << name << " graduated and went to work as a " << profession << "." << endl; 
    cout << name << " adopted a(n) " << animal << " named " << pet << "." << endl;  
    cout << "They both lived happily ever after!" << endl; 

    return 0;
}