#include <iostream>
using namespace std;

struct Address {
  string street;
  string city;
  int zipcode;
};

struct Customer {
  string name;
  Address address;
};

int main() {
  Address address;
  Customer customer;

  cout << "Please enter your name:" << endl;

  getline(cin, customer.name);

  cout << "Please enter your street:" << endl;
  getline(cin, address.street);
  cout << "Please enter your city:" << endl;
  getline(cin, address.city);

  cout << "Please enter your zipcode:" << endl;
  while(true) {
    cin >> address.zipcode;
    if(cin.fail()) {
      cout << "Please enter a valid zipcode." << endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (address.zipcode < 10000 || address.zipcode > 99999) {
      cout << "Please enter a valid zipcode." << endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      break;
    }
  }

  cout << address.zipcode << endl << address.street << endl << address.city << endl << address.zipcode << endl;
  cout << customer.name << endl;
}

