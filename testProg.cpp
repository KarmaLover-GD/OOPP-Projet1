#include <iostream>
#include <fstream>
#include <vector>
#include "markov_model.hpp"
using namespace std;

typedef std::map<std::string, string> trainers;
static bool isNumber(const string &s)
{
    for (char const &ch : s)
    {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}
int main(int argc, char **argv)
{

    string order(argv[1]);
    if (!isNumber(order))
        throw domain_error("first argument should be a number");

    //vector<string> sample;
    Markov_model m;
    string tmp1, tmp2;
    trainers trData;
    trainers trTest;

    int sep_idx = 0;
    for (int i = 2; i < argc; i++)
    {
        string s(argv[i]);
        if (s == "--")
            sep_idx = i;
    }

    if (sep_idx == 0)
        throw domain_error("No separator found");
    // Loading arguments and file contents
    for (int i = 2; i < argc; i++)
    {
        string s(argv[i]);
        if (i < sep_idx)
        {

            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                getline(myfile, tmp2);
                trData[tmp1] = tmp2;
            }
        }
        else if (i > sep_idx)
        {
            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                trTest[s] = tmp1;
            }
        }
    }
    int value = -99999;
    int best = -99999;
    int best_idx = 0;
    string best_name = "None";
    auto it = trData.begin();

    while (it != trData.end())
    {
        Markov_model m;
        markov_model(m, stoi(argv[1]), it->second);
        cout<<"-------Calculating likelihoods with training set "<<it->first<<"------"<<endl;
        
        for (auto it2 = trTest.begin(); it2 != trTest.end(); ++it2)
        {
            try
            {
                cout<<"Training set : "<<it2->first<<endl;
                value = likelihood(m, it2->second);
                if (value > best)
                {
                    best = value;
                    best_name = it2->second;
                }
                cout<<"likelihood : "<<value<< endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
                cout << "Likelihood : -"<<endl;
                value = -9999999;
            }
            
        }
        cout << "the test with the highest likelihood for training set " <<it->first<< " was : " << best_name << " With a likelihood of" << best << endl;
        best = -99999;
        best_name = "None";
        ++it;
    }

    return 0;
}