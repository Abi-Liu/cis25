//
// Created by Abi Liu on 2/8/25.
//
#include <iostream>
#include "utils/person.h"
#include "utils/phonebook.h"
using namespace PhonebookNamespace;
using namespace PersonNamespace;
using namespace std;

int main() {
  Person p("Abi", "123456789");
  p.display();

  p.updateName("Abi Liu");
  p.display();

  // p.updatePhoneNumber("234567890");
  // p.display();

  Phonebook pb;
  pb.addContact("123456789", p);

  Person p2 = *(pb.searchByNumber("123456789"));
  p2.display();
}