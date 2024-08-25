/* Design an Inventory class that can hold information and calculate data for items in a
retail store’s inventory. The class should have the following private member variables:

Variable Name       Description
itemNumber          An int that holds the item’s item number.
quantity            An int for holding the quantity of the items on hand.
cost                A double for holding the wholesale per-unit cost of the item
totalCost           A double for holding the total inventory cost of the item (calculated as quantity times cost).

The class should have the following public member functions:
Member Function         Description
Default Constructor     Sets all the member variables to 0.
Constructor #2          Accepts an item’s number, cost, and quantity as arguments.
                        The function should copy these values to the appropriate
                        member variables and then call the setTotalCost function.
setItemNumber           Accepts an integer argument that is copied to the itemNumber member variable.
setQuantity             Accepts an integer argument that is copied to the quantity member variable.
setCost                 Accepts a double argument that is copied to the cost member variable.
setTotalCost            Calculates the total inventory cost for the item (quantity times cost) and stores the result in totalCost.
getItemNumber           Returns the value in itemNumber.
getQuantity             Returns the value in quantity.
getCost                 Returns the value in cost.
getTotalCost            Returns the value in totalCost.

Demonstrate the class in a driver program.

Input Validation: Do not accept negative values for item number, quantity, or cost. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class Inventory {
   private:
    int itemNumber, quantity;
    double cost, totalCost;

   public:
    Inventory();
    Inventory(int, int, double);
    void setItemNumber(int i) {
        itemNumber = i;
    }

    void setQuantity(int q) {
        quantity = q;
        setTotalCost();
    }

    void setCost(double c) {
        cost = c;
        setTotalCost();
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }

    int getItemNumber() {
        return itemNumber;
    }

    int getQuantity() {
        return quantity;
    }

    double getCost() {
        return cost;
    }

    double getTotalCost() {
        return totalCost;
    }

};

Inventory::Inventory() {
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int i, int q, double c) {
    itemNumber = i;
    quantity = q;
    cost = c;
    setTotalCost();
}

int checker(int&, int);
double checker(double&, double);

int main() {

    Inventory retailStore[5];
    int nomb, bil;
    double harga;

    for(int i = 0; i < 5; i++) {
        cout << "Enter the details for item #" << (i + 1) << endl;

        cout << "Item number? ";
        nomb = checker(nomb, 0);
        retailStore[i].setItemNumber(nomb);

        cout << "Item quantity? ";
        bil = checker(bil, 0);
        retailStore[i].setQuantity(bil); 

        cout << "Item price? ";
        harga = checker(harga, 0);       
        retailStore[i].setCost(harga);

        retailStore[i] = Inventory(nomb, bil, harga);
        cout << endl;
    }


    cout << "Time to list out all of them: \n";
    // Displaying the table header
    cout << left << setw(15) << "Item Number" << setw(15) << "Quantity" << setw(15) << "Cost" << setw(15) << "Total Cost" << endl;

    // Displaying each item in the retailStore array
    for(int i = 0; i < 5; i++) {
        cout << left << setw(15) << retailStore[i].getItemNumber() << setw(15) << retailStore[i].getQuantity() 
        << "$" << setw(15) << retailStore[i].getCost() << "$" << setw(15) << retailStore[i].getTotalCost() << endl;
    }


    return 0;
}

int checker(int &x, int i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}

double checker(double &x, double i) {

    cin >> x;
    while (x < i) {
        cout << "Enter a bigger number, bigger than " << i << ". ";
        cin.clear();
        cin >> x;
    }

    return x;

}







