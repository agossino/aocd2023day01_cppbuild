#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <string>
#include "solverlib.hpp"

using namespace std;

namespace adoc_solver
{
    const char ZERO_CHAR = '0';
    const string DIGITS[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const int NOTHING_FOUND = -1;

    DigitWithPosition::DigitWithPosition(int the_digit, size_t the_pos)
        : digit(the_digit), position(the_pos)
    {
    }

    LineOfText::LineOfText(string text)
        : line_of_text(text), spelled_alphabetically(false)
    {
    }

    int LineOfText::two_digit_number()
    {
        search_numeric_digits();
        search_alphabetic_digits();

        if (spelled_alphabetically)
            numeric_digits.insert(numeric_digits.end(), alphabetic_digits.begin(), alphabetic_digits.end());

        sort(numeric_digits.begin(), numeric_digits.end(), is_first_position_bigger);

        if (!numeric_digits.empty())
            return numeric_digits.front().digit * 10 + numeric_digits.back().digit;
        else
            return 0;
    }

    void LineOfText::set_alphabetic()
    {
        spelled_alphabetically = true;
        return;
    }

    void LineOfText::unset_alphabetic()
    {
        spelled_alphabetically = false;
        return;
    }

    void LineOfText::search_numeric_digits()
    {
        for (int i = 0; i < line_of_text.length(); i++)
        {
            if (isdigit(line_of_text[i]))
            {
                numeric_digits.push_back(DigitWithPosition(line_of_text[i] - ZERO_CHAR, i));
            }
        }
    }

    void LineOfText::search_alphabetic_digits()
    {
        std::size_t position = 0;

        for (int i = 0; i < size(DIGITS); i++)
        {
            while ((position = line_of_text.find(DIGITS[i], position)) != std::string::npos)
            {
                alphabetic_digits.push_back(DigitWithPosition(i, position));
                position += 1;
            }
            position = 0;
        }
        return;
    }

    bool is_first_position_bigger(const DigitWithPosition digit_w_p1, const DigitWithPosition digit_w_p2)
    {
        return digit_w_p1.position < digit_w_p2.position;
    }

    int sum_text_lines(const vector<string> vector_str, bool is_spelled_alphabetically)
    {
        vector<int> vector_int;
        int sum;

        for (string str : vector_str)
        {
            LineOfText line = LineOfText(str);
            if (is_spelled_alphabetically)
                line.set_alphabetic();
            vector_int.push_back(line.two_digit_number());
        }

        sum = accumulate(vector_int.begin(), vector_int.end(), 0);

        return sum;
    }
}

namespace adoc_solver2
{
    int sum_text_lines(const vector<string> vector_str)
    {
        vector<int> vector_int;
        int sum;

        for (string str : vector_str)
        {
            adoc_solver::LineOfText line = adoc_solver::LineOfText(str);
            line.set_alphabetic();
            vector_int.push_back(line.two_digit_number());
        }

        sum = accumulate(vector_int.begin(), vector_int.end(), 0);

        return sum;
    }
}