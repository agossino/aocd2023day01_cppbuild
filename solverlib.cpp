#include <cctype>
#include <numeric>
#include <vector>
#include <string>
#include "solverlib.hpp"

using namespace std;

namespace adoc_solver1
{

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

    int first_digit(const string str)
    {
        int str_lenght = str.length();
        for (int i = 0; i < str.length(); i++)
        {
            if (isdigit(str[i]))
                return str[i] - '0';
        }
        return 0;
    }

    int last_digit(const string str)
    {
        int str_lenght = str.length();
        for (int i = str_lenght - 1; i >= 0; i--)
        {
            if (isdigit(str[i]))
                return str[i] - '0';
        }
        return 0;
    }
}