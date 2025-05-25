#include "../../include/phonebook.hpp"
#include "../../include/person.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <memory>
#include <iomanip>
#include <algorithm>

namespace PhonebookNamespace {

using namespace PersonNamespace;

    // loads contact list from .csv file
    void Phonebook::loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            // file does not exist yet, blank phonebook
            std::cout << "No contacts found in memory\n";
            return;
        }

        // phonebook file exists and is opened, we can read from it now and populate our phonebook map
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, number;

            if (std::getline(ss, name, ',') && std::getline(ss, number, ',')) {
                auto person = std::make_unique<Person>(name, number);
                addContact(std::move(person));
            }
        }

        std::cout << "Contacts loaded from memory\n";
    }

    // saves the changes made to the contact list to the same file it was loaded from, or creates the file if non-existent
    void Phonebook::saveToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error saving phonebook data!\n";
            return;
        }

        for (const auto& [number, contact] : contacts) {
            file << contact->getName() << "," << contact->getPhoneNumber() << "\n";
        }

        std::cout << "Contacts saved successfully!\n";
    }

    void Phonebook::printContacts() const {
        std::cout << std::setw(15) << std::left << "Name" << " "
                  << std::setw(10) << "Number\n";
        std::cout << std::string(25, '-') << "\n";
        for (const auto& [_, contact] : contacts) {
            contact->display();
        }
    }

    bool Phonebook::addContact(std::unique_ptr<ContactNamespace::Contact> person) {
        std::string number = person->getPhoneNumber();
        // if number is not valid, don't add it to the contact list
        if (!isValid(number)) return false;
        // if the number already exists in the phonebook, return false.
        // no duplicate phone numbers
        if (contacts.find(number) != contacts.end()) return false;
        contacts[number] = std::move(person);
        return true;
    }

    bool Phonebook::deleteContact(const std::string& phoneNumber) {
        return contacts.erase(phoneNumber) > 0;
    }

    bool Phonebook::updateContact(const std::string& originalNumber, std::unique_ptr<ContactNamespace::Contact> newPerson) {
      // number to modify does not exist, therefore we cant update the contact
        if (contacts.find(originalNumber) == contacts.end()) return false;
        // delete the original entry and add the new updated information
        contacts.erase(originalNumber);
        contacts[newPerson->getPhoneNumber()] = std::move(newPerson);
        return true;
    }

    ContactNamespace::Contact* Phonebook::searchByNumber(const std::string& phoneNumber) const {
        auto it = contacts.find(phoneNumber);
        return it != contacts.end() ? it->second.get() : nullptr;
    }

    std::vector<ContactNamespace::Contact*> Phonebook::searchByName(const std::string& name) const {
      // create a vector to store all valid contacts that have the search substring
        std::vector<ContactNamespace::Contact*> matches;
        for (const auto& [_, contact] : contacts) {
            if (contact->getName().find(name) != std::string::npos) {
                matches.push_back(contact.get());
            }
        }
        return matches;
    }

    // helper method to ensure phone number contains only digits
    bool Phonebook::isDigits(const std::string& str) {
        return std::all_of(str.begin(), str.end(), ::isdigit);
    }

    // checks for valid phone number
    bool Phonebook::isValid(const std::string& phoneNumber) {
        return phoneNumber.length() == 10 && isDigits(phoneNumber);
    }

}
