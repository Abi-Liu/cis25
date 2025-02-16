//
// Created by Abi Liu on 2/11/25.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace PersonNamespace {
    struct Person {
        std::string name;
        std::string phoneNumber; // formatted with no space and other characters: 1234567890

        Person(const std::string& name, const std::string& phoneNumber);
        Person() = default;
        void display();
        void updateName(const std::string& name);
        void updatePhoneNumber(const std::string& newPhoneNumber);
    };
}


#endif //PERSON_H
