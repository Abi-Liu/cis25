//
// Created by Abi Liu on 2/11/25.
//

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <map>
#include <iostream>
#include "person.h"

std::map<std::string, PersonNamespace::Person> createPhonebook();
void printContacts();
bool addContact(std::map<std::string, PersonNamespace::Person>& phonebook, const std::string& phoneNumber, PersonNamespace::Person& person);
bool deleteContact();
bool updateContact();
PersonNamespace::Person search(const std::string& phoneNumber);


#endif //PHONEBOOK_H
