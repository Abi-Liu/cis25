#ifndef CONTACT_H
#define CONTACT_H

#include <string>

namespace ContactNamespace {

    class Contact {
    public:
        virtual void display() const = 0;
        virtual std::string getName() const = 0;
        virtual std::string getPhoneNumber() const = 0;
        virtual void setName(const std::string& name) = 0;
        virtual void setPhoneNumber(const std::string& phoneNumber) = 0;
        virtual ~Contact() = default;
    };

}

#endif