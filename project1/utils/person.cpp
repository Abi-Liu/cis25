//
// Created by Abi Liu on 2/11/25.
//

#include "person.h"
#include <iostream>
using namespace std;

namespace PersonNamespace {
    Person::Person(const string& name, const string& phoneNumber) : name(name), phoneNumber(phoneNumber) {};

    void Person::display() {
      cout << "Name: " << name << " Number: " << phoneNumber << endl;
    }

    void Person::updateName(const string& newName) {
        name = newName;
    }

    void Person::updatePhoneNumber(const string& newPhoneNumber) {
        phoneNumber = newPhoneNumber;
    }
}