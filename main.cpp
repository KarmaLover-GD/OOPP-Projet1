#include <iostream>
#include "markov_model.hpp"


int main(){

    Markov_model m;
    std::string str = "aaaaaaaaaaaaa";
    int order = 3;
    
    markov_model(m, order, str);

    std::cout << laplace(m, "aaaa");

    return 0;
}