#include <vector>
#include <string>
#include <gtest/gtest.h>

#include "solverlib.hpp"

using namespace std;
using namespace adoc_solver1;

TEST(Solver1, ZeroReturn)
{
    vector<string> vec_string{""};

    EXPECT_EQ(sum_text_lines(vec_string), 0);
}

TEST(Solver1, OneReturn)
{
    vector<string> vec_string{"a1b"};

    EXPECT_EQ(sum_text_lines(vec_string), 11);
}

TEST(FirstDigit, ZeroReturnEmpty)
{
    EXPECT_EQ(first_digit(""), 0);
}

TEST(FirstDigit, ZeroReturn)
{
    EXPECT_EQ(first_digit("abc"), 0);
}

TEST(FirstDigit, OneReturn)
{
    EXPECT_EQ(first_digit("a1bc"), 1);
}

TEST(FirstDigit, OneReturnTwoN)
{
    EXPECT_EQ(first_digit("1a2"), 1);
}

TEST(FirstDigit, TwoReturnTwoN)
{
    EXPECT_EQ(first_digit("abc21"), 2);
}

TEST(LastDigit, ZeroReturnEmpty)
{
    EXPECT_EQ(last_digit(""), 0);
}

TEST(LastDigit, ZeroReturn)
{
    EXPECT_EQ(last_digit("abc"), 0);
}

TEST(LastDigit, OneReturn)
{
    EXPECT_EQ(last_digit("a1bc"), 1);
}

TEST(LastDigit, TwoReturnTwoN)
{
    EXPECT_EQ(last_digit("1b2"), 2);
}