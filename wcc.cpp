#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <cerrno>
#include <tuple>

using namespace std;

/// manage counters using a tuple
typedef tuple<unsigned int, unsigned int, unsigned int> Counters;

/// compute counters from open stream
Counters counters(std::istream &input)
{
    // line read from file
    string line;

    // number of lines counter
    unsigned int nb_lines = 0;

    // maximum and minimum values are set to their optimum
    // to calculate minimal & maximal length
    unsigned int min_value = numeric_limits<unsigned int>::max();
    unsigned int max_value = 0;

    // read each line of the input file
    while (getline(input, line))
    {
        // get length
        auto line_length = line.length();

        // check length and adjust min & max values accordingly
        if (line_length < min_value)
            min_value = line_length;
        if (line_length > max_value)
            max_value = line_length;

        // one more line is read!
        nb_lines++;
    }

    // return data as a tuple
    return make_tuple(min_value, max_value, nb_lines);
}

// Very simple utility used to calculate the minimum and maximum
// length of the lines of an ASCII file. It simply outputs the two
// values as: min max nb_lines
//
// usage: wcc <file>
//
// compile with GCC: g++ wcc.cpp -o wcc -std=c++11 -O3 -s
int main(int argc, char *argv[])
{
    // we'll store data in this tuple
    Counters ctr = make_tuple(0, 0, 0);

    // check arguments
    switch (argc)
    {
    case 1:
        ctr = counters(cin);
        break;

    case 2:
    {
        ifstream input_file(argv[1]);

        // could be stdin
        if (string(argv[1]) == "-")
        {
            ctr = counters(cin);
        }
        else
        {
            // check if file is opened
            if (input_file.fail())
            {
                cout << "Unable to open file <" << argv[1] << ">. Error <" << std::strerror(errno) << ">" << endl;
                exit(2);
            }
            ctr = counters(input_file);
            input_file.close();
        }
    }
    break;

    default:
        cout << "wcc [FILE]" << endl;
        exit(1);
    }

    // just print out computed values
    cout << get<0>(ctr) << " " << get<1>(ctr) << " " << get<2>(ctr) << " " << endl;
}
