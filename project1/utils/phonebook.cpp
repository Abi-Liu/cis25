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

    // for later iterations I will add input validation for phoneNumbers
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

    // returns a POINTER to a person object.
    // you have to be careful to check for nullptr before dereferencing
    Person* Phonebook::searchByNumber(const string& phoneNumber){
        if(phonebook.find(phoneNumber) == phonebook.end()){
            // phone number not found, return nullptr
            return nullptr;
        }

        // phone number exists, return a pointer to the Person struct
        return &(phonebook.find(phoneNumber)->second);

    }

    // this function takes a substring to search for and returns a vector of Persons
    // with the given substring in their name
    vector<Person> Phonebook::searchByName(const std::string& name) {
        // loop through the person values stored in the map and
        vector<Person> persons;
        for (auto it = phonebook.begin(); it != phonebook.end(); ++it){
            Person p = it->second;
            size_t found = p.name.find(name);
            if (found != string::npos) {
                // if we hit this case, that means we found a matching substring in name
                // add to vector and continue to next iteration
                persons.push_back(p);
            }
        }

        return persons;
    }
}
