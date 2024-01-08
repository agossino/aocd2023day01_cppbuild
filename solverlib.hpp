#ifndef SOLVERLIB_H
#define SOLVERLIB_H

#include <vector>
#include <string>

namespace adoc_solver1
{
    int sum_text_lines(const std::vector<std::string> vector_str);

    int first_digit(const std::string str, const bool spelled_with_letters = false);

    size_t find_last_match(const std::string str, const std::string to_find);

    int last_digit(const std::string str, const bool spelled_with_letters = false);
}

namespace adoc_solver2
{
    int sum_text_lines(const std::vector<std::string> vector_str);
}

#endif /* SOLVERLIB_H */