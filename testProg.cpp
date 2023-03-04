#include <iostream>
#include <fstream>
#include <vector>
#include "markov_model.hpp"
using namespace std;

typedef std::map<std::string, string> trainers;

int main(int argc, char **argv)
{
    vector<string> sample;

    Markov_model m;
    string tmp1, tmp2;
    trainers tr;
    for (int i = 1; i < argc; i++)
    {
        string s(argv[i]);
        if (s.substr(0, 2) == "TD")
        {
            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                getline(myfile, tmp2);

                tr[tmp1] = tmp2;
            }
        }
        else if (s.substr(0, 1) == "-")
        {
            continue;
        }else if(s.substr(0, 1)=="I" ){
            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                sample.push_back(tmp1);
            }
        }
    }

    // markov_model(m, stoi(argv[0]), ):

    cout << "You have entered " << argc
         << " arguments:"
         << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
}