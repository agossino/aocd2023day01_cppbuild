#include <cctype>
#include <numeric>
#include <vector>
#include <string>
#include "solverlib.hpp"

using namespace std;

namespace adoc_solver1
{
    const char ZERO_CHAR = '0';
    const string DIGITS[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int sum_text_lines(const vector<string> vector_str)
    {
        vector<int> vector_int;
        int sum;

        for (string str : vector_str)
        {
            int two_digits_int;
            two_digits_int = first_digit(str) * 10;
            two_digits_int += last_digit(str);
            vector_int.push_back(two_digits_int);
        }

        sum = accumulate(vector_int.begin(), vector_int.end(), 0);

        return sum;
    }

    int first_digit(const string str, const bool spelled_with_letters)
    {
        int str_length = str.length();
        int numeric_found_at_index = -1, numeric_found;
        int alphabetic_found_at_index = -1, alphabetic_found;

        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]))
            {
                numeric_found = str[i] - ZERO_CHAR;
                numeric_found_at_index = i;
                break;
            }
        }
        if (spelled_with_letters)
        {
            for (int i = 0; i < end(DIGITS) - begin(DIGITS); i++)
            {
                std::size_t found_at_index = str.find(DIGITS[i]);
                if (found_at_index != std::string::npos)
                {
                    if (alphabetic_found_at_index > -1)
                    {
                        if (alphabetic_found_at_index < found_at_index)
                        {
                            alphabetic_found = i;
                            alphabetic_found_at_index = found_at_index;
                        }
                    }
                    else
                    {
                        alphabetic_found = i;
                        alphabetic_found_at_index = found_at_index;
                    }
                }
            }

            if (numeric_found_at_index > alphabetic_found_at_index)
                return numeric_found;
            else if (alphabetic_found_at_index > numeric_found_at_index)
                return alphabetic_found;
            else
                return 0;
        }
        else
        {
            if (numeric_found_at_index > -1)
                return numeric_found;
            else
                return 0;
        }
    }

    int last_digit(const string str, const bool spelled_with_letters)
    {
        int str_length = str.length();
        for (int i = str_length - 1; i >= 0; i--)
        {
            if (isdigit(str[i]))
                return str[i] - ZERO_CHAR;
        }
        return 0;
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
            int two_digits_int;
            two_digits_int = adoc_solver1::first_digit(str, true) * 10;
            two_digits_int += adoc_solver1::last_digit(str, true);
            vector_int.push_back(two_digits_int);
        }

        sum = accumulate(vector_int.begin(), vector_int.end(), 0);

        return sum;
    }
}