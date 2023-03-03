#include <iostream>
#include<cmath>
#include "markov_model.hpp"


int main(){

    Markov_model m;
    std::string str = "aaaaaaabaaaaa";
    int order = 3;
    
    markov_model(m, order, str);

        std::cout<<likelihood(m, "aababb")<<std::endl;
        //std::cout<<log(laplace(m, "aaaa"))<<std::endl;

    return 0;
}