#ifndef REPL_HPP
#define REPL_HPP

#include "phonebook.hpp"
#include "command.hpp"
#include "person.hpp"
#include <string>

namespace ReplNamespace {

    class Repl {
    private:
        PhonebookNamespace::Phonebook phonebook;
        std::string getLineInput(const std::string& prompt) const;
        std::unique_ptr<ContactNamespace::Contact> getContactDetails() const;

    public:
        void start();
        CommandNamespace::Command parseCommand(const std::string& input) const;
    };

}

#endif