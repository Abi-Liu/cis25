#include "../utils/person.h"
#include <gtest/gtest.h>
using namespace PersonNamespace;

TEST(PersonTest, TestConstructor) {
  Person person("John", "1234567890");
  EXPECT_EQ(person.name, "John");
  EXPECT_EQ(person.phoneNumber, "1234567890");
}

TEST(PersonTest, TestUpdateName) {
  Person person("John", "1234567890");
  EXPECT_EQ(person.name, "John");
  person.updateName("Bob");
  EXPECT_EQ(person.name, "Bob");
}

TEST(PersonTest, TestUpdateNumber) {
  Person person("John", "1234567890");
  EXPECT_EQ(person.phoneNumber, "1234567890");
  person.updatePhoneNumber("1234567891");
  EXPECT_EQ(person.phoneNumber, "1234567891");
}
