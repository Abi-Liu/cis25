#ifndef PERSON_H
#define PERSON_H

#include "contact.hpp"
#include <string>
#include <iostream>

namespace PersonNamespace {

    class Person : public ContactNamespace::Contact {
    private:
        std::string name;
        std::string phoneNumber;

    public:
        Person() = default;
        Person(const std::string& name, const std::string& phoneNumber);

        void display() const override;
        std::string getName() const override;
        std::string getPhoneNumber() const override;
        void setName(const std::string& name) override;
        void setPhoneNumber(const std::string& phoneNumber) override;
    };

}

#endif // PERSON_H
