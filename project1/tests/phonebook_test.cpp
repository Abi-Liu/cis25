#include <gtest/gtest.h>
#include "../utils/phonebook.h"
#include "../utils/person.h"
using namespace PersonNamespace;
using namespace PhonebookNamespace;

TEST(PhonebookTest, isDigitSuccess) {
    bool res = isDigits("1234567890");
    EXPECT_TRUE(res);
}

TEST(PhonebookTest, isDigitFail) {
    bool res = isDigits("1234567a90");
    EXPECT_FALSE(res);
}

TEST(PhonebookTest, addContactSuccess) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    bool res = phonebook.addContact(p1);
    EXPECT_TRUE(res);

    // test for updating number for existing contact
    p1.updatePhoneNumber("1231231234");
    res = phonebook.addContact(p1);
    EXPECT_TRUE(res);
}

TEST(PhonebookTest, addContactFail) {
    Phonebook phonebook;
    // not 10 digits, should fail
    Person p1("John", "123456789");
    bool res = phonebook.addContact(p1);
    EXPECT_FALSE(res);

    // not all digits, fail
    p1.updatePhoneNumber("123123123s");
    res = phonebook.addContact(p1);
    EXPECT_FALSE(res);
}

TEST(PhonebookTest, deleteContactSuccess) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    phonebook.addContact(p1);
    bool res = phonebook.deleteContact(p1);
    EXPECT_TRUE(res);
}

TEST(PhonebookTest, deleteContactFail) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    bool res = phonebook.deleteContact(p1);
    EXPECT_FALSE(res);
}

TEST(PhonebookTest, updateContactSuccess) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    Person update("John Doe", "1234567890");
    phonebook.addContact(p1);
    bool res = phonebook.updateContact(p1, update);
    EXPECT_TRUE(res);
}

TEST(PhonebookTest, updateContactFail) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    Person update("John Doe", "1234567890");
    bool res = phonebook.updateContact(p1, update);
    EXPECT_FALSE(res);
}
