/* Imagine you are developing a software package that requires users to enter their own
passwords. Your software requires that users’ passwords meet the following criteria:
• The password should be at least six characters long.
• The password should contain at least one uppercase and at least one lowercase letter.
• The password should have at least one digit.
Write a program that asks for a password and then verifies that it meets the stated
criteria. If it doesn’t, the program should display a message telling the user why. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

void linefunction(char*, int);

void criteria(char*);

int c1(char*, int); // criterias
int c2(char*, int);
int c3(char*, int);
int c4(char*, int);

int main() {

    char *password = nullptr;
    int SIZE;

    cout << "What is the length of your string? ";
    cin >> SIZE;  

    password = new char[SIZE + 1];

    cin.ignore();
    linefunction(password, SIZE); 

    criteria(password);

    return 0;
}

void linefunction(char* array, int SIZE) {
    cout << "Input a password no more than " << (SIZE) << " in length. " << endl;
    cin.getline(array, SIZE + 1);
}

void criteria(char* str) {

    int count1 = 0, 
        count2 = 0, 
        count3 = 0, 
        count4 = 0,
        total = 0;

    total += c1(str, count1);
    total += c2(str, count2);
    total += c3(str, count3);
    total += c4(str, count4);    

    if(total == 0) {
        cout << "The password works perfectly!" << endl;
    }

    while(total > 0) { // goofy loop

        if (total >= 40) {
            cout << "The password should have at least one digit." << endl;
            total -= 40;
        }   
        else if (total >= 20) {
            cout << "The password should contain at least one lowercase." << endl;
            total -= 20;
        }  
        else if (total >= 10) {
            cout << "The password should contain at least one uppercase." << endl;
            total -= 10;
        } 
        else if (total >= 1) {
            cout << "The password should be at least six characters long." << endl;
            total -= 1;
        }

    }

}

int c1(char* str, int count) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    if(count < 6) {
        total += 1;
    }

    return total;
}

int c2(char* str, int count) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if(isupper(str[i])) {
                count++;
            }
        }
    }
    if(count == 0) {
        total += 10;
    }

    return total;
}

int c3(char* str, int count) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            if(islower(str[i])) {
                count++;
            }
        }
    }
    if(count == 0) {
        total += 20;
    }

    return total;
}

int c4(char* str, int count) {

    int total = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum(str[i])) {
            if(isdigit(str[i])) {
                count++;
            }
        }
    }
    if(count <= 0) {
        total += 40;
    }

    return total;

}
// doing it in 4 functions make it less clumpy