#include <iostream>
#include <fstream>
#include <vector>
#include <tclap/CmdLine.h>
#include "solverlib.hpp"

int main(int argc, char *argv[])
{
    using namespace std;
    ifstream in_fstream;
    string file_name;
    vector<string> text_lines;

    try
    {
        TCLAP::CmdLine command_line("Advent of code 2023 day 1 solver", ' ', "0.0");
        vector<int> part_args;
        part_args.push_back(1);
        part_args.push_back(2);
        TCLAP::ValuesConstraint<int> allowed_vals(part_args);
        TCLAP::ValueArg<int> part("p", "part", "Solve the mentioned quiz part", false, 1, &allowed_vals);
        command_line.add(part);
        TCLAP::UnlabeledValueArg<std::string> file_name("input_file", "The file data to be processed.", true, "", "file name");
        command_line.add(file_name);

        command_line.parse(argc, argv);

        {
            in_fstream.open(file_name.getValue());
            if (in_fstream.fail())
            {
                cout << "Opening " << file_name.getValue() << " failed." << endl;
                exit(1);
            }
            while (in_fstream)
            {
                string line;
                getline(in_fstream, line);
                text_lines.push_back(line);
            }

            cout << adoc_solver::sum_text_lines(text_lines, (part.getValue() == 1) ? false : true) << endl;
        }
    }
    catch (TCLAP::ArgException &e) // catch exceptions
    {
        std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl;
    }

    return 0;
}
