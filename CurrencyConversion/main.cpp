//
// Created by Abi Liu on 2/1/25.
//
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// holds conversion rates for currencies
// index 0 = USD
// index 1 = EURO
// index 2 = GPB
// index 3 = JPY
const double CONVERSION_RATES[4][4] = {
  {1, .97, .81, 155.18},
  {1.04, 1, .84, 160.81},
  {1.24, 1.20, 1, 190.3},
  {.0064, .0062, .0052, 1},
};

int getIndex(string input) {
  int index;
  if(input == "USD") index = 0;
  else if(input == "EURO") index = 1;
  else if(input == "GBP") index = 2;
  else if(input == "JPY") index = 3;
  // handles case where to/from is not usd, euro, gpb or jpy
  else return -1;

  return index;
}

double convert(double amount, string from, string to) {
  int fromIndex = getIndex(from), toIndex = getIndex(to);

  if (fromIndex == -1 || toIndex == -1) {
    return -1;
  }

  return amount*CONVERSION_RATES[fromIndex][toIndex];
}

void exchangePromotion(string from, string to, double rate) {
  int fromIndex = getIndex(from), toIndex = getIndex(to);

  if (fromIndex == -1 || toIndex == -1) {
    return;
  }


  double (*modifiableRates)[4] = const_cast<double(*)[4]>(CONVERSION_RATES);
  modifiableRates[fromIndex][toIndex] = rate;
  cout << "Promotional rate applied! " << from << " to " << to << " is now: " << rate << endl;

}

int main () {
  double amount;
  string from, to;

  cout << "Please enter the amount to be converted : ";
  cin >> amount;

  cout << "Which currency would you like to convert from?" << endl << "USD, EURO, GBP, JPY" << endl;
  cin >> from;

  cout << "Which currency would you like to convert to?" << endl << "USD, EURO, GBP, JPY" << endl;
  cin >> to;

  // convert to all uppercase
  transform(from.begin(), from.end(), from.begin(), ::toupper);
  transform(to.begin(), to.end(), to.begin(), ::toupper);
  double res = convert(amount, from, to);

  if (res == -1) {
    cout << "Please select a currency from the given list" << endl;
    return 0;
  }

  cout << fixed << setprecision(2) << res << " " + to << endl;
}