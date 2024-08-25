/* Design a CashRegister class that can be used with the InventoryItem class discussed
in this chapter. The CashRegister class should perform the following:
1. Ask the user for the item and quantity being purchased.
2. Get the item’s cost from the InventoryItem object.
3. Add a 30% profit to the cost to get the item’s unit price.
4. Multiply the unit price times the quantity being purchased to get the purchase sub-
total.
5. Compute a 6% sales tax on the subtotal to get the purchase total.
6. Display the purchase subtotal, tax, and total on the screen.
7. Subtract the quantity being purchased from the onHand variable of the
InventoryItem class object.
Implement both classes in a complete program. Feel free to modify the InventoryItem
class in any way necessary.
Input Validation: Do not accept a negative value for the quantity of items being
purchased. */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
#include "InventoryItem.h"
using namespace std;

class CashRegister {
   private:
    string item;
    int onHand;
    double price, profit, subtotal, tax, total;

   public:
    void deductCount(int i) {
        onHand -= i;
    }
    
    void setPrice(double p) {
        price = p;
    }

    void setProfit() {
        profit = price * 1.30;
    }

    void setSubtotal(int i) {
        subtotal = profit * i;
    }

    void setTax(double t) {
        tax = subtotal * (t/100);
    }

    void setTotal() {
        total = (subtotal + tax);
    }

    double displayProfit() {
        return profit;
    }

    double displayTax() {
        return tax;
    }

    double displaySubtotal() {
        return subtotal;
    }

    double displayTotal() {
        return total;
    }


};

int checker(int&, int, int);
double checker(double&, double);

int main() {

    const int NUM_ITEMS = 5;
    InventoryItem inventory[NUM_ITEMS] = {
        InventoryItem("Hammer", 6.95, 12), 
        InventoryItem("Wrench", 8.75, 20),
        InventoryItem("Pliers", 3.75, 10), 
        InventoryItem("Ratchet", 7.95, 14),
        InventoryItem("Screwdriver", 2.50, 22)};

    cout << setw(14) << "Inventory Item" << setw(8) << "Cost" << setw(8)
         << setw(16) << "Units on Hand\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << fixed << setprecision(2);
        cout << setw(14) << inventory[i].getDescription();
        cout << setw(8) << inventory[i].getCost();
        cout << setw(7) << inventory[i].getUnits() << endl;
    }

    CashRegister ryo;
    int num, amount;
    double t;

    cout << "What's the item you would like to buy? ";
    num = checker(num, 1, NUM_ITEMS);
    num--;
    ryo.setPrice(inventory[num].getCost());
    ryo.setProfit();

    cout << "... and the amount? ";
    amount = checker(amount, 0, inventory[num].getUnits());
    ryo.setSubtotal(amount);

    cout << "Tax amount (in percentage)? ";
    t = checker(t, 0);
    ryo.setTax(t);

    ryo.setTotal();

    cout << "Item purchased: " << inventory[num].getDescription() << endl;
    cout << "Amount purchased: " << amount << endl;
    cout << fixed << setprecision(2);
    cout << "Purchase subtotal: $" << ryo.displaySubtotal() << endl;
    cout << "Tax: $" << ryo.displayTax() << endl;
    cout << "Total price: $" << ryo.displayTotal() << endl;

    return 0;
}

int checker(int &x, int i, int j) {

    cin >> x;
    while (x < i || x > j) {
        cout << "Enter a bigger number, bigger than " << i << " but smaller than " << j << ". ";
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



