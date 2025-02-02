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
    double balances[] = {1000, 1230.51, 2250.25};
    int padding = 3;
    // could figure this out dynamically but ill hardcode for now.
    int longestName = 7;
    int idWidth = 6;
    int balanceWidth = 6;

    cout << setw((longestName + idWidth + balanceWidth)) << setfill(' ') << "Daily Report" << endl;

    cout << setw(idWidth) << left << "ID" << setw(padding) << setfill(' ') << " " << setw(longestName) << left
        << "Name" << setw(padding) << setfill(' ') << " " << setw(balanceWidth) << left << "Balance" << endl;

    cout << setw(idWidth) << setfill('-') << "-" << setw(padding) << setfill(' ') << " " << setw(longestName) << setfill('-') << "-"
        << setw(padding) << setfill(' ') << " " << setw(balanceWidth) << setfill('-') << "-" << endl;

    for (int i = 0; i < 3; i++) {
        cout << setw(idWidth) << right << setfill('0') << ids[i] << setw(padding) << setfill(' ') << " ";
        cout << setw(longestName) << left << names[i] << setw(padding) << setfill(' ') << " ";
        cout << setw(balanceWidth) << setprecision(2) << fixed << left << balances[i] << setw(padding) << setfill(' ') << " ";
        cout << endl;
    }
}