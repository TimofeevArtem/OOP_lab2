#include <gtest/gtest.h>
#include "string.h"
#include <cstddef>
#include <sstream>
#include <string>
#include <utility>

std::string textOf(const String& value) {
    std::ostringstream out;
    value.print(out);
    return out.str();
}

TEST(StringTest, DefaultIsEmpty) {
    const String s;
    EXPECT_EQ(textOf(s), "");
}

TEST(StringTest, CreatesFromText) {
    const String s("Hello");
    EXPECT_EQ(textOf(s), "Hello");
}

TEST(StringTest, CopiesText) {
    String original("Hello");
    String copy(original);

    original.append("!");

    EXPECT_EQ(textOf(copy), "Hello");
    EXPECT_EQ(textOf(original), "Hello!");
}

TEST(StringTest, MovesText) {
    String source("Hello");
    String moved(std::move(source));

    EXPECT_EQ(textOf(moved), "Hello");
    EXPECT_EQ(textOf(source), "");
}

TEST(StringTest, AssignsText) {
    String source("Hello");
    String destination("Old");

    destination = source;

    EXPECT_EQ(textOf(destination), "Hello");
    EXPECT_EQ(textOf(source), "Hello");
}

TEST(StringTest, SelfAssignmentWorks) {
    String s("Hello");

    s = s;

    EXPECT_EQ(textOf(s), "Hello");
}

TEST(StringTest, AppendsText) {
    String s("Hello");
    s.append(", World!");

    EXPECT_EQ(textOf(s), "Hello, World!");
}

TEST(StringTest, AppendsToEmptyString) {
    String s;
    s.append("Hello");

    EXPECT_EQ(textOf(s), "Hello");
}

TEST(StringTest, AppendsEmptyText) {
    String s("Hello");
    s.append("");

    EXPECT_EQ(textOf(s), "Hello");
}

TEST(StringTest, FindsText) {
    const String s("Hello World");

    EXPECT_EQ(s.find("World"), 6u);
    EXPECT_EQ(s.find("Hello"), 0u);
}

TEST(StringTest, MissingTextReturnsNpos) {
    const String s("Hello");

    EXPECT_EQ(s.find("xyz"), static_cast<std::size_t>(-1));
    EXPECT_EQ(s.find("HelloWorld"), static_cast<std::size_t>(-1));
}

TEST(StringTest, WrapsText) {
    const String s("Hello world again");
    const String result = s.wrap(12);

    EXPECT_EQ(textOf(result), "Hello world\nagain");
}