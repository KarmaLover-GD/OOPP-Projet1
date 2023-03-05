#include <iostream>
#include <fstream>
#include <vector>
#include "markov_model.hpp"
using namespace std;

typedef std::map<std::string, string> trainers;
static bool isNumber(const string& s)
{
    for (char const &ch : s) {
        if (std::isdigit(ch) == 0) 
            return false;
    }
    return true;
 }
int main(int argc, char **argv)
 {
    string order(argv[0]);
     if(!isNumber(order))
        throw domain_error("first argument should be a number");
   
    vector<string> sample;
    Markov_model m;
    string tmp1, tmp2;
    trainers tr;
    int sep_idx = 0; 
    for (int i = 1; i < argc; i++)
    {
        string s(argv[i]);
        if(s == "--")
            sep_idx == i;
    }

    if(sep_idx == 0 || sep_idx > argc)
        throw domain_error("No separator found");
    // Loading arguments and file contents 
    for(int i =1; i<argc; i++){
        string s(argv[i]);
        if(i<sep_idx){
             
            
            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                getline(myfile, tmp2);
                tr[tmp1] = tmp2;
            }
        }else if( i> sep_idx){
            ifstream myfile;
            myfile.open(s);
            if (myfile.is_open())
            {
                getline(myfile, tmp1);
                sample.push_back(tmp1);
            }
        }
    }
    int value = -99999;
    int best = -99999;
    int best_idx = 0;
    auto it = tr.begin();

    while(it != tr.end()){
        Markov_model m;
        markov_model(m, stoi(argv[0]), it->second);
        for(int i = 0; i<sample.size(); i++){
            try
            {
                value = likelihood(m, sample[i]);
                if(value>best){
                    best = value;
                    best_idx = i;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                cout<<"-";
                value = -9999999;
            }
            cout<<value <<"is the likelihood for test"<<i <<"under trained set "<<it->first<<endl;
        }
        cout<<"the was with the highest likelihood was the number :"<<best_idx<< " Witrh a likelihood of"<<best<<endl;
        best = -99999;
        best_idx = 0;

    }
    

    // markov_model(m, stoi(argv[0]), ):

    cout << "You have entered " << argc
         << " arguments:"
         << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
 }