//
// Created by Abi Liu on 2/11/25.
//

#include "person.h"
#include <iostream>
#include <iomanip>
using namespace std;

namespace PersonNamespace {
    Person::Person(const string& name, const string& phoneNumber) : name(name), phoneNumber(phoneNumber) {};

    void Person::display() {
      cout << setw(15) << left << setfill(' ') << name << " " << setw(10) << left << phoneNumber << endl;
    }

    void Person::updateName(const string& newName) {
        name = newName;
    }

    void Person::updatePhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
}