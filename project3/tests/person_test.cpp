#include <gtest/gtest.h>
#include "../include/person.hpp"
using namespace PersonNamespace;

TEST(PersonTest, ConstructorAndGetters) {
  Person person("John", "1234567890");
  EXPECT_EQ(person.getName(), "John");
  EXPECT_EQ(person.getPhoneNumber(), "1234567890");
}

TEST(PersonTest, SetName) {
  Person person("John", "1234567890");
  person.setName("Bob");
  EXPECT_EQ(person.getName(), "Bob");
}

TEST(PersonTest, SetPhoneNumber) {
  Person person("John", "1234567890");
  person.setPhoneNumber("1234567891");
  EXPECT_EQ(person.getPhoneNumber(), "1234567891");
}
