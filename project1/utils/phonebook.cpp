//
// Created by Abi Liu on 2/11/25.
//

#include <iostream>
#include <map>
#include "phonebook.h"
#include "person.h"
using namespace PersonNamespace;
using namespace std;

namespace PhonebookNamespace {

    // later we can modify this function to load a list of contacts from a text file
    Phonebook Phonebook::loadPhonebook() {
        Phonebook newPhonebook;
        return newPhonebook;
    }


    void Phonebook::printContacts(){}

    // for later projects I will add input validation for phoneNumbers
    bool Phonebook::addContact(const string& phoneNumber, Person& person){
        // first we search to see if the phone number already exists
        if(phonebook.find(phoneNumber) == phonebook.end()){
            // phonenumber does not exist, add and return true
            phonebook[phoneNumber] = person;
            return true;
        }

        // this phone number already exists, do not modify the map and return false;
        return false;
    }

    bool Phonebook::deleteContact() {
        return false;
    }
    bool Phonebook::updateContact() {
        return false;
    }

    Person* Phonebook::searchByNumber(const string& phoneNumber){
        if(phonebook.find(phoneNumber) == phonebook.end()){
            // phone number not found, return nullptr
            return nullptr;
        }

        // phone number exists, return a pointer to the Person struct
        return &(phonebook.find(phoneNumber)->second);

    }
}
