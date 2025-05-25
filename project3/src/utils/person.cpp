#include "../../include/person.hpp"
#include <iomanip>

using namespace std;
using namespace PersonNamespace;

Person::Person(const std::string& name, const std::string& phoneNumber) : name(name), phoneNumber(phoneNumber) {}

void Person::display() const {
    std::cout << std::setw(15) << std::left << name << " " << std::setw(10) << phoneNumber << std::endl;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getPhoneNumber() const {
    return phoneNumber;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

void Person::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}