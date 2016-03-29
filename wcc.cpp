#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// very simple utility used to calculate the minimum and maximum
// length of the lines of an ASCII file. It simply outputs the two
// values as: min max
//
// usage: wcc <file>
//
// compile with GCC: g++ wcc.cpp -o wcc -std=c++11 -O3 -s
int main(int argc, char *argv[]) 
{
    // line read from file
    string line;

    // maximum and minimum values are set to their optimum
    // to calculate minimal & maximal length
    unsigned int min_value=numeric_limits<unsigned int>::max();
    unsigned int max_value=0;

    // check arguments
    if (argc != 2)
    {
        cout << "wcc file" << endl;
        exit(1);
    }

    // file handle
    ifstream input_file(argv[1]);

    // check if file is opened
    if (!input_file)
    {
        cout << "Unable to open file " << argv[1] << endl;
        exit(2);
    }


    // read each line of the input file
    while (getline(input_file, line))
    {
        // get length
        auto line_length = line.length();

        // check length and adjust min & max values accordingly
        if (line_length < min_value) min_value = line_length;
        if (line_length > max_value) max_value = line_length;
    }

    // close file and display values as: min max
    input_file.close();
    cout << min_value << " " << max_value << endl;

}

