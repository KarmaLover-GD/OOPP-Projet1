#include <iostream>
#include<cmath>
#include "markov_model.hpp"


int main(){

    Markov_model m;
    std::string str = "abcdefgacaa";
    int order = 3;
    
    markov_model(m, order, str);

        std::cout<<likelihood(m, "abaafadcaaa")<<std::endl;
        //std::cout<<log(laplace(m, "baaa"))<<std::endl;

    return 0;
}