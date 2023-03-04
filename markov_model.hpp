
#include <iostream>
#include <set>
#include <map>
using namespace std;

typedef std::set<char> Alphabet;
typedef std::map<std::string, unsigned int> Model;

struct Markov_model {
unsigned int order;
Alphabet alphabet;
Model model;
};

struct Matching
{
    Markov_model m;
    string name;
    string closest;
};


void markov_model(Markov_model&, unsigned int, const std::string&);

double laplace(const Markov_model&, const std::string&);

double likelihood(Markov_model&, const std::string&);

void display_model(const Markov_model&);