//
// Created by Abi Liu on 2/11/25.
//

#include "person.h"
#include <iostream>
using namespace std;

namespace PersonNamespace {
    Person::Person(string name, string phoneNumber) : name(name), phoneNumber(phoneNumber) {};

    void Person::display() {
      cout << "Name: " << name << "Number: " << phoneNumber << endl;
    }
}