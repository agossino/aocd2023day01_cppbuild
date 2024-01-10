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

    try {
	TCLAP::CmdLine cmd("Advent of code 2023 day 1 solver", ' ', "0.0");
    TCLAP::SwitchArg alphabetic_mode("a","alphabetic","Read number spelled alphabetically, in addition to digit", cmd, false);
    TCLAP::UnlabeledValueArg<std::string> file_name("input_file", "The file data to be processed.", true, "", "file name");
    cmd.add(file_name);
    
	cmd.parse( argc, argv );

    
    {
        in_fstream.open(file_name.getValue());
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

        cout << adoc_solver::sum_text_lines(text_lines, alphabetic_mode.getValue()) << endl;
    }

    

    } catch (TCLAP::ArgException &e)  // catch exceptions
	{ std::cerr << "error: " << e.error() << " for arg " << e.argId() << std::endl; }

    return 0;
}
