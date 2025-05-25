#include "../../include/repl.hpp"
#include "../../include/person.hpp"
#include "../../include/phonebook.hpp"
#include <iostream>

namespace ReplNamespace {

using namespace PhonebookNamespace;
using namespace PersonNamespace;
using namespace CommandNamespace;


// helper method to get user input
std::string Repl::getLineInput(const std::string& prompt) const {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}

// extract the contact details from the user entered information
std::unique_ptr<ContactNamespace::Contact> Repl::getContactDetails() const {
    std::string name;
    std::string number;

    while (true) {
        name = getLineInput("Enter name: ");
        if (!name.empty()) break;
        std::cout << "Name cannot be empty!\n";
    }

    while (true) {
        number = getLineInput("Enter 10-digit phone number: ");
        if (Phonebook::isValid(number)) break;
        std::cout << "Invalid phone number!\n";
    }

    return std::make_unique<Person>(name, number);
}

// parse and return the command using the enum
Command Repl::parseCommand(const std::string& input) const {
    if (input == "1") return CommandNamespace::Command::Add;
    if (input == "2") return CommandNamespace::Command::Delete;
    if (input == "3") return CommandNamespace::Command::SearchName;
    if (input == "4") return CommandNamespace::Command::SearchNumber;
    if (input == "5") return CommandNamespace::Command::Print;
    if (input == "6") return CommandNamespace::Command::Exit;
    return CommandNamespace::Command::Unknown;
}

// main driver method to run the repl
void Repl::start() {
    std::cout << "Loading phonebook...\n";
    // load file and populate contacts
    phonebook.loadFromFile("../../phonebook.csv");

    while (true) {
        std::cout << "\n[1] Add Contact\n[2] Delete Contact\n[3] Search by Name\n"
                     "[4] Search by Number\n[5] Print All\n[6] Exit\n";
        std::string input = getLineInput("Select an option: ");
        Command cmd = parseCommand(input);

        // switch statement to iterate over the user entered command
        switch (cmd) {
            case Command::Add: {
                auto contact = getContactDetails();
                std::cout << (phonebook.addContact(std::move(contact)) ?
                    "Contact added.\n" : "Failed to add contact.\n");
                break;
            }
            case Command::Delete: {
                std::string number = getLineInput("Enter number to delete: ");
                std::cout << (phonebook.deleteContact(number) ?
                    "Deleted.\n" : "Not found.\n");
                break;
            }
            case Command::SearchName: {
                std::string name = getLineInput("Enter name to search: ");
                for (auto c : phonebook.searchByName(name)) c->display();
                break;
            }
            case Command::SearchNumber: {
                std::string number = getLineInput("Enter number to search: ");
                auto contact = phonebook.searchByNumber(number);
                if (contact) {
                    contact->display();
                } else {
                    std::cout << "Not found.\n";
                }                break;
            }
            case Command::Print:
                phonebook.printContacts();
                break;
            case Command::Exit:
                phonebook.saveToFile("../../phonebook.csv");
                std::cout << "Goodbye!\n";
                return;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}

}
