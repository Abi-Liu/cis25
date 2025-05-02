//
// Created by Abi Liu on 5/2/25.
//
#include <gtest/gtest.h>
#include "../utils/repl.h"
using namespace ReplNamespace;

TEST(ReplTest, ParseCommandAdd) {
    Command cmd = parseCommand(1);
    EXPECT_EQ(cmd, Add);
}

TEST(ReplTest, ParseCommandDelete) {
    Command cmd = parseCommand(2);
    EXPECT_EQ(cmd, Delete);
}

TEST(ReplTest, ParseCommandSearchName) {
    Command cmd = parseCommand(3);
    EXPECT_EQ(cmd, SearchName);
}

TEST(ReplTest, ParseCommandSearchNumber) {
    Command cmd = parseCommand(4);
    EXPECT_EQ(cmd, SearchNumber);
}

TEST(ReplTest, ParseCommandPrint) {
    Command cmd = parseCommand(5);
    EXPECT_EQ(cmd, Print);
}

TEST(ReplTest, ParseCommandExit) {
    Command cmd = parseCommand(6);
    EXPECT_EQ(cmd, Exit);
}

TEST(ReplTest, ParseCommandUnknown) {
    Command cmd = parseCommand(8);
    EXPECT_EQ(cmd, Unknown);
}
