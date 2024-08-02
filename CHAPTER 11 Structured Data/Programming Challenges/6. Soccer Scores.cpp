/* Write a program that stores the following data about a soccer player in a structure:

    Player’s Name
    Player’s Number
    Points Scored by Player

The program should keep an array of 12 of these structures. Each element is for a dif-
ferent player on a team. When the program runs it should ask the user to enter the data
for each player. It should then show a table that lists each player’s number, name, and
points scored. The program should also calculate and display the total points earned by
the team. The number and name of the player who has earned the most points should
also be displayed.

Input Validation: Do not accept negative values for players’ numbers or points scored. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct team {
    string name;
    int number;
    int points;
};

const int teamSize = 3;

int checker(int&, int);
void unique(team[], int);
int findHigh(team[]);

int main() {

    team players[teamSize];
    int total, mostp;

    for(int i = 0; i < teamSize; i++) {
        cout << "Player " << (i + 1) << "'s name? ";
        getline(cin, players[i].name);

        cout << players[i].name << "'s number? ";
        players[i].number = checker(players[i].number, 0);
        unique(players, i);

        cout << "Points scored by "<< players[i].name << " ? ";
        players[i].points = checker(players[i].points, -1);

        total +=  players[i].points;
        cin.ignore();      
    }

    mostp = findHigh(players);

    cout << "Total points earned by the team: " << total << endl;

    cout << players[mostp].name << ", who is player number " << players[mostp].number << 
    " has scored the most points, which is " << players[mostp].points << endl;

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

void unique(team players[], int index) {
    bool unique;
    do {
        unique = true;
        // Check if the number is unique
        for (int j = 0; j < index; j++) {
            if (players[index].number == players[j].number) {
                unique = false;
                cout << "Player number must be unique. Please choose another number." << endl;
                cout << "Player " << players[index].name << "'s number? ";
                players[index].number = checker(players[index].number, 1);
                break;
            }
        }
    } while (!unique);
}

int findHigh(team players[]) {
    
    int highest = players[0].points;
    for(int i = 1; i < teamSize; i++) {
        if(players[i].points > highest) {
            highest = i;
        }
    }

    return highest;
}

