#include <gtest/gtest.h>
#include "../include/phonebook.hpp"
#include "../include/person.hpp"
#include <memory>
using namespace PhonebookNamespace;
using namespace PersonNamespace;

TEST(PhonebookTest, IsDigits_ValidAndInvalid) {
    EXPECT_TRUE(Phonebook::isDigits("1234567890"));
    EXPECT_FALSE(Phonebook::isDigits("12345abc90"));
}

TEST(PhonebookTest, IsValid_ValidAndInvalid) {
    EXPECT_TRUE(Phonebook::isValid("1234567890"));
    EXPECT_FALSE(Phonebook::isValid("1234"));
}

TEST(PhonebookTest, AddContact_ValidAndInvalid) {
    Phonebook book;

    auto valid = std::make_unique<Person>("Alice", "1234567890");
    EXPECT_TRUE(book.addContact(std::move(valid)));

    auto invalid = std::make_unique<Person>("Bob", "12345abc");
    EXPECT_FALSE(book.addContact(std::move(invalid)));
}

TEST(PhonebookTest, DeleteContact) {
    Phonebook book;
    auto person = std::make_unique<Person>("Charlie", "1111111111");
    book.addContact(std::make_unique<Person>("Charlie", "1111111111"));
    EXPECT_TRUE(book.deleteContact("1111111111"));
    EXPECT_FALSE(book.deleteContact("9999999999"));
}

TEST(PhonebookTest, UpdateContact_SuccessAndFail) {
    Phonebook book;
    auto old = std::make_unique<Person>("David", "2222222222");
    book.addContact(std::make_unique<Person>("David", "2222222222"));

    auto updated = std::make_unique<Person>("David Jr.", "3333333333");
    EXPECT_TRUE(book.updateContact("2222222222", std::move(updated)));

    auto failUpdate = std::make_unique<Person>("Ghost", "9999999999");
    EXPECT_FALSE(book.updateContact("nonexistent", std::move(failUpdate)));
}

TEST(PhonebookTest, SearchByNumber) {
    Phonebook book;
    book.addContact(std::make_unique<Person>("Eve", "4444444444"));

    auto found = book.searchByNumber("4444444444");
    ASSERT_NE(found, nullptr);
    EXPECT_EQ(found->getName(), "Eve");

    auto notFound = book.searchByNumber("0000000000");
    EXPECT_EQ(notFound, nullptr);
}

TEST(PhonebookTest, SearchByName) {
    Phonebook book;
    book.addContact(std::make_unique<Person>("John", "1234567890"));
    book.addContact(std::make_unique<Person>("Johnny", "0987654321"));
    book.addContact(std::make_unique<Person>("Alice", "1111111111"));

    auto results = book.searchByName("John");
    EXPECT_EQ(results.size(), 2);

    auto none = book.searchByName("Zebra");
    EXPECT_TRUE(none.empty());
}
