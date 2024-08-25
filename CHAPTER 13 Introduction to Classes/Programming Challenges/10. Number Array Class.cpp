/* Design a class that has an array of floating-point numbers. The constructor should
accept an integer argument and dynamically allocate the array to hold that many
numbers. The destructor should free the memory held by the array. In addition, there
should be member functions to perform the following operations:
• Store a number in any element of the array
• Retrieve a number from any element of the array
• Return the highest value stored in the array
• Return the lowest value stored in the array
• Return the average of all the numbers stored in the array
Demonstrate the class in a program. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std; // stealing from 13-17 header file

class Floaty{
   private:
    int* number; 
    int* list; // Pointer to the array.
    int elements; // Number of elements.
    bool isValid(int elem) { // Validates subscripts.
        bool status;

        if(elem < 0 || elem > elements) {
            status = false;
        }
        else {
            status = true;
        }

        return status;
    }

   public:
    Floaty(int size) { // Constructor
        list = new int[size];
        elements = size;

        for(int i = 0; i < size; i++) {
            list[i] = 0;
        }
        
    }

    ~Floaty() { // Destructor
        delete [] list; 
    };

    void setElem(int n, int e) {
        if(isValid(n)) {
            list[n] = e;
        }
        else {
            cout << "Error! \n";
            exit(EXIT_FAILURE);
        }
    }

    int getElem(int n) {
        if(isValid(n)) {
            return list[n];
        }
        else {
            cout << "Error! \n";
            exit(EXIT_FAILURE);
        }
    }

    int getHighest() {
        int highest = list[0];

        for(int i = 1; i < elements; i++) {
            if(list[i] > highest) {
                highest = list[i];
            }
        }
        return highest;
    }

    int getLowest() {
        int lowest = list[0];

        for(int i = 1; i < elements; i++) {
            if(list[i] < lowest) {
                lowest = list[i];
            }
        }
        return lowest;
    }
    
    double getAverage() {
        double total = 0;

        for(int i = 0; i < elements; i++) {
            total += static_cast<double>(list[i]);
        }
        total /= static_cast<double>(elements);
        return total;
    }

};

void displayMenu();

int main() {
    int keluasan, value, index, choice;

    cout << "Size of array? ";
    cin >> keluasan;

    Floaty numbers(keluasan);

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter index and value: ";
            cin >> index >> value;
            numbers.setElem(index, value);
            cout << "Stored " << value << " in index #" << index << endl;
            break;
        case 2:
            cout << "Enter index: ";
            cin >> index;
            cout << "Value at index " << index << ": " << numbers.getElem(index) << endl;
            break;
        case 3:
            cout << "Highest value: " << numbers.getHighest() << endl;
            break;
        case 4:
            cout << "Lowest value: " << numbers.getLowest() << endl;
            break;
        case 5:
            cout << "Average value: " << numbers.getAverage() << endl;
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}

void displayMenu() {
    cout << "\n1. Store a number in any element of the array\n";
    cout << "2. Retrieve a number from any element of the array\n";
    cout << "3. Return the highest value stored in the array\n";
    cout << "4. Return the lowest value stored in the array\n";
    cout << "5. Return the average of all the numbers stored in the array\n";
    cout << "6. Exit\n";
}