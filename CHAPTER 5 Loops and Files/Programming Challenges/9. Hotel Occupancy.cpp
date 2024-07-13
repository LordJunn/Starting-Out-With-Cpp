/* Write a program that calculates the occupancy rate for a hotel. The program should
start by asking the user how many floors the hotel has. A loop should then iterate once
for each floor. In each iteration, the loop should ask the user for the number of rooms
on the floor and how many of them are occupied. After all the iterations, the program
should display how many rooms the hotel has, how many of them are occupied, how
many are unoccupied, and the percentage of rooms that are occupied. The percentage
may be calculated by dividing the number of rooms occupied by the number of rooms.

NOTE: It is traditional that most hotels do not have a thirteenth floor. The loop in
this program should skip the entire thirteenth iteration. 

Input Validation: Do not accept a value less than 1 for the number of floors. Do not
accept a number less than 10 for the number of rooms on a floor.*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    float floors = 0, 
        rooms = 0, 
        occupied = 0, 
        unoccupiedt = 0, 
        roomst = 0, 
        occupiedt = 0, 
        maxrooms = 0; // for some reason if i dont set it to 0, itll show 8 digits.

    float occupiedp;

    cout << "How many floors the hotel has?" << endl;
    cin >> floors;

    while (floors <= 0) {
        cout << "I don't remember being in an underground hotel." << endl;
        cout << "How many (above the ground) floors the hotel has?" << endl;
        cin >> floors;
    }

    for (int i = 1; i <= floors; i++) {

        if (i == 13) {
            cout << "Floor" << i << " is missing.\n";
            continue;  // Immediately start the next iteration
        }        

        cout << "How many rooms does floor " << i << " has?" << endl;
        cin >> rooms;

        while (rooms < 10) {
            cout << "Not sure why I can't type under 10 rooms per floor." << endl;
            cout << "How many rooms does floor " << i << " has?" << endl;
            cin >> rooms;
        }  

        roomst += rooms;
        maxrooms = rooms;

        cout << "How many rooms are occupied on floor " << i << " ?" << endl;
        cin >> occupied;

        while (maxrooms < occupied) {
            cout << "It seems like we have overbooked, is there anyone sleeping on the hallway?" << endl;
            cout << "How many rooms are occupied on floor " << i << " ?" << endl;
            cin >> occupied;
        }      

        occupiedt += occupied;     

    }

    cout << "Total rooms the hotel has = " << roomst << endl;
    cout << "Total occupied rooms the hotel has = " << occupiedt << endl;

    unoccupiedt = roomst - occupiedt;

    cout << "Total unoccupied rooms the hotel has = " << unoccupiedt << endl;

    occupiedp = 100 * (occupiedt/roomst) ;

    cout << "Total percentage of occupied rooms the hotel has = " << occupiedp << "%" << endl;

    return 0;
}