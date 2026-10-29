/*
 * Name       : Muhammad Hashim Aftab
 * Reg No     : L1S26BSCS0116
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */
#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    char path[100];

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open()) 
    {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    int n;

    if (!(inFile >> n)) 
    {
        cout << "No students found!" << endl;
        inFile.close();
        return 0;
    }

    if (n > 30) 
    {
        cout << "Too many students!" << endl;
        inFile.close();
        return 0;
    }

    inFile.ignore(100, '\n');

    ofstream outFile("scholarship.txt");

    if (!outFile.is_open()) 
    {
        inFile.close();
        return 1;
    }

    int count = 0;
    int eligible = 0;
    double total = 0;
    double highestCGPA = -1;

    char name[30];
    char topName[30] = "";
    double cgpa;

    for (int i = 0; i < n; i++) 
    {

        if (!inFile.getline(name, 30, ',')) 
        {
            break;
        }

        if (!(inFile >> cgpa))
        {
            break;
        }

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        count++;
        total = total + cgpa;

        if (cgpa >= 3.50) 
        {
            eligible++;
            outFile << name << "," << cgpa << endl;
        }

        if (cgpa > highestCGPA) 
        {
            highestCGPA = cgpa;

            int j = 0;

            while (name[j] != '\0') 
            {
                topName[j] = name[j];
                j++;
            }

            topName[j] = '\0';
        }
    }

    if (count < n) 
    {
        cout << "Warning: only " << count << " of " << n << " records found." << endl;
    }

    if (count == 0) 
    {
        cout << "No students found!" << endl;
    }
    else 
    {
        cout << "Students: " << count << endl;
        cout << "Average CGPA: " << total / count << endl;
        cout << "Eligible for scholarship: " << eligible << endl;
        cout << "Top student: " << topName   << " (" << highestCGPA << ")" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}
