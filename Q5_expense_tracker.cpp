
/*
 * Name       : Muhammad Hashim Aftab
 * Reg No     : L1S26BSCS0116   
 * Assignment : 02 - File Handling
 * Question   : Q5 - Expense Tracker
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
    int choice;

    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) 
        {
            char category[20];
            int amount;

            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0) 
            {
                cout << "Invalid amount!" << endl;
            }
            else 
            {
                ofstream outFile("expenses.txt", ios::app);

                if (!outFile) 
                {
                    return 1;
                }

                outFile << category << " " << amount << endl;
                outFile.close();

                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2) 
        {
            ifstream inFile("expenses.txt");

            if (!inFile) 
            {
                cout << "No expenses yet." << endl;
            }
            else 
            {
                char category[20];
                char largestCategory[20];
                int amount;
                int largestAmount = 0;
                int total = 0;
                int count = 0;

                while (count < 100 && inFile >> category >> amount) 
                {
                    count++;
                    cout << count << ". " << category << " " << amount << endl;

                    total += amount;

                    if (count == 1 || amount > largestAmount) 
                    {
                        largestAmount = amount;

                        int i = 0;
                        while (category[i] != '\0')
                        {
                            largestCategory[i] = category[i];
                            i++;
                        }
                        largestCategory[i] = '\0';
                    }
                }

                inFile.close();

                if (count == 0) 
                {
                    cout << "No expenses yet." << endl;
                }
                else 
                {
                    cout << "Total spent: " << total << endl;
                    cout << "Largest expense: "
                        << largestCategory << " ("
                        << largestAmount << ")" << endl;
                }
            }
        }
        else if (choice == 3) 
        {
            char searchCategory[20];
            char category[20];
            int amount;
            int count = 0;
            int total = 0;

            cout << "Enter category: ";
            cin >> searchCategory;

            ifstream inFile("expenses.txt");

            if (inFile) 
            {
                while (inFile >> category >> amount) 
                {
                    int i = 0;

                    while (category[i] != '\0' && searchCategory[i] != '\0' && category[i] == searchCategory[i]) 
                    {
                        i++;
                    }

                    if (category[i] == '\0' && searchCategory[i] == '\0') 
                    {
                        count++;
                        total += amount;
                    }
                }

                inFile.close();
            }

            if (count == 0) 
            {
                cout << "No expenses found for " << searchCategory << endl;
            }
            else 
            {
                cout << "Expenses in " << searchCategory << ": " << count << endl;
                cout << "Total for " << searchCategory << ": " << total << endl;
            }
        }
        else if (choice == 4)
        {
            ofstream outFile("expenses.txt");

            if (!outFile)
            {
                return 1;
            }

            outFile.close();
            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5)
        {
            cout << "Goodbye!" << endl;
        }
        else 
        {
            cout << "Invalid choice!" << endl;
        }

    } 
    while (choice != 5);

    return 0;
}
