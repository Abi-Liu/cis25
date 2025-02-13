//
// Created by Abi Liu on 2/11/25.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <map>
#include <iostream>
#include <vector>
#include "person.h"

namespace PhonebookNamespace {
    struct Phonebook {
        std::map<std::string, PersonNamespace::Person> phonebook;

        Phonebook() = default;

        Phonebook loadPhonebook();
        void printContacts();
        bool addContact(const std::string& phoneNumber, PersonNamespace::Person& person);
        bool deleteContact();
        bool updateContact();
        PersonNamespace::Person* searchByNumber(const std::string& phoneNumber);
        std::vector<PersonNamespace::Person> searchByName(const std::string& name);
    };
}


#endif //PHONEBOOK_H
