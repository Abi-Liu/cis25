#include <gtest/gtest.h>
#include "../include/repl.hpp"
#include "../include/command.hpp"
using namespace ReplNamespace;

TEST(ReplTest, ParseCommand_Valid) {
    Repl repl;

    EXPECT_EQ(repl.parseCommand("1"), CommandNamespace::Add);
    EXPECT_EQ(repl.parseCommand("2"), CommandNamespace::Delete);
    EXPECT_EQ(repl.parseCommand("3"), CommandNamespace::SearchName);
    EXPECT_EQ(repl.parseCommand("4"), CommandNamespace::SearchNumber);
    EXPECT_EQ(repl.parseCommand("5"), CommandNamespace::Print);
    EXPECT_EQ(repl.parseCommand("6"), CommandNamespace::Exit);
}

TEST(ReplTest, ParseCommand_Invalid) {
    Repl repl;
    EXPECT_EQ(repl.parseCommand("0"), CommandNamespace::Unknown);
    EXPECT_EQ(repl.parseCommand("999"), CommandNamespace::Unknown);
    EXPECT_EQ(repl.parseCommand("abc"), CommandNamespace::Unknown);
}
