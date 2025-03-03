//
// Created by Abi Liu on 2/8/25.
//
#include <iostream>
#include "utils/person.h"
#include "utils/phonebook.h"
#include <vector>
#include <memory>
using namespace PhonebookNamespace;
using namespace PersonNamespace;
using namespace std;

int main() {
    Person p1("John", "2222222222");
    p1.updateName("John Doe");
    p1.updatePhoneNumber("1111111111");
    //
    Phonebook pb;
    //
    pb.addContact(p1);
    //
    Person p2("Sally Doe", "2222222222");
    pb.addContact(p2);

    Person update ("J Doe", "3333333333");
    pb.updateContact(p1, update);
    // pb.printContacts();

    Person p3("Abi Liu", "4444444444");
    pb.addContact(p3);

    //
    // Person* ptr = pb.searchByNumber("4444444444");
    // if (ptr != nullptr) {
    //     ptr -> display();
    // } else {
    //     cout << "No such contact found" << endl;
    // }
    //
    vector<Person> people = pb.searchByName("doe");
    for (int i = 0; i < people.size(); i++) {
        people[i].display();
    }
}
