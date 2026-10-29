/*
 * Name       : Muhammad Hashim Aftab   
 * Reg No     : L1S26BSCS0116   
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() 
{

    ifstream inFile("parking.txt");

    if (!inFile) 
    {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int day, month, year;
    char slash1, slash2;

    inFile >> day >> slash1 >> month >> slash2 >> year;

    char header[100];
    inFile.getline(header, 100);
    inFile.getline(header, 100);

    ofstream outFile("receipts.txt");

    if (!outFile) 
    {
        cout << "Could not create receipts.txt!" << endl;
        inFile.close();
        return 1;
    }

    cout << "Parking report for " << day << "/" << month << "/" << year << endl;

    outFile << "Receipts for " << day << "/" << month << "/" << year << endl;

    char plate[15];
    char type;
    int inHour, inMinute, outHour, outMinute;
    char colon1, colon2;

    int totalVehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;

    int longestMinutes = -1;
    char longestPlate[15] = "";

    while (totalVehicles < 30 && inFile >> plate >> type >> inHour >> colon1 >> inMinute >> outHour >> colon2 >> outMinute) 
    {        
        int minutes = (outHour * 60 + outMinute) - (inHour * 60 + inMinute);

        int hours = minutes / 60;
        int remainingMinutes = minutes % 60;

        int chargedHours = (minutes + 59) / 60;

        if (chargedHours == 0) 
        {
            chargedHours = 1;
        }

        int fee;

        if (type == 'C') 
        {
            fee = chargedHours * 100;
            cars++;
        }
        else 
        {
            fee = chargedHours * 40;
            bikes++;
        }

        totalVehicles++;
        totalCollected = totalCollected + fee;

        if (minutes > longestMinutes) 
        {
            longestMinutes = minutes;

            int i = 0;
            while (plate[i] != '\0') 
            {
                longestPlate[i] = plate[i];
                i++;
            }
            longestPlate[i] = '\0';
        }

        cout << plate << " ";

        if (type == 'C')
        {
            cout << "Car ";
        }
        else 
        {
            cout << "Bike ";
        }

        cout << hours << " h " << remainingMinutes << " min Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;
    }

    cout << "Vehicles: " << totalVehicles << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalCollected << endl;

    if (totalVehicles > 0) 
    {
        cout << "Longest stay: " << longestPlate << " (" << longestMinutes / 60 << " h " << longestMinutes % 60 << " min)" << endl;
    }
    else 
    {
        cout << "No vehicles Found!" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
