/* Modify the Movie Data program written for Programming Challenge 1 to include two
additional members that hold the movie’s production costs and first-year revenues.
Modify the function that displays the movie data to display the title, director, release
year, running time, and first year’s profit or loss. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

struct MovieData {
    string title;
    string director;
    int year;
    int time;
    int cost;
    int revenue;
};

int main() {
    
    const int maxMovies = 2; // stolen idea from 11-4
    MovieData movie[maxMovies];
    int index;

    cout << "Enter the details for " << maxMovies << " movies." << endl;

    for (index = 0; index < maxMovies; index++) {
        cout << "Movie #" << (index + 1) << "'s title? ";
        getline(cin, movie[index].title);
        cout << "Movie #" << (index + 1) << "'s director? ";
        getline(cin, movie[index].director);  
        cout << "Movie #" << (index + 1) << "'s release year? ";
        cin >> movie[index].year;        
        cout << "Movie #" << (index + 1) << "'s running time (minutes)? ";
        cin >> movie[index].time;        
        cout << "Movie #" << (index + 1) << "'s production cost? ";
        cin >> movie[index].cost;        
        cout << "Movie #" << (index + 1) << "'s first year revenue? ";
        cin >> movie[index].revenue;      
        cin.ignore();
        cout << endl;
    }

    cout << "You have finished entering all the necessary data. " << endl;
    cout << "It is time to display them. " << endl;

    for (index = 0; index < maxMovies; index++) {
        int gross;

        cout << "Movie #" << (index + 1) << "'s title: " << movie[index].title << endl;
        cout << movie[index].title << "'s director: " << movie[index].director << endl;
        cout << movie[index].title << "'s release year: " << movie[index].year << endl;
        cout << movie[index].title << "'s running time (minutes): " << movie[index].time << endl; 

        gross = movie[index].revenue - movie[index].cost;

        if (gross < 0) {
            gross = abs(gross);
            cout << movie[index].title << "'s loss: " << gross << "$." << endl;
        }
        else if (gross == 0) {
            cout << movie[index].title << " neither made nor lose money, it broke even somehow. " << endl;
        }
        else {
            cout << movie[index].title << "'s profit: " << gross << "$." << endl;
        }

        cout << endl;       
    }   

    return 0;
}