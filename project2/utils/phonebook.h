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
        void savePhonebook();
        void printContacts();
        bool addContact(PersonNamespace::Person& person);
        bool deleteContact(const std::string& phoneNumber);
        bool updateContact(const PersonNamespace::Person& original, const PersonNamespace::Person& newPerson);
        PersonNamespace::Person* searchByNumber(const std::string& phoneNumber);
        std::vector<PersonNamespace::Person> searchByName(const std::string& name);
    };

    bool isDigits(const std::string& str);
    bool isValid(const std::string& phoneNumber);
}


#endif //PHONEBOOK_H
