/* Write a class named Employee that has the following member variables:
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee
works.
• position. A string that holds the employee’s job title.
The class should have the following constructors:
• A constructor that accepts the following values as arguments and assigns them to
the appropriate member variables: employee’s name, employee’s ID number, depart-
ment, and position.
• A constructor that accepts the following values as arguments and assigns them to the
appropriate member variables: employee’s name and ID number. The department
and position fields should be assigned an empty string ("").
• A default constructor that assigns empty strings ("") to the name, department, and
position member variables, and 0 to the idNumber member variable.
Write appropriate mutator functions that store values in these member variables and
accessor functions that return the values in these member variables. Once you have
written the class, write a separate program that creates three Employee objects to hold
the following data.

Name            ID Number       Department      Position
Susan Meyers    47899           Accounting      Vice President
Mark Jones      39119           IT              Programmer
Joy Rogers      81774           Manufacturing   Engineer

The program should store this data in the three objects and then display the data for
each employee on the screen. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Employee {
   private:
    string name;
    int id;
    string department;
    string position;

   public:
    Employee(string, int, string, string);

    string getName() const {
        return name;
    }

    int getID() const {
        return id;
    }

    string getDepartment() const {
        return department;
    }

    string getPosition() const {
        return position;
    }

};

Employee::Employee(string n, int i, string d, string p) {
    name = n;
    id = i;
    department = d;
    position = p;
}

int main() {
    const int maxWorkers = 3;
    
    Employee pekerja[maxWorkers] = { // refer 13-14
        Employee("Susan Meyers", 47899, "Accounting", "Vice President"),
        Employee("Mark Jones", 39119, "IT", "Programmer"),
        Employee("Joy Rogers", 81774, "Manufacturing", "Engineer")
    };

    cout << left << setw(15) << "Name" << setw(15) << "ID Number" << setw(15) << "Department" << setw(15) << "Position" << endl;

    for (int i = 0; i < maxWorkers; i++) {
        cout << left << setw(15) << pekerja[i].getName();
        cout << left << setw(15) << pekerja[i].getID();
        cout << left << setw(15) << pekerja[i].getDepartment();
        cout << left << setw(15) << pekerja[i].getPosition();
        cout << endl;
    }

    return 0;
}