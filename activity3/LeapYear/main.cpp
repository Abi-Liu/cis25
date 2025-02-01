//
// Created by Abi Liu on 1/29/25.
//
#include <iostream>
using namespace std;

int main() {
  int year;
  cin >> year;
  bool isLeapYear = false;

  if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
     isLeapYear = true;
  }

  if(isLeapYear) {
    cout << "Year is a leap year" << endl;
  } else {
    cout << "Year is not a leap year" << endl;
  }
}