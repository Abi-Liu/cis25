//
// Created by Abi Liu on 2/11/25.
//

#ifndef PERSON_H
#define PERSON_H

#include <string>

namespace PersonNamespace {
    struct Person {
        std::string name;
        std::string phoneNumber; // formatted with no space and other characters: 123456789

        Person(std::string& name, std::string& phoneNumber);
        void display();
        void updateName(std::string& name);
        void Person::updatePhoneNumber(std::string& newPhoneNumber);
    };
}


#endif //PERSON_H
