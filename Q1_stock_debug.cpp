/*
 * Name       : Muhammad Hashim Aftab
 * Reg No     : L1S26BSCS0116
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>
#include <fstream> // FIX 1: Needed for file handling
using namespace std;

int main() {
    ifstream inFile("stock.txt");
    if (!inFile) { // FIX 2: Check if the file failed to open
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    ofstream reorder("reorder.txt", ios::app); // FIX 3: Keep old data

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    double total = 0; // FIX 4: Store decimal values

    char header[100];
    inFile.getline(header, 100); // FIX 5: Skip the header line

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {
            reorder << code << " " << qty << endl; // FIX 6: Write each item on a new line
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
