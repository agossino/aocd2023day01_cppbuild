#include <iostream>
#include <fstream>
#include <vector>
#include "solverlib.hpp"

int main(int argc, char *argv[])
{
    using namespace std;
    ifstream in_fstream;
    vector<string> text_lines;

    if (argc == 1)
    {
        cout << "Advent of Code solver" << endl;
        cout << "Usage: " << argv[0] << "  INPUT_FILE" << endl;
    }
    else
    {
        in_fstream.open(argv[1]);
        if (in_fstream.fail())
        {
            cout << "Opening " << argv[1] << " failed." << endl;
            exit(1);
        }
        while (in_fstream)
        {
            string line;
            getline(in_fstream, line);
            text_lines.push_back(line);
        }

        cout << adoc_solver1::sum_text_lines(text_lines) << endl;
    }

    return 0;
}
