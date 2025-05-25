#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <map>
#include <string>
#include <vector>
#include "contact.hpp"

namespace PhonebookNamespace {

    class Phonebook {
    private:
        std::map<std::string, std::unique_ptr<ContactNamespace::Contact> > contacts;

    public:
        Phonebook() = default;

        void loadFromFile(const std::string& filename);
        void saveToFile(const std::string& filename) const;
        void printContacts() const;
        bool addContact(std::unique_ptr<ContactNamespace::Contact> person);
        bool deleteContact(const std::string& phoneNumber);
        bool updateContact(const std::string& originalNumber, std::unique_ptr<ContactNamespace::Contact> newPerson);
        ContactNamespace::Contact* searchByNumber(const std::string& phoneNumber) const;
        std::vector<ContactNamespace::Contact*> searchByName(const std::string& name) const;

        static bool isDigits(const std::string& str);
        static bool isValid(const std::string& phoneNumber);
    };

}

#endif // PHONEBOOK_H
