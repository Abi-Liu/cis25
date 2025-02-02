//
// Created by Abi Liu on 2/1/25.
//
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int ids[] = {1, 2, 3};
    string names[] = {"Alice", "Bob", "Charlie"};
    double balances[] = {530.25, 1230.51, 2250.25};
    int padding = 3;
    // could figure this out dynamically but ill hardcode for now.
    int longestName = 7;
    int idWidth = 6;
    int balanceWidth = 7;

    // calculates where to print the title based on the lengths of each field: id, name and balance
    cout << setw((longestName + idWidth + balanceWidth)) << setfill(' ') << "Daily Report" << endl;

    // outputs the column titles for each column with a standard padding of 3 spaces
    cout << setw(idWidth) << left << "ID" << setw(padding) << setfill(' ') << " " << setw(longestName) << left
        << "Name" << setw(padding) << setfill(' ') << " " << setw(balanceWidth) << left << "Balance" << endl;

    // prints the separator between title and values using the same calculated lengths and padding size
    cout << setw(idWidth) << setfill('-') << "-" << setw(padding) << setfill(' ') << " " << setw(longestName) << setfill('-') << "-"
        << setw(padding) << setfill(' ') << " " << setw(balanceWidth) << setfill('-') << "-" << endl;


    // loops through the arrays and prints the id, name and balance for each person on their own line with the same padding
    for (int i = 0; i < 3; i++) {
        cout << setw(idWidth) << right << setfill('0') << ids[i] << setw(padding) << setfill(' ') << " ";
        cout << setw(longestName) << left << names[i] << setw(padding) << setfill(' ') << " ";
        cout << "$" << setw(balanceWidth) << setprecision(2) << fixed << left << balances[i] << setw(padding) << setfill(' ') << " ";
        cout << endl;
    }
}