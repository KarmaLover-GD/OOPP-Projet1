#include <iostream>
#include <error.h>
#include "markov_model.hpp"
static void fill_model(Model &m, unsigned int order, const std::string &s)
{
    int occ;
    for (int i = 0; i < s.length(); i++)
    {
        occ = 1;
        std::string tmp = "";
        if (i + order < s.length())
        {
            tmp = s.substr(i, order);
            // std::cout << tmp << std::endl;
        }

        else
        {
            for (int j = 0; j < order; j++)
            {
                tmp = tmp + s[(i + j) % s.length()];
            }
        }
        if (m.count(tmp) > 0)
        {
            occ = m.find(tmp)->second + 1;
        }

        m[tmp] = occ;
    }
}

void markov_model(Markov_model &m, unsigned int order, const std::string &s)
{
    // String must be longer than the order itself
    if (s.length() < order)
    {
        throw;
    }

    for (int i = 0; i < s.length(); i++)
    {
        m.alphabet.insert(s[i]);
    }

    m.order = order;

    fill_model(m.model, order, s);
    fill_model(m.model, order-1, s);
    
}


void display_model(const Markov_model &m)
{

    std::cout << "Order :" << m.order << std::endl;

    std::cout << "Displaying alphabet " << std::endl;

    for (auto it = m.alphabet.begin(); it !=
                                       m.alphabet.end();
         ++it)
        std::cout << ' ' << *it;

    std::cout << "Dispalying model" << std::endl;

    auto it = m.model.begin();
    while (it != m.model.end())
    {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }
}

double laplace(const Markov_model &m, const std::string &s)
{

    //------------ Error Handling ------------------
    
    int alpha_sz = m.alphabet.size();

    std::cout<<"N(sc) + 1 = "<< double(m.model.find(s)->second + 1) <<std::endl;
    std::cout<<"N(s) + A = " <<  double(m.model.find(s.substr(0, s.length()  -1))->second + alpha_sz) << std::endl;

    double proba = (double(m.model.find(s)->second + 1)) / double(m.model.find(s.substr(0, s.length()  -1))->second + alpha_sz);

    return proba;
}
