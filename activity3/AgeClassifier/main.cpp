//
// Created by Abi Liu on 1/29/25.
//
#include <iostream>
using namespace std;

int main() {
    int age;
    cin >> age;
    if (age < 12) {
      cout << "Child" << endl;
    } else if (age < 20) {
      cout << "Teen" << endl;
    } else if (age < 64) {
      cout << "Adult" << endl;
    } else {
      cout << "Senior" << endl;
    }
}