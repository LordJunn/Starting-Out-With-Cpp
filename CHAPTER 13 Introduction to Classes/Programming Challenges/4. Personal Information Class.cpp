/* Design a class that holds the following personal data: name, address, age, and phone
number. Write appropriate accessor and mutator functions. Demonstrate the class by
writing a program that creates three instances of it. One instance should hold your infor-
mation, and the other two should hold your friends’ or family members’ information. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class PI {
   private:
    string name, address;
    int age, phone;

   public:
    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    int getAge() const {
        return age;
    }
    int getPhone() const {
        return phone;
    }

    // Mutator functions (i ttoally am just lazy)
    void setName(const string& newName) {
        name = newName;
    }
    void setAddress(const string& newAddress) {
        address = newAddress;
    }
    void setAge(int newAge) {
        age = newAge;
    }
    void setPhoneNumber(const int& newPhoneNumber) {
        phone = newPhoneNumber;
    }

};

int checker(int&, int, int);

int main() {

    PI mine, fwen, family;
    string na, ad;
    int ag, ph;

    cout << "What is my name? ";
    getline(cin, na);
    mine.setName(na);

    cout << "What is my address? ";
    getline(cin, ad);
    mine.setAddress(ad);

    cout << "What is my age? ";
    ag = checker(ag, 0, 100);
    mine.setAge(ag);

    cout << "What is my phone number? ";
    ph = checker(ph, 0, 9);
    mine.setPhoneNumber(ph);

    // Friend's information (no im totally not lazy)
    cout << "What is your friend's name? ";
    cin.ignore();
    getline(cin, na);
    fwen.setName(na);

    cout << "What is your friend's address? ";
    getline(cin, ad);
    fwen.setAddress(ad);

    cout << "What is your friend's age? ";
    ag = checker(ag, 0, 100);
    fwen.setAge(ag);

    cout << "What is your friend's phone number? ";
    ph = checker(ph, 0, 9);
    fwen.setPhoneNumber(ph);

    // Family member's information (no im totally not lazy)
    cout << "What is your family member's name? ";
    cin.ignore();
    getline(cin, na);
    family.setName(na);

    cout << "What is your family member's address? ";
    getline(cin, ad);
    family.setAddress(ad);

    cout << "What is your family member's age? ";
    ag = checker(ag, 0, 100);
    family.setAge(ag);

    cout << "What is your family member's phone number? ";
    ph = checker(ph, 0, 9);
    family.setPhoneNumber(ph);

    cout << left << setw(15) << "Name" << setw(15) << "Address" << setw(15) << "Age" << setw(15) << "Phone Number" << endl;

    cout << left << setw(15) << mine.getName() << setw(15) << mine.getAddress() 
    << setw(15) << mine.getAge() << setw(15) << mine.getPhone() << endl;

    cout << left << setw(15) << fwen.getName() << setw(15) << fwen.getAddress() 
    << setw(15) << fwen.getAge() << setw(15) << fwen.getPhone() << endl;

    cout << left << setw(15) << family.getName() << setw(15) << family.getAddress() 
    << setw(15) << family.getAge() << setw(15) << family.getPhone() << endl; 

    return 0;
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
