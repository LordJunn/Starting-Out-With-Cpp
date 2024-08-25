/* Write a class named RetailItem that holds data about an item in a retail store. The
class should have the following member variables:
• description. A string that holds a brief description of the item.
• unitsOnHand. An int that holds the number of units currently in inventory.
• price. A double that holds the item’s retail price.
Write a constructor that accepts arguments for each member variable, appropriate
mutator functions that store values in these member variables, and accessor functions
that return the values in these member variables. Once you have written the class, write
a separate program that creates three RetailItem objects and stores the following data
in them.
            Description     Units   On Hand Price
Item #1     Jacket          12      59.95
Item #2     Designer Jeans  40      34.95
Item #3     Shirt           20      24.95 */

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

class RetailItem {
   private:
    string description;
    int unitsOnHand;
    double price;

   public:
    RetailItem(string, int, double);

    string getDesc() const {
        return description;
    }
    void setDesc(const string& newDesc) {
        description = newDesc;
    }

    int getUnitsOnHand() const {
        return unitsOnHand;
    }
    void setUnitsOnHand(const int& newUnits) {
        unitsOnHand = newUnits;
    }

    double getPrice() const {
        return price;
    }
    void setPrice(const double& newPrice) {
        price = newPrice;
    }

};

RetailItem::RetailItem(string d, int u, double p) {
    description = d;
    unitsOnHand = u;
    price = p;
}

int main() {

    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);

    // lazy ahh mf
    cout << left << setw(15) << " " << setw(15) << "Description" << setw(20) << "Units On Hand" << setw(15) << "Price" << endl;
    cout << left << setw(15) << "Item #1" << setw(20) << item1.getDesc() << setw(15) << item1.getUnitsOnHand() << "$" 
    << setw(15) << fixed << setprecision(2) << item1.getPrice() << endl;
    cout << left << setw(15) << "Item #2" << setw(20) << item2.getDesc() << setw(15) << item2.getUnitsOnHand() << "$" 
    << setw(15) << fixed << setprecision(2) << item2.getPrice() << endl;
    cout << left << setw(15) << "Item #3" << setw(20) << item3.getDesc() << setw(15) << item3.getUnitsOnHand() << "$" 
    << setw(15) << fixed << setprecision(2) << item3.getPrice() << endl;
    
    return 0;
}