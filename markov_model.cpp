#include <iostream>
#include <error.h>
#include "markov_model.hpp"

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
            std::cout<<tmp<<std::endl;
        }
        if (m.model.count(tmp) > 0)
        {
            occ = m.model.find(tmp)->second + 1;
        }
        
            m.model[tmp] = occ;
        
    }
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

        double proba = m.model.find(s)->second + 1 / m.model.find(s.substr(0, s.length() / 2))->second + alpha_sz;

        return proba;
    }
