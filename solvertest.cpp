#include <vector>
#include <string>
#include <gtest/gtest.h>

#include "solverlib.hpp"

using namespace std;

TEST(LineOfTextNumeric, NoNumber)
{
    adoc_solver::LineOfText lot = adoc_solver::LineOfText("");
    EXPECT_EQ(lot.two_digit_number(), 0) << "text: ";

    string text = "onetwothreeeeeonine";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 0) << "text: " << text;
}

TEST(LineOfTextNumeric, OneDigit)
{
    string text = "1";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 11) << "text: " << text;

    text = "ontw7threeightninefour";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 77) << "text: " << text;
}

TEST(LineOfTextNumeric, TwoDigits)
{
    string text = "89";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 89) << "text: " << text;

    text = "sixsixxx5threenine4";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 54) << "text: " << text;

    text = "2oneoonesix1";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 21) << "text: " << text;

    text = "quert0oo1";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 1) << "text: " << text;
}

TEST(LineOfTextNumeric, MoreDigits)
{
    string text = "122223";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 13) << "text: " << text;

    text = "0onetwo55555555six4";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 4) << "text: " << text;

    text = "2ontw010sseven41";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 21) << "text: " << text;

    text = "quert987654ontwthre23nin";
    lot = adoc_solver::LineOfText(text);
    EXPECT_EQ(lot.two_digit_number(), 93) << "text: " << text;
}

TEST(LineOfTextAlphabetic, NoNumber)
{
    adoc_solver::LineOfText lot = adoc_solver::LineOfText("");
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 0) << "text: ";

    string text = "onEtwOthreEFIVESIXninE"; // capital letters are ignored (see DIGITS array)
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 0) << "text: " << text;
}

TEST(LineOfTextAlphabetic, TwoDigits)
{
    string text = "eight12sevennine";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 89) << "text: " << text;

    text = "ontwfive0thre6ninfour";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 54) << "text: " << text;

    text = "twoontwthreninone";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 21) << "text: " << text;

    text = "quertzeroonetwthreonenin";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 1) << "text: " << text;
}

TEST(LineOfTextAlphabetic, MoreDigits)
{
    string text = "threextwoxone";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 31) << "text: " << text;

    text = "zeroontwfivethreninfourfourfoursixfour";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 4) << "text: " << text;

    text = "twoontwzeroonezerothrenonein";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 21) << "text: " << text;

    text = "quertnineontwthretwothreeeenin";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 93) << "text: " << text;
}

TEST(LineOfTextAlphabetic, Mixed)
{
    string text = "8threextwoxone";
    adoc_solver::LineOfText lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 81) << "text: " << text;

    text = "zero9twfivethreninfourfourfoursixfour";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 4) << "text: " << text;

    text = "bybythreeonetwzeroonezerothree4in";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 34) << "text: " << text;

    text = "quertninenineontw8three8threetwothreeeenin";
    lot = adoc_solver::LineOfText(text);
    lot.set_alphabetic();
    EXPECT_EQ(lot.two_digit_number(), 93) << "text: " << text;
}

TEST(Solver, ZeroReturn)
{
    vector<string> vec_string{""};

    EXPECT_EQ(adoc_solver::sum_text_lines(vec_string), 0);
}

TEST(Solver, OneReturn)
{
    vector<string> vec_string{"a1b"};

    EXPECT_EQ(adoc_solver::sum_text_lines(vec_string), 11);
}

TEST(SumTextLines, EmptyStr)
{
    vector<string> lines = {""};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 0);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 0);
}

TEST(SumTextLines, OneLineStr)
{
    vector<string> lines = {"querty"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 0);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 0);
    lines = {"que2rty"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 22);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 22);
    lines = {"querty19"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 19);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 19);
    lines = {"quesixrty19"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 69);
    lines = {"ninequerty19one9on"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 99);
}

TEST(SumTextLines, Sum)
{
    vector<string> lines = {"querty", "hi1"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 11);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 11);
    lines = {"que2rty", "4hello0"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 62);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 62);
    lines = {"1querty19", "0Ooooh!1"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines), 20);
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 20);
    lines = {"one5quertythree9", "alzeroOoooh!1thre"};
    EXPECT_EQ(adoc_solver::sum_text_lines(lines, true), 20);
}
