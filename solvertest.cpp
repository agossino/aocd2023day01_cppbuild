#include <vector>
#include <string>
#include <gtest/gtest.h>

#include "solverlib.h"

using namespace std;

TEST(Solver1, ZeroReturn)
{
    vector<string> vec_string{""};

    EXPECT_EQ(func(vec_string), 0);
}
