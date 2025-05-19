#include <gtest/gtest.h>
#include "../include/person.h"
#include "../include/phonebook.h"

using PersonNamespace::Person, PhonebookNamespace::Phonebook;

TEST(IsDigits, EmptyNumber) {
	EXPECT_FALSE(PhonebookNamespace::isDigits("")); //test fails; empty strings are considered valid
}

class FixturePB : public ::testing::Test {
protected:
	Phonebook pb;
	Person a{ "Jimmy", "8005551234" }, b{ "Johnny", "8005551235" };

	FixturePB() {
		pb.addContact(a);
	}
};

TEST_F(FixturePB, DupeContact) {
	EXPECT_FALSE(pb.addContact(a)); //test passes; prevents adding duplicate number
}

TEST_F(FixturePB, UpdateContactInvalidNumber) {
	EXPECT_FALSE(pb.updateContact(a, { "Jimmy", "123" })); //test fails; invalid number allowed as input
}

TEST_F(FixturePB, DupeUpdateNumber) {
	pb.addContact(b);
	EXPECT_FALSE(pb.updateContact(a, { "Jimmy", b.phoneNumber })); //test fails; duplicate number allowed as update
}

TEST_F(FixturePB, SearchCaseInsensitive) {
	auto results = pb.searchByName("jimmy"); //search 'jimmy' instead of 'Jimmy'
	EXPECT_EQ(results.size(), 1); //test fails; no results found
}