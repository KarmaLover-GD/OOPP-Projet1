#include <iostream>
#include <fstream>
#include "markov_model.hpp"
using namespace std;

typedef std::map<std::string, string> trainers;

int main(int argc, char **argv)
{

    Markov_model m;

    for (int i = 1; i < argc; i++)
    {
        string s(argv[i]);
        if (s.substr(0, 2) != "TD")
            break;
        ifstream myfile;
        myfile.open(s);
    }

    // markov_model(m, stoi(argv[0]), ):

    cout << "You have entered " << argc
         << " arguments:"
         << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}