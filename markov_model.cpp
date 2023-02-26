#include <iostream>
#include <error.h>
#include "markov_model.hpp"


void markov_model(Markov_model& m, unsigned int order, const std::string& s){
    //String must be longer than the order itself 
    if(s.length() < order){
        throw;
    }

    for(int i = 0; i< s.length(); i++){
        m.alphabet.insert(s[i]);
    }

    m.order = order;

    int occ = 0;
    for(int i= 0; i+order<s.length(); i++){
        
            std::string tmp = s.substr(i, i+order);
            if(m.model.find(tmp)->second)
                occ = m.model.find(tmp)->second;
            else
               occ = 1;
        
            m.model[tmp] = occ;
    }
    
}


static std::string *generate_substrings()



// static void fill_map(Model& mod,unsigned int order, const std::string& s){



// }

