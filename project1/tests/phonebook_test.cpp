#include <gtest/gtest.h>
#include "../utils/phonebook.h"
#include "../utils/person.h"
#include <vector>
using namespace std;
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

TEST(PhonebookTest, searchByNumberSuccess) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    phonebook.addContact(p1);
    Person* res = phonebook.searchByNumber("1234567890");
    EXPECT_NE(res, nullptr);
    EXPECT_EQ(res->name, "John");
    EXPECT_EQ(res->phoneNumber, "1234567890");
}

// person pointer should be null
TEST(PhonebookTest, searchByNumberFail) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    phonebook.addContact(p1);
    Person* res = phonebook.searchByNumber("9234128560");
    EXPECT_EQ(res, nullptr);
}

TEST(PhonebookTest, searchByName) {
    Phonebook phonebook;
    Person p1("John", "1234567890");
    Person p2("John Doe", "0987654321");
    Person p3("Alice Doe", "1111111111");
    phonebook.addContact(p1);
    phonebook.addContact(p2);
    phonebook.addContact(p3);
    vector<Person> res = phonebook.searchByName("John");
    EXPECT_EQ(res.size(), 2);

    // case where name not found
    res = phonebook.searchByName("asdf");
    EXPECT_EQ(res.size(), 0);
}
