//
// Created by Abi Liu on 2/8/25.
//
#include <iostream>
#include "utils/person.h"
#include "utils/phonebook.h"
#include <vector>
using namespace PhonebookNamespace;
using namespace PersonNamespace;
using namespace std;

int main() {
  Person p("Abi", "1234567890");
  p.updateName("Abi Liu");

  // p.updatePhoneNumber("234567890");
  // p.display();

  Phonebook pb;
  pb.addContact("1234567890", p);

  Person p2("Bob Liu", "3216547890");
  pb.addContact("3216547890", p2);

  Person* p3 = pb.searchByNumber("123456789");
  if (p3) {
    p3->display();
  }

  vector<Person> persons = pb.searchByName("Bob");
  for (int i = 0; i < persons.size(); i++) {
    persons[i].display();
  }

  string s = "Bob Liu";
}