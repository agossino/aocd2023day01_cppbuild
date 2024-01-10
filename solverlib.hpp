#ifndef SOLVERLIB_H
#define SOLVERLIB_H

#include <vector>
#include <string>

namespace adoc_solver
{
    struct DigitWithPosition
    {
        DigitWithPosition(int digit, size_t position);
        int digit;
        size_t position;
    };

    class LineOfText
    {
    public:
        LineOfText(const std::string text);
        int two_digit_number();
        void set_alphabetic();
        void unset_alphabetic();

    private:
        void search_numeric_digits();
        void search_alphabetic_digits();
        std::string line_of_text;
        std::vector<DigitWithPosition> alphabetic_digits;
        std::vector<DigitWithPosition> numeric_digits;
        bool spelled_alphabetically;
    };

    int sum_text_lines(const std::vector<std::string> vector_str, bool is_spelled_alphabetically = false);

    int first_digit(const std::string str, const bool spelled_with_letters = false);

    size_t find_last_match(const std::string str, const std::string to_find);

    int last_digit(const std::string str, const bool spelled_with_letters = false);
    
    bool is_first_position_bigger(const DigitWithPosition digit1, const DigitWithPosition digit2);
}

#endif /* SOLVERLIB_H */