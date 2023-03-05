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
       
        // else if (s.substr(0, 1) == "-")
        // {
        //     continue;
        // }else if(s.substr(0, 1)=="I" ){
            
        // }
    

    // markov_model(m, stoi(argv[0]), ):

    cout << "You have entered " << argc
         << " arguments:"
         << "\n";

    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";

    return 0;
 }