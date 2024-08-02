/* Write a program that uses a structure named MovieData to store the following infor-
mation about a movie:

    Title
    Director
    Year Released
    Running Time (in minutes)

The program should create two MovieData variables, store values in their members,
and pass each one, in turn, to a function that displays the information about the movie
in a clearly formatted manner. */

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
        cin.ignore();
        cout << endl;
    }

    cout << "You have finished entering all the necessary data. " << endl;
    cout << "It is time to display them. " << endl;

    for (index = 0; index < maxMovies; index++) {
        cout << "Movie #" << (index + 1) << "'s title: " << movie[index].title << endl;
        cout << movie[index].title << "'s director: " << movie[index].director << endl;
        cout << movie[index].title << "'s release year: " << movie[index].year << endl;
        cout << movie[index].title << "'s running time (minutes): " << movie[index].time << endl; 
        cout << endl;       
    }   

    return 0;
}