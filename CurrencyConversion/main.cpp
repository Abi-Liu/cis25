//
// Created by Abi Liu on 2/1/25.
//
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

const int USD = 0;
const int EURO = 1;
const int GPB = 2;
const int JPY = 3;

double convert(double amount, string from, string to) {
  int fromIndex, toIndex;
  if(from == "USD") fromIndex = 0;
  else if(from == "EURO") fromIndex = 1;
  else if(from == "GBP") fromIndex = 2;
  else if(from == "JPY") fromIndex = 3;
  // handles case where to/from is not usd, euro, gpb or jpy
  else return -1;

  if(to=="USD") toIndex = 0;
  else if(to=="EURO") toIndex = 1;
  else if(to=="GBP") toIndex = 2;
  else if(to=="JPY") toIndex = 3;
  else return -1;

  return amount*CONVERSION_RATES[fromIndex][toIndex];
}

void exchangePromotion(string to, string from, double rate) {
  int fromIndex, toIndex;
  if(from == "USD") fromIndex = 0;
  else if(from == "EURO") fromIndex = 1;
  else if(from == "GBP") fromIndex = 2;
  else if(from == "JPY") fromIndex = 3;

  if(to=="USD") toIndex = 0;
  else if(to=="EURO") toIndex = 1;
  else if(to=="GBP") toIndex = 2;
  else if(to=="JPY") toIndex = 3;


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
  cout << res << endl;
}