#include <vector>
#include <string>
#include <gtest/gtest.h>

#include "solverlib.hpp"

using namespace std;

TEST(Solver1, ZeroReturn)
{
    vector<string> vec_string{""};

    EXPECT_EQ(adoc_solver1::sum_text_lines(vec_string), 0);
}

TEST(Solver1, OneReturn)
{
    vector<string> vec_string{"a1b"};

    EXPECT_EQ(adoc_solver1::sum_text_lines(vec_string), 11);
}

TEST(FirstDigit, ZeroReturnEmpty)
{
    ASSERT_EQ(adoc_solver1::first_digit(""), 0);
    ASSERT_EQ(adoc_solver1::first_digit("", true), 0);
}

TEST(FirstDigit, ZeroReturn)
{
    ASSERT_EQ(adoc_solver1::first_digit("abc"), 0);
    ASSERT_EQ(adoc_solver1::first_digit("abc", true), 0);
}

TEST(FirstDigit, OneReturn)
{
    ASSERT_EQ(adoc_solver1::first_digit("a1beightc"), 1);
    ASSERT_EQ(adoc_solver1::first_digit("a1bc", true), 1);
    ASSERT_EQ(adoc_solver1::first_digit("aonebc", true), 1);
}

TEST(FirstDigit, OneReturnTwoN)
{
    ASSERT_EQ(adoc_solver1::first_digit("1aone2"), 1);
    ASSERT_EQ(adoc_solver1::first_digit("a2nine", true), 2);
    ASSERT_EQ(adoc_solver1::first_digit("threea2", true), 3);
    ASSERT_EQ(adoc_solver1::first_digit("onfour5two", true), 4);
}

TEST(FirstDigit, TwoReturnTwoN)
{
    ASSERT_EQ(adoc_solver1::first_digit("abc21"), 2);
    ASSERT_EQ(adoc_solver1::first_digit("8abc21"), 8);
    ASSERT_EQ(adoc_solver1::first_digit("sixabc21", true), 6);
    ASSERT_EQ(adoc_solver1::first_digit("abceight21", true), 8);
}

TEST(FindLastString, TwoStrings)
{
    ASSERT_EQ(adoc_solver1::find_last_match("twosevenone3six4tdltwo", "two"), 19);
    ASSERT_EQ(adoc_solver1::find_last_match("3fourninefourjjtqrng", "four"), 9);
}

TEST(LastDigit, ZeroReturnEmpty)
{
    EXPECT_EQ(adoc_solver1::last_digit(""), 0);
    EXPECT_EQ(adoc_solver1::last_digit("", true), 0);
}

TEST(LastDigit, ZeroReturn)
{
    EXPECT_EQ(adoc_solver1::last_digit("abc"), 0);
    EXPECT_EQ(adoc_solver1::last_digit("abc", true), 0);
}

TEST(LastDigit, OneReturn)
{
    EXPECT_EQ(adoc_solver1::last_digit("a1bc"), 1);
    EXPECT_EQ(adoc_solver1::last_digit("6bc"), 6);
    EXPECT_EQ(adoc_solver1::last_digit("bc5"), 5);
    EXPECT_EQ(adoc_solver1::last_digit("a1bc", true), 1);
    EXPECT_EQ(adoc_solver1::last_digit("3bc", true), 3);
    EXPECT_EQ(adoc_solver1::last_digit("afourbc", true), 4);
    EXPECT_EQ(adoc_solver1::last_digit("sixbc", true), 6);
    EXPECT_EQ(adoc_solver1::last_digit("abcnine", true), 9);
}

TEST(LastDigit, TwoReturnTwoN)
{
    EXPECT_EQ(adoc_solver1::last_digit("1b2"), 2);
    EXPECT_EQ(adoc_solver1::last_digit("12fks"), 2);
    EXPECT_EQ(adoc_solver1::last_digit("9bone2", true), 2);
    EXPECT_EQ(adoc_solver1::last_digit("1b2threex", true), 3);
    EXPECT_EQ(adoc_solver1::last_digit("9three8four7five", true), 5);
    EXPECT_EQ(adoc_solver1::last_digit("twosevenone3six4tdltwo", true), 2);
}

TEST(SumTextLines, EmptyStr)
{
    vector<string> lines = {""};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 0);
}

TEST(SumTextLines, OneLineStr)
{
    vector<string> lines = {"querty"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 0);
    lines = {"que2rty"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 22);
    lines = {"querty19"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 19);
}

TEST(SumTextLines, Sum)
{
    vector<string> lines = {"querty", "hi1"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 11);
    lines = {"que2rty", "4hello0"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 62);
    lines = {"1querty19", "0Ooooh!1"};
    EXPECT_EQ(adoc_solver1::sum_text_lines(lines), 20);
}

TEST(SumTextLines2, EmptyStr)
{
    vector<string> lines = {""};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 0);
}

TEST(SumTextLines2, OneLineStr)
{
    vector<string> lines = {"querty"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 0);
    lines = {"que2rty"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 22);
    lines = {"querty19"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 19);
    lines = {"quesixrty19"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 69);
    lines = {"ninequerty19one9on"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 99);
}

TEST(SumTextLines2, Sum)
{
    vector<string> lines = {"querty", "hi1"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 11);
    lines = {"que2rty", "4hello0"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 62);
    lines = {"1querty19", "0Ooooh!1"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 20);
    lines = {"one5quertythree9", "alzeroOoooh!1thre"};
    EXPECT_EQ(adoc_solver2::sum_text_lines(lines), 20);
}
