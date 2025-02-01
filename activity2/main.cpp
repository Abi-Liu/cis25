//
// Created by Abi Liu on 1/31/25.
//
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


string getRandomCard() {
    int randNum = rand() % 13 + 1;
    const char* card;

    if (randNum == 1) {
        card = "Ace";
    } else if (randNum == 13) {
        card = "King";
    } else if (randNum == 12) {
        card = "Queen";
    } else if (randNum == 11) {
        card = "Jack";
    } else {
        card = to_string(randNum).c_str();
    }

    return card;
}
string getRandomSuit() {
    int randSuit = rand() % 4;
    const char* suit;
    switch (randSuit) {
        case 0:
            suit = "Hearts";
        break;
        case 1:
            suit = "Diamonds";
        break;
        case 2:
            suit = "Spades";
        break;
        case 3:
            suit = "Clubs";
        break;
    }

    return suit;
}

void printRandomCard() {
}

int main() {
    // seed rand
    srand(time(NULL));
    string card = getRandomCard();
    string suit = getRandomSuit();
    string res = card + " of " + suit;
    string label = "Casino Card:";
    // minus 2 for the extra 2 * characters
    int length = 40 - res.length() - label.length() - 2;
    cout << setw(40) << setfill('*') << "" << endl;
    cout << "*" << setw(39) << setfill(' ') << "*" << endl;
    cout << "*" << setw(length) << left << label << setfill('-');
    cout << setw(40 - length - 2) << right << res << "*" << endl;
    cout << "*" << setw(39) << setfill(' ') << "*" << endl;
    cout << setw(40) << setfill('*') << "" << endl;
    return 0;
}