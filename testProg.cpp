#include <iostream>
#include "markov_model.hpp"
using namespace std;

int main(int argc, char** argv){

    Markov_model m;

    markov_model(m, stoi(argv[0]), )

    cout << "You have entered " << argc
         << " arguments:" << "\n";
  
    for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";
  
    return 0;
}