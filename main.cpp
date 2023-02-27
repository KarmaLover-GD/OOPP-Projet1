#include <iostream>
#include "markov_model.hpp"


int main(){

    Markov_model m;
    std::string str = "voivoivoi unprogramme de stvtest";
    int order = 3;
    
    markov_model(m, order, str);

    display_model(m);

}